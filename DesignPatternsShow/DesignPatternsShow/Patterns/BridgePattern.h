/*文件名：BridgePattern.h
作者：YZY
说明：桥接模式
上次修改时间：2019/11/6 
*/
#pragma once
namespace BridgePattern {

#pragma region 声明桥（桥包含了要桥接的对象）
	//抽象基类，定义了实现的接口
	class AbstractionImplement
	{
	public:
		virtual void Operation() = 0;//定义操作接口
		virtual ~AbstractionImplement();
	protected:
		AbstractionImplement();
	};

	// 继承自AbstractionImplement,是AbstractionImplement的不同实现之一
	class ConcreteAbstractionImplementA :public AbstractionImplement
	{
	public:
		ConcreteAbstractionImplementA();
		~ConcreteAbstractionImplementA();
		void Operation();//实现操作
	protected:
	};

	// 继承自AbstractionImplement,是AbstractionImplement的不同实现之一
	class ConcreteAbstractionImplementB :public AbstractionImplement
	{
	public:
		ConcreteAbstractionImplementB();
		~ConcreteAbstractionImplementB();
		void Operation();//实现操作
	protected:
	};
#pragma endregion
	//////////////////////////////////////////////////////////////////////////
#pragma region 实现桥
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
		cout << "桥接上A桥尾" << endl;
	}

	ConcreteAbstractionImplementB::ConcreteAbstractionImplementB()
	{}

	ConcreteAbstractionImplementB::~ConcreteAbstractionImplementB()
	{}

	void ConcreteAbstractionImplementB::Operation()
	{
		cout << "桥接上B桥尾" << endl;
	}
#pragma endregion
	//////////////////////////////////////////////////////////////////////////	
#pragma region 声明要桥头 
	class Abstraction
	{
	public:
		virtual void Operation() = 0;//定义接口，表示该类所支持的操作
		virtual ~Abstraction();
	protected:
		Abstraction();
	};

	class RefinedAbstractionA :public Abstraction
	{
	public:
		RefinedAbstractionA(AbstractionImplement* imp);//构造函数
		virtual ~RefinedAbstractionA();//析构函数
		virtual void Operation();//实现接口
	private:
		AbstractionImplement* _imp;//私有成员
	};

	class RefinedAbstractionB :public Abstraction
	{
	public:
		RefinedAbstractionB(AbstractionImplement* imp);//构造函数
		virtual ~RefinedAbstractionB();//析构函数
		virtual void Operation();//实现接口
	private:
		AbstractionImplement* _imp;//私有成员
	};
#pragma endregion
	//////////////////////////////////////////////////////////////////////////
#pragma region 实现桥头
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
		cout << "A桥头" << endl;
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
		cout << "B桥头" << endl;
		this->_imp->Operation();
	}
#pragma endregion
	//////////////////////////////////////////////////////////////////////////

	void BridgePatternTest()
	{
		/* 将抽象部分与它的实现部分分离，使得它们可以独立地变化

		1、抽象Abstraction与实现AbstractionImplement分离;

		2、抽象部分Abstraction可以变化，如new RefinedAbstractionA(imp)、new RefinedAbstractionB(imp2);

		3、实现部分AbstractionImplement也可以变化，如new ConcreteAbstractionImplementA()、new ConcreteAbstractionImplementB();

		*/

		AbstractionImplement* imp = new ConcreteAbstractionImplementA();        //实现部分ConcreteAbstractionImplementA
		Abstraction* abs = new RefinedAbstractionA(imp);                        //抽象部分RefinedAbstractionA
		abs->Operation();

		cout << "-----------------------------------------" << endl;

		AbstractionImplement* imp1 = new ConcreteAbstractionImplementB();        //实现部分ConcreteAbstractionImplementB
		Abstraction* abs1 = new RefinedAbstractionA(imp1);                        //抽象部分RefinedAbstractionA
		abs1->Operation();

		cout << "-----------------------------------------" << endl;

		AbstractionImplement* imp2 = new ConcreteAbstractionImplementA();        //实现部分ConcreteAbstractionImplementA
		Abstraction* abs2 = new RefinedAbstractionB(imp2);                        //抽象部分RefinedAbstractionB
		abs2->Operation();

		cout << "-----------------------------------------" << endl;

		AbstractionImplement* imp3 = new ConcreteAbstractionImplementB();        //实现部分ConcreteAbstractionImplementB
		Abstraction* abs3 = new RefinedAbstractionB(imp3);                        //抽象部分RefinedAbstractionB
		abs3->Operation();

		cout << endl;
	}
}