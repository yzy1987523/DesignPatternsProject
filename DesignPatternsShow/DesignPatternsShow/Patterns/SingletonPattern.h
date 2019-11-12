/*�ļ�����SingletonPattern.h
���ߣ�YZY
˵��������ģʽ
�ϴ��޸�ʱ�䣺2019/11/12
*/
#pragma once
namespace SingletonPattern {

	using namespace std;
	class Singleton {
	public:
		Singleton() {};
		Singleton(const Singleton&) {};//��ֹ����
		static Singleton* GetInstance();
		void Show();
	private:
		Singleton& operator = (const Singleton&) {};//��ֹ��ֵ
		static Singleton* instance;

	};
	//����ģʽ
	Singleton* Singleton::instance = NULL;
	Singleton* Singleton::GetInstance() {
		if (instance == nullptr) {
			instance = new Singleton();
		}
		return instance;
	}
	//����ģʽ
	/*Singleton* Singleton::instance = new Singleton();
	Singleton* Singleton::GetInstance() {
		return instance;
	}*/

	//�̰߳�ȫ��ģ��ģʽ
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

	//ģ����static����
	template<class T>
	T*  CSingleton<T>::_instance = NULL;

	template<class T>
	CThreadLockCs CSingleton<T>::lcs;

	//ģ���෽��ʵ��
	template<class T>
	CSingleton<T>::CSingleton(void)
	{
	}

	template<class T>
	T*  CSingleton<T>::Instance(void)
	{
		//double-check
		//�ӳٴ�����ֻ�е��÷�����Instance�Żᴴ����ʵ��
		if (_instance == NULL)
		{
			//�������������CriticalSectionʵ��
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
		cout<<"ʵ����"<<endl;
	}

	void SingletonPatternTest() {
		Singleton *obj = Singleton::GetInstance();
		obj->Show();

		typedef CSingleton<Singleton> S;
		S::Instance()->Show();		
		S::Close();
	}

}