/*文件名：TemplateMethodPattern.h
作者：Yzy
说明：模板方法模式(最基础的模式，实现抽象类方法)
上次修改时间：2019/11/11
*/
#pragma once
#include <iostream>
namespace TemplateMethodPattern {
	using namespace std;
	class Template {
	public:
		virtual void funA() = 0;
		virtual void funB() = 0;
	};
	class Concrete :public Template{
	public:
		void funA();
		void funB();
	};
	void Concrete::funA() {
		cout<<"实现了A"<<endl;
	}
	void Concrete::funB() {
		cout << "实现了B" << endl;
	}
	void TemplateMethodPatternTest() {
		Template* temp = new Concrete;
		temp->funA();
		temp->funB();
	}
}