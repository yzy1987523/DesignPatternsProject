/*�ļ�����AbstractFactoryPattern.h
���ߣ�Yzy
˵�������󹤳�ģʽ
�ϴ��޸�ʱ�䣺2019/11/5 16:18:33 *
*/
#pragma once

namespace AbstractFactoryPattern {
#include <iostream>
	using namespace std;
	//����Ʒ
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
	
	//����Ʒ
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
		Product*p = FactoryA::CreateProduct();//����Ҫ��static���β��������ַ�ʽ
		SideProduct*sp = FactoryA::CreateSideProduct();
		
		p->Show();
		sp->Show();

		Factory*Fcb=new FactoryB;//Ҳ������ָ��ķ�ʽ,һ�������ַ�ʽ����Ϊ�����ó���������
		Fcb->CreateProduct()->Show();
		Fcb->CreateSideProduct()->Show();

		FactoryC Fcc;//Ҳ����ֱ������һ�����ݽṹ	
		Fcc.CreateProduct()->Show();
		Fcc.CreateSideProduct()->Show();

		//=============================//
		//��auto��������ʽ�����ɶȸ���//
		//=============================//
		auto*f = new FactoryB;
		f->CreateProduct()->Show();
		//=============================//
		//������������������ֱ�Ӵ�����Ʒ//
		//=============================//
		auto*pro = new ProductA;
		pro->Show();
		(new ProductB)->Show();

		//=============================//
		//auto*f = new FactoryA;//ʹ��newʱ���ܰ�����static���εķ���//
		//=============================//
	}
}