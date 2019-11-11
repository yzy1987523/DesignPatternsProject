/*�ļ�����ChainOfResponsibilityPattern.h
���ߣ�YZY
˵����������ģʽ��������󣬴��¼���ʼ��������Ȩ�޲���ʱ��ʾ��һ��������ȡ���һ���ķ�����
�ϴ��޸�ʱ�䣺2019/11/11 
*/
#pragma once
namespace ChainOfResponsibilityPattern {
#include <iostream>
#include <string>
	using namespace std;
	// ����
	class Request
	{
	public:
		int m_nNumber;
	};

	// ������
	class Manager
	{
	public:
		Manager(string temp) { name = temp; }
		void SetSuccessor(Manager* temp) { manager = temp; }
		virtual void GetRequest(Request* request) = 0;
	protected:
		Manager* manager;
		string name;
	};

	// ����
	class CommonManager : public Manager
	{
	public:
		CommonManager(string strTemp) : Manager(strTemp) {}
		virtual void GetRequest(Request* request);
	};

	void CommonManager::GetRequest(Request* request)
	{
		if (request->m_nNumber >= 0 && request->m_nNumber < 1000)
		{
			cout << name << " ����������: " << request->m_nNumber << endl;
		}
		else
		{
			manager->GetRequest(request);//��ȡ�ϼ��ķ���
		}
	}

	// �ܼ�
	class Majordomo : public Manager
	{
	public:
		Majordomo(string strTemp) : Manager(strTemp) {}
		virtual void GetRequest(Request* request);
	};

	void Majordomo::GetRequest(Request* request)
	{
		if (request->m_nNumber <= 5000)
		{
			cout << name << " ����������: " << request->m_nNumber << endl;
		}
		else
		{
			manager->GetRequest(request);//��ȡ�ϼ��ķ���
		}
	}

	//�ܾ���  
	class GeneralManager : public Manager
	{
	public:
		GeneralManager(string name) :Manager(name) {}
		virtual void GetRequest(Request* request)  //�ܾ�����Դ�����������  
		{
			cout << name << " ����������: " << request->m_nNumber << endl;//�ռ�����
		}
	};

	void ChainOfResponsibilityPatternTest() {

		Manager* common = new CommonManager("�ž���");
		Manager* major = new Majordomo("���ܼ�");
		Manager* general = new GeneralManager("����");

		common->SetSuccessor(major);//�����˾ʹ��ݸ���һ��������
		major->SetSuccessor(general);

		Request* rq = new Request();//��нҪ��

		rq->m_nNumber = 999;//����1000��CommonManager�׶ξ��ܴ���
		common->GetRequest(rq);

		rq->m_nNumber = 4999;
		common->GetRequest(rq);

		rq->m_nNumber = 6999;//����5000��Ҫ��GeneralManager�׶δ���
		common->GetRequest(rq);
	}
}