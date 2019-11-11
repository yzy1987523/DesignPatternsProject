/*文件名：StatePattern.h
作者：YZY
说明：状态模式（一个对象有多个状态，通过引用状态参数就可以切换状态）
上次修改时间：2019/11/11 
*/
#pragma once
#include <iostream>  
namespace StatePattern {
	using namespace std;


	/*声明Context类*/
	class Context;

	/*抽象状态类:定义一个接口以封装与Context的一个特定状态相关的行为*/
	class State
	{
	public:
		virtual void Handle(Context *pContext) = 0;
	};

	/*Context类，维护一个ConcreteState子类的实例，这个实例定义当前的状态*/
	class Context
	{
	public:
		Context(State *pState) : m_pState(pState) {}

		void Request()
		{
			if (m_pState)
			{
				m_pState->Handle(this);
			}
		}

		void ChangeState(State *pState)
		{
			m_pState = pState;
		}

	private:
		State *m_pState; //这里的State指针是实现特定状态相关的关键
	};

	class ConcreteStateA : public State
	{
	public:
		virtual void Handle(Context *pContext)
		{
			cout << "I am concrete stateA." << endl;
		}
	};

	class ConcreteStateB : public State
	{
	public:
		virtual void Handle(Context *pContext)
		{
			cout << "I am concrete stateB." << endl;
		}
	};


	void StatePatternTest()
	{
		State *pStateA = new ConcreteStateA();//初始化两个具体状态类对象
		State *pStateB = new ConcreteStateB();
		Context *pContext = new Context(pStateA); //将具体状态类对象交由Context类管理

		pContext->Request();//Context类根据对象状态，调用该对象的特定函数Request
		pContext->ChangeState(pStateB); //改变对象状态
		pContext->Request();
	}
}