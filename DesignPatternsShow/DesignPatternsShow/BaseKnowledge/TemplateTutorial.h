/*文件名：TemplateTutorial.h 
作者：YZY
说明：模板的学习案例
上次修改时间：2019/11/13 
*/
#pragma once
namespace TemplateTutorial {	
	//using namespace std;
	//////////////////////////////////////////////////////////////////////////
	//函数模板
	template<typename T> void AFun(T t);
	template<class T> void AFun(T*t);
	template<typename T1, typename T2>T1 BFun(T2 t);

	template<typename T> void AFun(T t) {
		cout << t << endl;
		if (is_pointer<T>::value) {//返回0或1，分别表示假和真
			cout << &t << endl;
			//cout << *t << endl;//虽然有短路判断，但是如果传入非指针，还是会报错
		}
	}
	template<typename T> void AFun(T*t) {//class与typename大多数时可以互换，但优先使用typename
		cout << &t << endl;
		cout << t << endl;
		cout << *t << endl;
	}
	template<typename T1, typename T2>T1 BFun<T1>(T2 t) {
		T1 temp=0;
		temp=temp + t;//注意：传入的参数必须能满足操作
		return temp;
	}
	//////////////////////////////////////////////////////////////////////////
	//类模板
	template<typename T>class AC{
	public:
		AC();
		~AC();
		void Push(T t);
		T Pop();
	private:
		T*p_t;
		int m_size;
	};
	template<typename T>AC<T>::AC() {
		m_size = 0;
		p_t = new T[100];
	}
	template<typename T>AC<T>::~AC() {
		delete p_t;
		p_t = nullptr;
	}
	template<typename T>void AC<T>::Push(T t){
		m_size++;
		p_t[m_size - 1] = t;
	}
	template<typename T>T AC<T>::Pop() {
		T t=p_t[m_size - 1];
		m_size--;
		return t;
	}
	void TemplateTutorialTest() {
		//////////////////////////////////////////////////////////////////////////
		//函数模板
		int a = 19190;
		int*b=&a;
		string c="1989";
		char d = '1';		
		AFun(b);
		int e = BFun<int>(a);
		
		//////////////////////////////////////////////////////////////////////////
		//类模板
		AC<int> ac;
		ac.Push(0);
		cout<< ac.Pop()<<endl;
	}
}