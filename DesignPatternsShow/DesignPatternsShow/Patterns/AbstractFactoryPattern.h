/*文件名：AbstractFactoryPattern.h
作者：Yzy
说明：抽象工厂模式
上次修改时间：2019/11/5 16:18:33 *
*/
#pragma once

namespace AbstractFactoryPattern {
#include <iostream>
	using namespace std;
	//主产品
	class Product
	{
	public:
		virtual void Show() = 0;
	};
	class ProductA :public Product
	{
	public:
		void Show()
		{
			cout << "I'm ProductA" << endl;
		}
	};
	class ProductB :public Product

	{
	public:
		void Show()
		{
			cout << "I'm ProductB" << endl;
		}
	};
	class ProductC:public Product

	{
	public:
		void Show()
		{
			cout << "I'm ProductC" << endl;
		}
	};
	
	//副产品
	class SideProduct
	{
	public:
		virtual void Show() = 0;
	};
	class SideProductA :public SideProduct
	{
	public:
		void Show()
		{
			cout << "I'm SideProductA" << endl;
		}
	};
	class SideProductB :public SideProduct
	{
	public:
		void Show()
		{
			cout << "I'm SideProductB" << endl;
		}
	};
	class SideProductC :public SideProduct

	{
	public:
		void Show()
		{
			cout << "I'm SideProductC" << endl;
		}
	};
	
	class Factory
	{
	public:
		virtual Product* CreateProduct() = 0;
		virtual SideProduct* CreateSideProduct() = 0;
	};

	class FactoryA :public Factory
	{
	public:
		static Product* CreateProduct()
		{
			cout << "Create ProductA" << endl;
			return new ProductA();
		}
		static SideProduct* CreateSideProduct()
		{
			cout << "Create SideProductA" << endl;
			return new SideProductA();

		}
	};
	class FactoryB :public Factory
	{
	public:
		Product* CreateProduct()
		{
			cout << "Create ProductB" << endl;
			return new ProductB();
		}
		SideProduct* CreateSideProduct()
		{
			cout << "Create SideProductB" << endl;
			return new SideProductB();
		}
	};
	class FactoryC:public Factory
	{
	public:
		Product* CreateProduct()
		{
			cout << "Create ProductC" << endl;
			return new ProductC();
		}
		 SideProduct* CreateSideProduct()
		{
			cout << "Create SideProductC" << endl;
			return new SideProductC();
		}
	};

	void AbstractFactoryPatternTest()
	{	
		Product*p = FactoryA::CreateProduct();//方法要用static修饰才能用这种方式
		SideProduct*sp = FactoryA::CreateSideProduct();
		
		p->Show();
		sp->Show();

		Factory*Fcb=new FactoryB;//也可以用指针的方式,一般用这种方式，因为可以用抽象类声明
		Fcb->CreateProduct()->Show();
		Fcb->CreateSideProduct()->Show();

		FactoryC Fcc;//也可以直接声明一个数据结构	
		Fcc.CreateProduct()->Show();
		Fcc.CreateSideProduct()->Show();

		//=============================//
		//用auto的声明方式，自由度更高//
		//=============================//
		auto*f = new FactoryB;
		f->CreateProduct()->Show();
		//=============================//
		//可以跳过创建工厂，直接创建产品//
		//=============================//
		auto*pro = new ProductA;
		pro->Show();
		(new ProductB)->Show();

		//=============================//
		//auto*f = new FactoryA;//使用new时不能包含用static修饰的方法//
		//=============================//
	}
}