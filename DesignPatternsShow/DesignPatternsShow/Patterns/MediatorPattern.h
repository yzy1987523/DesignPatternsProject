/*文件名：MediatorPattern.h
作者：Yzy
说明：中介者模式（消息传递到一处，然后分配给指定对象）
上次修改时间：2019/11/11
*/
#pragma once
#include <iostream>  
#include <string>
namespace MediatorPattern {
	using namespace std;

	//当两个类相互调用时，先声明其中一个类
	class Mediator;

	/*定义抽象人类*/
	class Person
	{
	public:
		virtual void SetMediator(Mediator *mediator) {}
		virtual void SendMessage(string &message) {}//&作为取值符，使用地址作为传递的参数，可以节省传递消耗；当然也可以不加&，不过要保证传递过程中的统一
		virtual void GetMessage(string &message) {}
	protected:
		Mediator *p_mediator; //中介    
	};

	/*定义抽象中介类*/
	class Mediator
	{
	public:
		virtual void Send(string &message, Person *person) {}
		virtual void SetRenter(Person *renter) {}
		virtual void SetLandlord(Person *landlord) {}

	};

	/*定义租客类*/
	class Renter :public Person
	{
	public:
		void SetMediator(Mediator *mediator) { p_mediator = mediator; }
		void SendMessage(string &message) { p_mediator->Send(message, this); }
		void GetMessage(string &message) { cout << "租房者收到房东发来的消息：" << message; }
	};

	/*定义房东类*/
	class Landlord :public Person
	{
	public:
		void SetMediator(Mediator *mediator) { p_mediator = mediator; }
		void SendMessage(string &message) { p_mediator->Send(message, this); }
		void GetMessage(string &message) { cout << "房东收到租客发来的消息：" << message; }
	};

	/*定义具体中介类*/
	class HouseMediator :public Mediator
	{
	public:
		HouseMediator() :p_renter(NULL), p_landlord(NULL) {}
		void SetRenter(Person *renter) { p_renter = renter; }
		void SetLandlord(Person *landlord) { p_landlord = landlord; }
		void Send(string &message, Person *person)
		{//接收消息的对象为该对象的对应对象
			if (person == p_renter)
				p_landlord->GetMessage(message);
			else
				p_renter->GetMessage(message);
		}
	private:
		Person *p_renter;
		Person *p_landlord;
	};
	void  MediatorPatternTest()
	{
		Mediator *mediator = new HouseMediator();
		Person *person1 = new Renter();
		Person *person2 = new Landlord();
		mediator->SetRenter(person1);
		mediator->SetLandlord(person2);
		person1->SetMediator(mediator);
		person2->SetMediator(mediator);
		string str1("我想在深圳北站附近租套房子，一室一厅\n");
		string str2("我有套深圳北站附近的房子出租，一室一厅\n");
		person1->SendMessage(str1);
		person2->SendMessage(str2);

		
	}
}