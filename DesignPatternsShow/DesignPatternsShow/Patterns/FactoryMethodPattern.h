/*文件名：FactoryMethodPattern.h
作者：YZY
说明：工厂方法模式
上次修改时间：2019/11/5 16：03：03 *
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace FactoryMethodPattern {
	class Product
	{
	public:
		//double numberA, numberB;
		virtual void  Show() = 0;
		/*{
			return 0;
		}*/
	};

	class ProductA :public Product
	{
		void Show()
		{
			cout << "I'm ProductA" << endl;
		}
	};


	class ProductB :public Product
	{
		void Show()
		{
			cout << "I'm ProductB" << endl;
		}
	};

	class ProductC :public Product
	{
		void Show()
		{
			cout << "I'm ProductC" << endl;
		}
	};
	//=======================================================================================//
	//以上与简单工厂模式一样，下面的就是区别：每个产品都有对应的具体工厂，产品与工厂成对添加//	
	//=======================================================================================//
	class Factory
	{
	public:
		virtual Product *CreateProduct() = 0;
	};

	class ProductAFactory :public Factory
	{
	public:
		static Product *CreateProduct()
		{
			return new ProductA();
		}
	};


	class ProductBFactory :public Factory
	{
	public:
		static Product *CreateProduct()
		{
			return new ProductB();
		}
	};

	class ProductCFactory :public Factory
	{
	public:
		static Product *CreateProduct()
		{
			return new ProductC();
		}
	};
	

	void FactoryMethodPatternTest()
	{
		Product *pro = ProductAFactory::CreateProduct();
		pro->Show();
		pro = ProductBFactory::CreateProduct();
		pro->Show();
		pro = ProductCFactory::CreateProduct();
		pro->Show();
	}
}