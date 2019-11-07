/*�ļ�����DecoratorPattern.h
���ߣ�Yzy
˵����װ��ģʽ����ʵ���Ǵ���������࣬Ȼ������Ϊ�������ݣ�ÿ�δ��ݾͻ������һ������Ĺ��ܣ�
�ϴ��޸�ʱ�䣺2019/11/7 09��21��09 *
*/
#pragma once
namespace DecoratorPattern {
#include <iostream>
	using namespace std;

	//̹�˳����� component
	class Tank
	{
	public:
		virtual void shot() = 0;		
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
	public:
		void decorator(Tank *_tank)
		{
			this->tank = _tank;
		}
		void shot()
		{
			tank->shot();
		}
	protected:  //���������protectŶ  ��Ϊ�����̳�Decorator����Ҫ��
		Tank *tank;//has_a�Ĺ�ϵ
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
		pDecorator->decorator(ptank);//װ��������
		BigShot *pBig = new BigShot();
		pBig->decorator(pDecorator);//װ������Ʒ1
		SilentShot *pBigSlient = new SilentShot();
		pBigSlient->decorator(pBig);//װ������Ʒ2
		pBigSlient->shot();

	}
}