/*�ļ�����MediatorPattern.h
���ߣ�Yzy
˵�����н���ģʽ����Ϣ���ݵ�һ����Ȼ������ָ������
�ϴ��޸�ʱ�䣺2019/11/11
*/
#pragma once
#include <iostream>  
#include <string>
namespace MediatorPattern {
	using namespace std;

	//���������໥����ʱ������������һ����
	class Mediator;

	/*�����������*/
	class Person
	{
	public:
		virtual void SetMediator(Mediator *mediator) {}
		virtual void SendMessage(string &message) {}//&��Ϊȡֵ����ʹ�õ�ַ��Ϊ���ݵĲ��������Խ�ʡ�������ģ���ȻҲ���Բ���&������Ҫ��֤���ݹ����е�ͳһ
		virtual void GetMessage(string &message) {}
	protected:
		Mediator *p_mediator; //�н�    
	};

	/*��������н���*/
	class Mediator
	{
	public:
		virtual void Send(string &message, Person *person) {}
		virtual void SetRenter(Person *renter) {}
		virtual void SetLandlord(Person *landlord) {}

	};

	/*���������*/
	class Renter :public Person
	{
	public:
		void SetMediator(Mediator *mediator) { p_mediator = mediator; }
		void SendMessage(string &message) { p_mediator->Send(message, this); }
		void GetMessage(string &message) { cout << "�ⷿ���յ�������������Ϣ��" << message; }
	};

	/*���巿����*/
	class Landlord :public Person
	{
	public:
		void SetMediator(Mediator *mediator) { p_mediator = mediator; }
		void SendMessage(string &message) { p_mediator->Send(message, this); }
		void GetMessage(string &message) { cout << "�����յ���ͷ�������Ϣ��" << message; }
	};

	/*��������н���*/
	class HouseMediator :public Mediator
	{
	public:
		HouseMediator() :p_renter(NULL), p_landlord(NULL) {}
		void SetRenter(Person *renter) { p_renter = renter; }
		void SetLandlord(Person *landlord) { p_landlord = landlord; }
		void Send(string &message, Person *person)
		{//������Ϣ�Ķ���Ϊ�ö���Ķ�Ӧ����
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
		string str1("���������ڱ�վ�������׷��ӣ�һ��һ��\n");
		string str2("���������ڱ�վ�����ķ��ӳ��⣬һ��һ��\n");
		person1->SendMessage(str1);
		person2->SendMessage(str2);

		
	}
}