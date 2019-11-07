/*�ļ�����FlyweightPattern.h
���ߣ�YZY
˵������Ԫģʽ����ʵ���Ǽ򻯰����أ�
�ϴ��޸�ʱ�䣺2019/11/7 22:50:40 *
*/
#pragma once
namespace FlyweightPattern {
//#include <iostream>
//#include <vector>
//	using namespace std;
//	class BaseObj {
//	public:
//		virtual void fun() = 0;
//	};
//	class Obj :public BaseObj {
//	public:
//		void fun();
//	};
//	void Obj::fun() {
//		cout << "ʵ������һ������" << endl;
//	}
//	///
//
//	//using namespace std;
//	class Pool {
//	public:
//		Pool();
//		~Pool();
//		BaseObj*GetObj();
//	private:
//		vector<BaseObj> objlist;
//	};
//	///
//	Pool::Pool() {
//		Obj temp;
//		objlist.push_back(temp);
//	}
//	Pool::~Pool() {
//		BaseObj*temp = &(objlist.at(0));
//		delete temp;
//		temp = nullptr;
//	}
//	BaseObj*Pool::GetObj() {
//		BaseObj*temp = &(objlist.at(0));
//		return temp;
//	}
//	///
//	void FlyweightPatternTest() {
//		Pool* pool = new Pool();
//		BaseObj*temp = pool->GetObj();
//		temp->fun();
//	}

	class FlyWeight
	{
	public:
		FlyWeight() {};
		virtual ~FlyWeight() {};

		virtual void operation() = 0;

	};


	class ConcreteFlyWeight : public FlyWeight
	{
	public:
		ConcreteFlyWeight() {};
		~ConcreteFlyWeight() {};

		void operation();

	};
	void ConcreteFlyWeight::operation()
	{
		printf("I'm ConcreteFlyWeight!\n");
	}
#include <vector>

	using namespace std;

	class FlyWeightFactory
	{
	public:
		FlyWeightFactory();
		~FlyWeightFactory();

		FlyWeight* GetFlyWeight(int key);

	private:
		vector<FlyWeight*> m_flyWeights;//�ܶ�ʱ��Ϊ������Ч�ʣ�ʹ��hash��֮��Ľṹ������򵥵�ʹ��vector
	};
	FlyWeightFactory::FlyWeightFactory()
	{
		FlyWeight* tmp = new ConcreteFlyWeight();
		m_flyWeights.push_back(tmp);
	}




	FlyWeightFactory::~FlyWeightFactory()
	{
		FlyWeight* tmp = m_flyWeights.at(0);
		delete tmp;
		tmp = NULL;
	}




	FlyWeight* FlyWeightFactory::GetFlyWeight(int key)
	{
		//�򵥵��ʾ
		return m_flyWeights.at(key);
	}
	void FlyweightPatternTest()
	{
		FlyWeightFactory* factory = new FlyWeightFactory();

		FlyWeight* flyWeight = factory->GetFlyWeight(0);
		flyWeight->operation();
	}
}