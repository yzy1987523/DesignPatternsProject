/*�ļ�����CommandPattern.h
���ߣ�YZY
˵��������ģʽ�������߻�ȡ�ͻ�����Ϣ���ٽ���Ϣ���ݸ��նˣ�
�ϴ��޸�ʱ�䣺2019/11/11
*/
#pragma once
namespace CommandPattern {
#include <iostream>  
#include <string>
#include <vector>
	using namespace std;

	/*����ʦ���ֻ࣬���𿾴�����*/
	class Barbecuer
	{
	public:
		void BakeMutton() { cout << "Bake mutton" << endl; }
		void BakeChickenWing() { cout << "Bake ChickenWing" << endl; }
	};

	/*���������ࣺ��ִ�о�������Ľӿ�*/
	class Command
	{
	public:
		Command() {}
		Command(Barbecuer *receiver) :p_receiver(receiver) {}
		virtual void ExecuteCommand() = 0; //ִ������
	protected:
		Barbecuer *p_receiver;
	};

	/*����������:�����⴮����*/
	class BakeMuttonCommand :public Command
	{
	public:
		BakeMuttonCommand(Barbecuer *receiver) { p_receiver = receiver; }
		void ExecuteCommand() { 
			p_receiver->BakeMutton(); 
		}
	};

	/*����������:�����ᴮ����*/
	class BakeChickenWingCommand :public Command
	{
	public:
		BakeChickenWingCommand(Barbecuer *receiver) { p_receiver = receiver; }
		void ExecuteCommand()
		{
			p_receiver->BakeChickenWing();
		}
	};

	/*����Ա��*/
	class Waiter
	{
	public:
		void SetOrder(Command *command);
		void Notify();
	private:
		vector<Command *>p_commandList; //�����൱��һ������������
	};

	void Waiter::SetOrder(Command *command)
	{
		p_commandList.push_back(command);
		cout << "���ӿ�������:"<< typeid(command).name() << endl;//��ȡ����
	}

	void Waiter::Notify()
	{
		vector<Command*>::iterator i;
		for (i = p_commandList.begin(); i != p_commandList.end(); ++i)
			(*i)->ExecuteCommand();
	}

	void CommandPatternTest()
	{
		//���ɿ���ʦ��������Ա����������
		Barbecuer *p_cook = new Barbecuer();
		Command *p_mutton = new BakeMuttonCommand(p_cook);
		Command *p_chickenwing = new BakeChickenWingCommand(p_cook);
		Waiter *p_waiter = new Waiter();

		//�������������͵��������
		p_waiter->SetOrder(p_mutton);
		p_waiter->SetOrder(p_chickenwing);

		//����Ա֪ͨ����ʦ�����嶩��
		p_waiter->Notify();

	}
}