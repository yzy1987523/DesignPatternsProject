/*文件名：FacadePattern.h
作者：YZY
说明：外观模式(虽然可以直接调用子类，但是为了方便，给一系列子任务加了一层外壳，只用调用一次外壳，就能完整执行所有任务)
上次修改时间：2019/11/7 
*/
#pragma once
namespace FacadePattern {
#include <iostream>
	using namespace std;
	class SubWork1 {
	public:
		void Event() {
			cout << "子任务1" << endl;
		};
	};
	class SubWork2 {
	public:
		void Event() {
			cout << "子任务2" << endl;
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