/*文件名：SimpleFactoryPattern.h
作者：YZY
说明：简单工厂模式
上次修改时间：2019/11/5 
*/
#pragma once
#include <iostream>
using namespace std;
namespace SimpleFactoryPattern {
	enum ProductTypeTag
	{
		TypeA,
		TypeB,
		TypeC
	};

	class Product
	{
	public:
		virtual void Show() = 0;
	};

	class ProductA : public Product
	{
	public:
		void Show()
		{
			cout << "I'm ProductA" << endl;
		}
	};

	class ProductB : public Product
	{
	public:
		void Show()
		{
			cout << "I'm ProductB" << endl;
		}
	};

	class ProductC : public Product
	{
	public:
		void Show()
		{
			cout << "I'm ProductC" << endl;
		}
	};

	class Factory
	{
	public:
		Product* CreateProduct(ProductTypeTag type)
		{
			switch (type)
			{
			case TypeA:
				return new ProductA();

			case TypeB:
				return new ProductB();

			case TypeC:
				return new ProductC();

			default:
				return NULL;
			}
		}
	};
	void SimpleFactoryPatternTest() {
		Factory *ProductFactory = new Factory();
		Product *productObjA = ProductFactory->CreateProduct(TypeA);
		if (productObjA != NULL)
			productObjA->Show();

		Product *productObjB = ProductFactory->CreateProduct(TypeB);
		if (productObjB != NULL)
			productObjB->Show();

		Product *productObjC = ProductFactory->CreateProduct(TypeC);
		if (productObjC != NULL)
			productObjC->Show();

		delete ProductFactory;//释放指针指向的内容
		ProductFactory = NULL;//将指针指向NULL

		delete productObjA;
		productObjA = NULL;

		delete productObjB;
		productObjB = NULL;

		delete productObjC;
		productObjC = NULL;
	}
}