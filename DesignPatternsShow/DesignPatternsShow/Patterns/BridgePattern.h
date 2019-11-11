/*�ļ�����BridgePattern.h
���ߣ�YZY
˵�����Ž�ģʽ
�ϴ��޸�ʱ�䣺2019/11/6 
*/
#pragma once
namespace BridgePattern {

#pragma region �����ţ��Ű�����Ҫ�ŽӵĶ���
	//������࣬������ʵ�ֵĽӿ�
	class AbstractionImplement
	{
	public:
		virtual void Operation() = 0;//��������ӿ�
		virtual ~AbstractionImplement();
	protected:
		AbstractionImplement();
	};

	// �̳���AbstractionImplement,��AbstractionImplement�Ĳ�ͬʵ��֮һ
	class ConcreteAbstractionImplementA :public AbstractionImplement
	{
	public:
		ConcreteAbstractionImplementA();
		~ConcreteAbstractionImplementA();
		void Operation();//ʵ�ֲ���
	protected:
	};

	// �̳���AbstractionImplement,��AbstractionImplement�Ĳ�ͬʵ��֮һ
	class ConcreteAbstractionImplementB :public AbstractionImplement
	{
	public:
		ConcreteAbstractionImplementB();
		~ConcreteAbstractionImplementB();
		void Operation();//ʵ�ֲ���
	protected:
	};
#pragma endregion
	//////////////////////////////////////////////////////////////////////////
#pragma region ʵ����
	AbstractionImplement::AbstractionImplement()
	{}

	AbstractionImplement::~AbstractionImplement()
	{}

	ConcreteAbstractionImplementA::ConcreteAbstractionImplementA()
	{}

	ConcreteAbstractionImplementA::~ConcreteAbstractionImplementA()
	{}

	void ConcreteAbstractionImplementA::Operation()
	{
		cout << "�Ž���A��β" << endl;
	}

	ConcreteAbstractionImplementB::ConcreteAbstractionImplementB()
	{}

	ConcreteAbstractionImplementB::~ConcreteAbstractionImplementB()
	{}

	void ConcreteAbstractionImplementB::Operation()
	{
		cout << "�Ž���B��β" << endl;
	}
#pragma endregion
	//////////////////////////////////////////////////////////////////////////	
#pragma region ����Ҫ��ͷ 
	class Abstraction
	{
	public:
		virtual void Operation() = 0;//����ӿڣ���ʾ������֧�ֵĲ���
		virtual ~Abstraction();
	protected:
		Abstraction();
	};

	class RefinedAbstractionA :public Abstraction
	{
	public:
		RefinedAbstractionA(AbstractionImplement* imp);//���캯��
		virtual ~RefinedAbstractionA();//��������
		virtual void Operation();//ʵ�ֽӿ�
	private:
		AbstractionImplement* _imp;//˽�г�Ա
	};

	class RefinedAbstractionB :public Abstraction
	{
	public:
		RefinedAbstractionB(AbstractionImplement* imp);//���캯��
		virtual ~RefinedAbstractionB();//��������
		virtual void Operation();//ʵ�ֽӿ�
	private:
		AbstractionImplement* _imp;//˽�г�Ա
	};
#pragma endregion
	//////////////////////////////////////////////////////////////////////////
#pragma region ʵ����ͷ
#include <iostream>

	using namespace std;

	Abstraction::Abstraction()
	{}

	Abstraction::~Abstraction()
	{}

	RefinedAbstractionA::RefinedAbstractionA(AbstractionImplement* imp)
	{
		this->_imp = imp;
	}

	RefinedAbstractionA::~RefinedAbstractionA()
	{
		delete this->_imp;
		this->_imp = NULL;
	}

	void RefinedAbstractionA::Operation()
	{
		cout << "A��ͷ" << endl;
		this->_imp->Operation();
	}

	RefinedAbstractionB::RefinedAbstractionB(AbstractionImplement* imp)
	{
		this->_imp = imp;
	}

	RefinedAbstractionB::~RefinedAbstractionB()
	{
		delete this->_imp;
		this->_imp = NULL;
	}

	void RefinedAbstractionB::Operation()
	{
		cout << "B��ͷ" << endl;
		this->_imp->Operation();
	}
#pragma endregion
	//////////////////////////////////////////////////////////////////////////

	void BridgePatternTest()
	{
		/* �����󲿷�������ʵ�ֲ��ַ��룬ʹ�����ǿ��Զ����ر仯

		1������Abstraction��ʵ��AbstractionImplement����;

		2�����󲿷�Abstraction���Ա仯����new RefinedAbstractionA(imp)��new RefinedAbstractionB(imp2);

		3��ʵ�ֲ���AbstractionImplementҲ���Ա仯����new ConcreteAbstractionImplementA()��new ConcreteAbstractionImplementB();

		*/

		AbstractionImplement* imp = new ConcreteAbstractionImplementA();        //ʵ�ֲ���ConcreteAbstractionImplementA
		Abstraction* abs = new RefinedAbstractionA(imp);                        //���󲿷�RefinedAbstractionA
		abs->Operation();

		cout << "-----------------------------------------" << endl;

		AbstractionImplement* imp1 = new ConcreteAbstractionImplementB();        //ʵ�ֲ���ConcreteAbstractionImplementB
		Abstraction* abs1 = new RefinedAbstractionA(imp1);                        //���󲿷�RefinedAbstractionA
		abs1->Operation();

		cout << "-----------------------------------------" << endl;

		AbstractionImplement* imp2 = new ConcreteAbstractionImplementA();        //ʵ�ֲ���ConcreteAbstractionImplementA
		Abstraction* abs2 = new RefinedAbstractionB(imp2);                        //���󲿷�RefinedAbstractionB
		abs2->Operation();

		cout << "-----------------------------------------" << endl;

		AbstractionImplement* imp3 = new ConcreteAbstractionImplementB();        //ʵ�ֲ���ConcreteAbstractionImplementB
		Abstraction* abs3 = new RefinedAbstractionB(imp3);                        //���󲿷�RefinedAbstractionB
		abs3->Operation();

		cout << endl;
	}
}