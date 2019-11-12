/*�ļ�����PrototypePattern.h
���ߣ�Yzy
˵����ԭ��ģʽ(ʵ����һ�����󣬿����ɴ˻�ȡ��������)
�ϴ��޸�ʱ�䣺2019/11/12 
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