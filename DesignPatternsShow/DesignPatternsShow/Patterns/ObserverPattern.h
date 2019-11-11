/*�ļ�����ObserverPattern.h
���ߣ�YZY
˵�����۲���ģʽ(�������¼�)
�ϴ��޸�ʱ�䣺2019/11/11 
*/
#pragma once
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
namespace ObserverPattern {
	using namespace std;
	class Observer;

	//���۲��߽ӿ�
	class Observable
	{
	public:
		Observable() {}
		virtual ~Observable() {}
		virtual void addObserver(string &description, Observer* p) = 0;
		virtual void delObserver(string &description) = 0;
		virtual void notifyObserver() = 0;
	};

	//�۲��߽ӿ�
	class Observer
	{
	public:
		Observer() {}
		virtual ~Observer() {}
		virtual void regist() = 0;
		virtual void unregist() = 0;
		virtual void update() = 0;
	};

	//���۲���A
	class A : public Observable
	{
	public:
		A() {};
		~A() {};
		void addObserver(string &description, Observer* p)
		{
			m_mapObserver.insert(pair<string, Observer*>(description, p));//���룻pair�ǽṹ�壬һ����Ϊmap��Ԫ��
		}
		void delObserver(string &description)
		{
			m_mapObserver.erase(description);//����
		}
		void notifyObserver()
		{
			//for_each(m_mapObserver.begin(),
			//	m_mapObserver.end(),
			//	[](const pair<string, Observer*> temp) //Ϊ��Ҫ��[]��const��
			//{ temp.second->update(); });
			for_each(m_mapObserver.begin(), 
				m_mapObserver.end(), 
				[](pair<string, Observer*> temp)->
				void {temp.second->update(); });
		}
	private:
		map<string, Observer*> m_mapObserver;
	};

	//�۲���B
	class B : public Observer
	{
	public:
		B(string &description, Observable* p) : m_description(description), m_pObservable(p) {}
		~B() {};
		//ע���ΪA�Ĺ۲���
		void regist()
		{
			m_pObservable->addObserver(m_description, this);
		}
		//�Ƴ���A�Ĺ۲�
		void unregist()
		{
			m_pObservable->delObserver(m_description);
		}
		void update()
		{
			cout << "I am " << m_description << ", get response from A." << endl;
		}
	private:
		Observable* m_pObservable;
		string &m_description;
	};

	//�۲���C
	class C : public Observer
	{
	public:
		C(string &description, Observable* p) : m_description(description), m_pObservable(p) {}
		~C() {};
		//ע���ΪA�Ĺ۲���
		void regist()
		{
			m_pObservable->addObserver(m_description, this);
		}
		//�Ƴ���A�Ĺ۲�
		void unregist()
		{
			m_pObservable->delObserver(m_description);
		}
		void update()
		{
			cout << "I am " << m_description << ", get response from A." << endl;
		}
	private:
		Observable* m_pObservable;
		string&m_description;
	};

	void ObserverPatternTest()
	{
		//����һ�����۲���
		A* pA = new A;

		string str1("Observer B");
		//���������۲���,��ע���ΪA�Ĺ۲���
		B* pB = new B(str1, pA);
		pB->regist();
		string str2("Observer B");//string str2("Observer C");
		//cout << &str1 << ":" << &str2 << endl;����ĵ�ַ��һ��
		C* pC = new C(str2, pA);//��������str1��str2����һ��������Ϊmap��keyֵһ�������ֻע����һ��
		
		pC->regist();

		//����A::notifyObserver֪ͨA�����й۲��ߣ���ʱ��B��C�����յ���Ӧ��
		pA->notifyObserver();

		//B�����Ƴ���A�Ĺ۲�
		pB->unregist();
		cout << "------------------------------------------------" << endl;

		//��ʱ���ٵ���A::notifyObserver��ֻ��C���յ���Ӧ��
		pA->notifyObserver();
	}
}