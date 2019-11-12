/*文件名：PrototypePattern.h
作者：Yzy
说明：原型模式(实例化一个对象，可以由此获取拷贝对象)
上次修改时间：2019/11/12 
*/
#pragma once
namespace PrototypePattern {
#include <stdio.h>
	class Prototype {

	public:
		virtual Prototype* clone() = 0;
	};


	class ConcretePrototype :public Prototype {

	public:
		ConcretePrototype();
		~ConcretePrototype();
		ConcretePrototype(const ConcretePrototype&);
		Prototype* clone();

	//private:
	};


	ConcretePrototype::ConcretePrototype()
	{

	}


	ConcretePrototype::~ConcretePrototype()
	{

	}

	ConcretePrototype::ConcretePrototype(const ConcretePrototype& c)
	{
		fprintf(stderr, "ConcretePrototype copy construct!\n");
	}


	Prototype* ConcretePrototype::clone()
	{
		return new ConcretePrototype(*this);
	}


//////////////////////////////////////////////////////////////////////////


	void PrototypePatternTest()
	{
		Prototype* p = new ConcretePrototype();

		Prototype* a = p->clone();		
	}
}