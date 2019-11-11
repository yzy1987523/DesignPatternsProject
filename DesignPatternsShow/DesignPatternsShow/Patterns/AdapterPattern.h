/*�ļ�����AdapterPattern.h
���ߣ�YZY
˵����������ģʽ
�ϴ��޸�ʱ�䣺2019/11/6 
*/
#pragma once
#include <iostream>
namespace AdapterPattern {
	//////////////////////////////////////////////////////////////////////////
	//Ŀ��ӿ��ࣨ�����ࣩ���ͻ���Ҫ�Ľӿڣ�������Ƶ������
	class Target
	{
	public:
		virtual void Request();//�����׼�ӿ�,���粥��
	};

	//��Ҫ������࣬������avi��ʽ����Ƶ
	class Adaptee
	{
	public:		
		void SpecificRequest();//�ض������󣬱��粥��avi��Ƶ
	private:
		int param;
	};

	//����ģʽ�����������࣬ͨ��public�̳л�ýӿڼ̳е�Ч����ͨ��private�̳л��ʵ�ּ̳е�Ч��
	class Adapter0 : public Adaptee, public Target
	{
	public:				
		void Request();//ʵ��Target�����Request�ӿڣ����Բ���virtual��
	};

	//������ģʽ�����������࣬�̳�Target�࣬������ϵķ�ʽʵ��Adaptee�ĸ���
	class Adapter1 :public Target
	{
	public:
		Adapter1(Adaptee* adaptee);
		Adapter1();
		~Adapter1();
		
		virtual void Request();//ʵ��Target�����Request�ӿ�
	private:
		Adaptee* _adaptee;
	};
	//////////////////////////////////////////////////////////////////////////

	using namespace std;

	void Target::Request()
	{
		cout << "Target::Request()" << endl;
	}
	
	void Adaptee::SpecificRequest()
	{		
		cout << "Adaptee::SpecificRequest():" << endl;
	}		
	void Adapter0::Request()
	{
		cout << "Adapter0::Request()" << endl;		
		this->SpecificRequest();
		cout << "----------------------------" << endl;
	}

	//����ģʽ��Adapter
	Adapter1::Adapter1() :_adaptee(new Adaptee)
	{
	}

	Adapter1::Adapter1(Adaptee* _adaptee)
	{
		this->_adaptee = _adaptee;
	}

	Adapter1::~Adapter1()
	{
	}

	void Adapter1::Request()
	{
		cout << "Adapter1::Request()" << endl;
		this->_adaptee->SpecificRequest();
		cout << "----------------------------" << endl;
	}
	//////////////////////////////////////////////////////////////////////////
	void AdapterPatternTest()
	{
		//��ģʽAdapter0
		Target* pTarget0 = new Adapter0();		
		pTarget0->Request();			

		//����ģʽAdapter1,û�г�ʼ����������ʹ�õ���Ĭ��ֵ
		Target* pTarget1 = new Adapter1();
		pTarget1->Request();

		//����ģʽAdapter1�����в���Ҫ�޸�ʱ��һ�������ַ�ʽ
		Adaptee* ade = new Adaptee();		
		Target* pTarget2 = new Adapter1(ade);//���紫�벻ͬ����Ƶ
		pTarget2->Request();
	}
}