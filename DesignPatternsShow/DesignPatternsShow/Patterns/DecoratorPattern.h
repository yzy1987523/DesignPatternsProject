/*�ļ�����DecoratorPattern.h
���ߣ�Yzy
˵����װ��ģʽ
�ϴ��޸�ʱ�䣺2019/11/6 
*/
#pragma once
namespace DecoratorPattern {
#include <iostream>
	using namespace std;

	//̹�˳����� component
	class Tank
	{
	public:
		virtual void shot()
		{
			cout << "���ҿ��ڣ�" << endl;
		}
	};

	//Concrete Component  
	class T50 :public Tank //�����һ��̹�� �ͺ�ΪT50 Ҳ�����кܶ����������̹��
	{
	public:
		void shot()
		{
			cout << "T50����" << endl;
		}
	};

	//Decorator   
	class Decorator : public Tank//�˴���Ӧ��Ϊ��is_a��ϵ ��Ӧ����Ϊ��like_a
	{
	protected:  //���������protectŶ  ��Ϊ�����̳�Decorator����Ҫ��
		Tank *tank;//has_a�Ĺ�ϵ

	public:
		void decorator(Tank *_tank)
		{
			this->tank = _tank;
		}
		void shot()
		{
			tank->shot();
		}
	};


	//DecoratorA  �Ӵ����
	class BigShot :public  Decorator
	{

	public:
		void shot()
		{
			//Ϊ�����İ��꣬���뱻����������������뾲��
			cout << "�����׼�����" << endl;
			tank->shot();

		}
	};


	//DecoratorB     ����
	class SilentShot :public Decorator
	{

	public:
		void shot()
		{
			//Ϊ��֤�Ǳ��ڴ��� �������������뾲��
			cout << "�������" << endl;
			tank->shot();
		}
	};

	void DecoratorPatternTest()
	{
		Tank *ptank = new T50();
		Decorator *pDecorator = new Decorator();
		pDecorator->decorator(ptank);
		BigShot *pBig = new BigShot();
		pBig->decorator(pDecorator);
		SilentShot *pBigSlient = new SilentShot();
		pBigSlient->decorator(pBig);
		pBigSlient->shot();

	}
}