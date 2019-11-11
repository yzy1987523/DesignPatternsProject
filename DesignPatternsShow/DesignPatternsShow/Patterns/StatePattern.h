/*�ļ�����StatePattern.h
���ߣ�YZY
˵����״̬ģʽ��һ�������ж��״̬��ͨ������״̬�����Ϳ����л�״̬��
�ϴ��޸�ʱ�䣺2019/11/11 
*/
#pragma once
#include <iostream>  
namespace StatePattern {
	using namespace std;


	/*����Context��*/
	class Context;

	/*����״̬��:����һ���ӿ��Է�װ��Context��һ���ض�״̬��ص���Ϊ*/
	class State
	{
	public:
		virtual void Handle(Context *pContext) = 0;
	};

	/*Context�࣬ά��һ��ConcreteState�����ʵ�������ʵ�����嵱ǰ��״̬*/
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
		State *m_pState; //�����Stateָ����ʵ���ض�״̬��صĹؼ�
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
		State *pStateA = new ConcreteStateA();//��ʼ����������״̬�����
		State *pStateB = new ConcreteStateB();
		Context *pContext = new Context(pStateA); //������״̬�������Context�����

		pContext->Request();//Context����ݶ���״̬�����øö�����ض�����Request
		pContext->ChangeState(pStateB); //�ı����״̬
		pContext->Request();
	}
}