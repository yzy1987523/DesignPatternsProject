/*�ļ�����TemplateMethodPattern.h
���ߣ�Yzy
˵����ģ�巽��ģʽ(�������ģʽ��ʵ�ֳ����෽��)
�ϴ��޸�ʱ�䣺2019/11/11
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
		cout<<"ʵ����A"<<endl;
	}
	void Concrete::funB() {
		cout << "ʵ����B" << endl;
	}
	void TemplateMethodPatternTest() {
		Template* temp = new Concrete;
		temp->funA();
		temp->funB();
	}
}