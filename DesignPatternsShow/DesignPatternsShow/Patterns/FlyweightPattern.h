/*文件名：FlyweightPattern.h
作者：YZY
说明：享元模式（其实就是简化版对象池）
上次修改时间：2019/11/8 
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
		cout << "实例化了一个对象！" << endl;
	}
	///

	//using namespace std;
	class Pool {
	public:
		Pool();
		~Pool();
		BaseObj*GetObj();
	private:
		vector<BaseObj*> objlist;//抽象类不能作为实例化对象，只能作为指针对象；或者直接使用实例化对象作为元素
		//vector<Obj> objlist;//【法二】
	};
	///
	Pool::Pool() {
		BaseObj*temp=new Obj;
		//Obj temp;//【法二】

		objlist.push_back(temp);

	}
	Pool::~Pool() {
		BaseObj*temp = objlist.at(0);
		//BaseObj*temp=&objlist.at(0);//【法二】

		delete temp;
		temp = nullptr;
	}
	BaseObj*Pool::GetObj() {
		BaseObj*temp = objlist.at(0);
		//BaseObj*temp = &objlist.at(0);//【法二】

		return temp;
	}
	///
	void FlyweightPatternTest() {
		Pool* pool = new Pool;
		BaseObj*temp = pool->GetObj();
		temp->fun();
	}


}