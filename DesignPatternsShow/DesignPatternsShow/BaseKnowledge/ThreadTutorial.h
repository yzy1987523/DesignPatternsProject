/*文件名：ThreadTutorial.h 
作者：Yzy
说明：线程实例
上次修改时间：2019/11/15 
*/
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <numeric>
namespace ThreadTutorial {
	using namespace std;

	//线程要做的事情就写在这个线程函数中
	void fun1()
	{
		cout <<"1:1++++++" << endl;
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));//等待1s
		cout <<"1:2++++++" << endl;
		cout << endl;
	}
	void fun2(int v) {
		cout << "cpu核心个数" << thread::hardware_concurrency()<< endl;
		cout << endl;
		this_thread::yield();//让cpu执行其他空闲线程
		this_thread::sleep_for(chrono::milliseconds(1000));//等待1s
		cout <<"2:2++++++" << endl;
		cout << endl;
	}
	void fun3(int& n) {
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));//等待1s
		cout << "3:2++++++" << endl;
		cout << endl;
	}
	void ThreadTutorialTest() //主线程
	{
		thread f1(fun1); //声明子线程,同时开始执行
		thread f2(fun2, 1);
		
		int n = 10;
		thread f3(fun3, ref(n));
		thread f4(move(f3));//线程移动：f4线程获取f3线程的全部属性，f3线程被销毁
		cout << "==============" << endl;//可能在fun之前或之后执行，有一定随机性
		f1.detach();//分离子线程，让其自行执行，不会影响主线程【被称为守护进程】【当主线程结束时，分离子线程自动结束】
		f2.join(); 
		if (f3.joinable())//join前最好判断下
		{
			cout <<"================================================" << endl;
			f3.join();//阻塞主线程，直子线程完成
		}	
		f4.join();
	}
}