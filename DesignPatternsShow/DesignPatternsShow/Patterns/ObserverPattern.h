/*文件名：ObserverPattern.h
作者：YZY
说明：观察者模式(即监听事件)
上次修改时间：2019/11/11 
*/
#pragma once
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
namespace ObserverPattern {
	using namespace std;
	class Observer;

	//被观察者接口
	class Observable
	{
	public:
		Observable() {}
		virtual ~Observable() {}
		virtual void addObserver(string &description, Observer* p) = 0;
		virtual void delObserver(string &description) = 0;
		virtual void notifyObserver() = 0;
	};

	//观察者接口
	class Observer
	{
	public:
		Observer() {}
		virtual ~Observer() {}
		virtual void regist() = 0;
		virtual void unregist() = 0;
		virtual void update() = 0;
	};

	//被观察者A
	class A : public Observable
	{
	public:
		A() {};
		~A() {};
		void addObserver(string &description, Observer* p)
		{
			m_mapObserver.insert(pair<string, Observer*>(description, p));//插入；pair是结构体，一般作为map的元素
		}
		void delObserver(string &description)
		{
			m_mapObserver.erase(description);//擦除
		}
		void notifyObserver()
		{
			//for_each(m_mapObserver.begin(),
			//	m_mapObserver.end(),
			//	[](const pair<string, Observer*> temp) //为何要加[]和const？
			//{ temp.second->update(); });
			for_each(m_mapObserver.begin(), 
				m_mapObserver.end(), 
				[](pair<string, Observer*> temp)->
				void {temp.second->update(); });
		}
	private:
		map<string, Observer*> m_mapObserver;
	};

	//观察者B
	class B : public Observer
	{
	public:
		B(string &description, Observable* p) : m_description(description), m_pObservable(p) {}
		~B() {};
		//注册成为A的观察者
		void regist()
		{
			m_pObservable->addObserver(m_description, this);
		}
		//移除对A的观察
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

	//观察者C
	class C : public Observer
	{
	public:
		C(string &description, Observable* p) : m_description(description), m_pObservable(p) {}
		~C() {};
		//注册成为A的观察者
		void regist()
		{
			m_pObservable->addObserver(m_description, this);
		}
		//移除对A的观察
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
		//定义一个被观察者
		A* pA = new A;

		string str1("Observer B");
		//定义两个观察者,并注册成为A的观察者
		B* pB = new B(str1, pA);
		pB->regist();
		string str2("Observer B");//string str2("Observer C");
		//cout << &str1 << ":" << &str2 << endl;输出的地址不一样
		C* pC = new C(str2, pA);//如果传入的str1与str2内容一样，会因为map的key值一样而造成只注册上一个
		
		pC->regist();

		//调用A::notifyObserver通知A的所有观察者，这时候B和C都能收到响应。
		pA->notifyObserver();

		//B主动移除对A的观察
		pB->unregist();
		cout << "------------------------------------------------" << endl;

		//这时候再调用A::notifyObserver，只有C能收到响应。
		pA->notifyObserver();
	}
}