/*�ļ�����TemplateTutorial.h 
���ߣ�YZY
˵����ģ���ѧϰ����
�ϴ��޸�ʱ�䣺2019/11/13 
*/
#pragma once
namespace TemplateTutorial {	
	//using namespace std;
	//////////////////////////////////////////////////////////////////////////
	//����ģ��
	template<typename T> void AFun(T t);
	template<class T> void AFun(T*t);
	template<typename T1, typename T2>T1 BFun(T2 t);

	template<typename T> void AFun(T t) {
		cout << t << endl;
		if (is_pointer<T>::value) {//����0��1���ֱ��ʾ�ٺ���
			cout << &t << endl;
			//cout << *t << endl;//��Ȼ�ж�·�жϣ�������������ָ�룬���ǻᱨ��
		}
	}
	template<typename T> void AFun(T*t) {//class��typename�����ʱ���Ի�����������ʹ��typename
		cout << &t << endl;
		cout << t << endl;
		cout << *t << endl;
	}
	template<typename T1, typename T2>T1 BFun<T1>(T2 t) {
		T1 temp=0;
		temp=temp + t;//ע�⣺����Ĳ����������������
		return temp;
	}
	//////////////////////////////////////////////////////////////////////////
	//��ģ��
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
		//����ģ��
		int a = 19190;
		int*b=&a;
		string c="1989";
		char d = '1';		
		AFun(b);
		int e = BFun<int>(a);
		
		//////////////////////////////////////////////////////////////////////////
		//��ģ��
		AC<int> ac;
		ac.Push(0);
		cout<< ac.Pop()<<endl;
	}
}