/*�ļ�����FlyweightPattern.h
���ߣ�YZY
˵������Ԫģʽ����ʵ���Ǽ򻯰����أ�
�ϴ��޸�ʱ�䣺2019/11/8 
*/
#pragma once
#include <vector>
#include <iostream>
namespace FlyweightPattern {

	using namespace std;
	class BaseObj {
	public:
		virtual void fun() = 0;
	};
	class Obj :public BaseObj {
	public:
		void fun();
	};
	void Obj::fun() {
		cout << "ʵ������һ������" << endl;
	}
	///

	//using namespace std;
	class Pool {
	public:
		Pool();
		~Pool();
		BaseObj*GetObj();
	private:
		vector<BaseObj*> objlist;//�����಻����Ϊʵ��������ֻ����Ϊָ����󣻻���ֱ��ʹ��ʵ����������ΪԪ��
		//vector<Obj> objlist;//��������
	};
	///
	Pool::Pool() {
		BaseObj*temp=new Obj;
		//Obj temp;//��������

		objlist.push_back(temp);

	}
	Pool::~Pool() {
		BaseObj*temp = objlist.at(0);
		//BaseObj*temp=&objlist.at(0);//��������

		delete temp;
		temp = nullptr;
	}
	BaseObj*Pool::GetObj() {
		BaseObj*temp = objlist.at(0);
		//BaseObj*temp = &objlist.at(0);//��������

		return temp;
	}
	///
	void FlyweightPatternTest() {
		Pool* pool = new Pool;
		BaseObj*temp = pool->GetObj();
		temp->fun();
	}


}