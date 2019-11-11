/*文件名：AdapterPattern.h
作者：YZY
说明：适配器模式
上次修改时间：2019/11/6 
*/
#pragma once
#include <iostream>
namespace AdapterPattern {
	//////////////////////////////////////////////////////////////////////////
	//目标接口类（抽象类），客户需要的接口，比如视频播放器
	class Target
	{
	public:
		virtual void Request();//定义标准接口,比如播放
	};

	//需要适配的类，比如是avi格式的视频
	class Adaptee
	{
	public:		
		void SpecificRequest();//特定的需求，比如播放avi视频
	private:
		int param;
	};

	//【类模式】，适配器类，通过public继承获得接口继承的效果，通过private继承获得实现继承的效果
	class Adapter0 : public Adaptee, public Target
	{
	public:				
		void Request();//实现Target定义的Request接口（可以不加virtual）
	};

	//【对象模式】，适配器类，继承Target类，采用组合的方式实现Adaptee的复用
	class Adapter1 :public Target
	{
	public:
		Adapter1(Adaptee* adaptee);
		Adapter1();
		~Adapter1();
		
		virtual void Request();//实现Target定义的Request接口
	private:
		Adaptee* _adaptee;
	};
	//////////////////////////////////////////////////////////////////////////

	using namespace std;

	void Target::Request()
	{
		cout << "Target::Request()" << endl;
	}
	
	void Adaptee::SpecificRequest()
	{		
		cout << "Adaptee::SpecificRequest():" << endl;
	}		
	void Adapter0::Request()
	{
		cout << "Adapter0::Request()" << endl;		
		this->SpecificRequest();
		cout << "----------------------------" << endl;
	}

	//对象模式的Adapter
	Adapter1::Adapter1() :_adaptee(new Adaptee)
	{
	}

	Adapter1::Adapter1(Adaptee* _adaptee)
	{
		this->_adaptee = _adaptee;
	}

	Adapter1::~Adapter1()
	{
	}

	void Adapter1::Request()
	{
		cout << "Adapter1::Request()" << endl;
		this->_adaptee->SpecificRequest();
		cout << "----------------------------" << endl;
	}
	//////////////////////////////////////////////////////////////////////////
	void AdapterPatternTest()
	{
		//类模式Adapter0
		Target* pTarget0 = new Adapter0();		
		pTarget0->Request();			

		//对象模式Adapter1,没有初始化，适配类使用的是默认值
		Target* pTarget1 = new Adapter1();
		pTarget1->Request();

		//对象模式Adapter1，当有参数要修改时，一般用这种方式
		Adaptee* ade = new Adaptee();		
		Target* pTarget2 = new Adapter1(ade);//比如传入不同的视频
		pTarget2->Request();
	}
}