/*�ļ�����BuilderPattern.h
���ߣ�YZY
˵����������ģʽ(����ڹ���ģʽ�������������װ���Ӳ�Ʒ)
�ϴ��޸�ʱ�䣺2019/11/6 
*/
#pragma once
namespace BuilderPattern {
#include <stdio.h>
	//////////////////////////////////////////////////////////////////////////
	class Product {
	public:
		Product();
		~Product();

		void setPartA(int param);
		void setPartB(int param);
		void setPartC(int param);

		void show();

	private:
		int partA;
		int partB;
		int partC;

	};


	class AbstractBuilder {
	public:
		AbstractBuilder();
		virtual ~AbstractBuilder();

		virtual void createProduct() = 0;
		virtual void buildPartA(int param) = 0;
		virtual void buildPartB(int param) = 0;
		virtual void buildPartC(int param) = 0;

		virtual Product* getProduct() = 0;
	};


	class Builder : public AbstractBuilder {
	public:
		Builder();
		~Builder();

		void createProduct();
		void buildPartA(int param);
		void buildPartB(int param);
		void buildPartC(int param);

		Product* getProduct();

	private:
		Product* curProduct;

	};
	//////////////////////////////////////////////////////////////////////////
	Product::Product()
	{

	}


	Product::~Product()
	{

	}


	void Product::setPartA(int param)
	{
		partA = param;
	}


	void Product::setPartB(int param)
	{
		partB = param;
	}


	void Product::setPartC(int param)
	{
		partC = param;
	}


	void Product::show()
	{
		fprintf(stderr, "partA = %d  partB = %d  partC = %d\n", partA, partB, partC);//stderr��stdout������dos��������������߻�����������ļ�
	}


	AbstractBuilder::AbstractBuilder()
	{

	}


	AbstractBuilder::~AbstractBuilder()
	{

	}


	Builder::Builder()
		:curProduct(NULL)
	{

	}


	Builder::~Builder()
	{

	}


	void Builder::createProduct()
	{
		fprintf(stderr, "����һ����Ʒ�տ�\n");
		curProduct = new Product();
	}


	void Builder::buildPartA(int param)
	{
		fprintf(stderr, "���ڹ�����Ʒ��A����\n");
		curProduct->setPartA(param);
	}


	void Builder::buildPartB(int param)
	{
		fprintf(stderr, "���ڹ�����Ʒ��B����\n");
		curProduct->setPartB(param);
	}


	void Builder::buildPartC(int param)
	{
		fprintf(stderr, "���ڹ�����Ʒ��C����\n");
		curProduct->setPartC(param);
	}


	Product* Builder::getProduct()
	{		
		//�ҵ������ǲ�Ʒ����ȥ֮��,��ô�ͷ���ôŪ�Ͳ��齨���߹���
		return curProduct;
	}
	//////////////////////////////////////////////////////////////////////////
	class Director
	{
	public:
		Director(AbstractBuilder* builder);
		~Director();

		void construct();

	private:
		AbstractBuilder* curBuilder;
	};
	//////////////////////////////////////////////////////////////////////////
	Director::Director(AbstractBuilder* builder)
	{
		curBuilder = builder;
	}


	Director::~Director()
	{

	}


	void Director::construct()
	{
		if (!curBuilder)
			return;

		curBuilder->createProduct();
		curBuilder->buildPartA(1);
		curBuilder->buildPartB(2);
		curBuilder->buildPartC(3);
	}
	//////////////////////////////////////////////////////////////////////////
	void BuilderPatternTest() {
		AbstractBuilder* builder = new Builder();
		Director* director = new Director(builder);		
		director->construct();

		Product* product = builder->getProduct();
		product->show();
	}
}