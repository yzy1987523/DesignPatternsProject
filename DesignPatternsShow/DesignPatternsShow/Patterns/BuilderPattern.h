/*文件名：BuilderPattern.h
作者：YZY
说明：建造者模式(相较于工厂模式，其更倾向于组装复杂产品)
上次修改时间：2019/11/6 
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
		fprintf(stderr, "partA = %d  partB = %d  partC = %d\n", partA, partB, partC);//stderr与stdout都是向dos窗口输出，但后者会输出到磁盘文件
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
		fprintf(stderr, "创建一个产品空壳\n");
		curProduct = new Product();
	}


	void Builder::buildPartA(int param)
	{
		fprintf(stderr, "正在构建产品的A部分\n");
		curProduct->setPartA(param);
	}


	void Builder::buildPartB(int param)
	{
		fprintf(stderr, "正在构建产品的B部分\n");
		curProduct->setPartB(param);
	}


	void Builder::buildPartC(int param)
	{
		fprintf(stderr, "正在构建产品的C部分\n");
		curProduct->setPartC(param);
	}


	Product* Builder::getProduct()
	{		
		//我的理解就是产品交出去之后,怎么释放怎么弄就不归建造者管了
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