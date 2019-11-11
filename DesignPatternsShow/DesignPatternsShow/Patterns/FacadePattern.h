/*�ļ�����FacadePattern.h
���ߣ�YZY
˵�������ģʽ(��Ȼ����ֱ�ӵ������࣬����Ϊ�˷��㣬��һϵ�����������һ����ǣ�ֻ�õ���һ����ǣ���������ִ����������)
�ϴ��޸�ʱ�䣺2019/11/7 
*/
#pragma once
namespace FacadePattern {
#include <iostream>
	using namespace std;
	class SubWork1 {
	public:
		void Event() {
			cout << "������1" << endl;
		};
	};
	class SubWork2 {
	public:
		void Event() {
			cout << "������2" << endl;
		};
	};
	class Work {
	private:
		SubWork1 work1;
		SubWork2 work2;
	public:
		void Event() {
			work1.Event();
			work2.Event();
		};
	};
	
	///
	void FacadePatternTest() {
		Work* w = new Work;
		w->Event();
	}
}