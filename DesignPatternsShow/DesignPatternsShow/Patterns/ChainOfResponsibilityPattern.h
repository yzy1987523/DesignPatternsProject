/*文件名：ChainOfResponsibilityPattern.h
作者：YZY
说明：责任链模式（提出请求，从下级开始反馈请求，权限不够时请示上一级，最多获取最后一级的反馈）
上次修改时间：2019/11/11 
*/
#pragma once
namespace ChainOfResponsibilityPattern {
#include <iostream>
#include <string>
	using namespace std;
	// 请求
	class Request
	{
	public:
		int m_nNumber;
	};

	// 管理者
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

	// 经理
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
			cout << name << " 处理了请求: " << request->m_nNumber << endl;
		}
		else
		{
			manager->GetRequest(request);//获取上级的反馈
		}
	}

	// 总监
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
			cout << name << " 处理了请求: " << request->m_nNumber << endl;
		}
		else
		{
			manager->GetRequest(request);//获取上级的反馈
		}
	}

	//总经理  
	class GeneralManager : public Manager
	{
	public:
		GeneralManager(string name) :Manager(name) {}
		virtual void GetRequest(Request* request)  //总经理可以处理所有请求  
		{
			cout << name << " 处理了请求: " << request->m_nNumber << endl;//终极反馈
		}
	};

	void ChainOfResponsibilityPatternTest() {

		Manager* common = new CommonManager("张经理");
		Manager* major = new Majordomo("李总监");
		Manager* general = new GeneralManager("赵总");

		common->SetSuccessor(major);//处理不了就传递给下一个责任人
		major->SetSuccessor(general);

		Request* rq = new Request();//加薪要求

		rq->m_nNumber = 999;//少于1000的CommonManager阶段就能处理
		common->GetRequest(rq);

		rq->m_nNumber = 4999;
		common->GetRequest(rq);

		rq->m_nNumber = 6999;//大于5000的要到GeneralManager阶段处理
		common->GetRequest(rq);
	}
}