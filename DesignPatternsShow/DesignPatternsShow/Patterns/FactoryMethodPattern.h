/*�ļ�����FactoryMethodPattern.h
���ߣ�YZY
˵������������ģʽ
�ϴ��޸�ʱ�䣺2019/11/5 16��03��03 *
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
	//������򵥹���ģʽһ��������ľ�������ÿ����Ʒ���ж�Ӧ�ľ��幤������Ʒ�빤���ɶ����//	
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