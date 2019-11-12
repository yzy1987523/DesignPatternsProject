/*文件名：SingletonPattern.h
作者：YZY
说明：单例模式
上次修改时间：2019/11/12
*/
#pragma once
namespace SingletonPattern {

	using namespace std;
	class Singleton {
	public:
		Singleton() {};
		Singleton(const Singleton&) {};//禁止拷贝
		static Singleton* GetInstance();
		void Show();
	private:
		Singleton& operator = (const Singleton&) {};//禁止赋值
		static Singleton* instance;

	};
	//懒汉模式
	Singleton* Singleton::instance = NULL;
	Singleton* Singleton::GetInstance() {
		if (instance == nullptr) {
			instance = new Singleton();
		}
		return instance;
	}
	//饿汉模式
	/*Singleton* Singleton::instance = new Singleton();
	Singleton* Singleton::GetInstance() {
		return instance;
	}*/

	//线程安全的模板模式
	class CThreadLockCs
	{
	public:
		CThreadLockCs() { InitializeCriticalSection(&m_cs); }
		~CThreadLockCs() { DeleteCriticalSection(&m_cs); }
		void lock() { EnterCriticalSection(&m_cs); }
		void unlock() { LeaveCriticalSection(&m_cs); }
	private:
		CRITICAL_SECTION m_cs;
	};
	template<class T>
	class CSingleton
	{
	private:
		static T* _instance;
		CSingleton(void);
		static CThreadLockCs lcs;
	public:
		static T* Instance(void);
		static void Close(void);
	};

	//模板类static变量
	template<class T>
	T*  CSingleton<T>::_instance = NULL;

	template<class T>
	CThreadLockCs CSingleton<T>::lcs;

	//模板类方法实现
	template<class T>
	CSingleton<T>::CSingleton(void)
	{
	}

	template<class T>
	T*  CSingleton<T>::Instance(void)
	{
		//double-check
		//延迟创建，只有调用方访问Instance才会创建类实例
		if (_instance == NULL)
		{
			//互斥访问锁，用CriticalSection实现
			lcs.lock();
			if (_instance == NULL)
			{
				_instance = new T;
			}
			lcs.unlock();
		}
		return _instance;
	}

	template<class T>
	void CSingleton<T>::Close(void)
	{
		if (_instance)
		{
			delete _instance;
		}
	}


	void Singleton::Show() {
		cout<<"实例化"<<endl;
	}

	void SingletonPatternTest() {
		Singleton *obj = Singleton::GetInstance();
		obj->Show();

		typedef CSingleton<Singleton> S;
		S::Instance()->Show();		
		S::Close();
	}

}