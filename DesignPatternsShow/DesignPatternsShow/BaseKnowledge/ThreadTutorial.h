/*�ļ�����ThreadTutorial.h 
���ߣ�Yzy
˵�����߳�ʵ��
�ϴ��޸�ʱ�䣺2019/11/15 
*/
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <numeric>
namespace ThreadTutorial {
	using namespace std;

	//�߳�Ҫ���������д������̺߳�����
	void fun1()
	{
		cout <<"1:1++++++" << endl;
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));//�ȴ�1s
		cout <<"1:2++++++" << endl;
		cout << endl;
	}
	void fun2(int v) {
		cout << "cpu���ĸ���" << thread::hardware_concurrency()<< endl;
		cout << endl;
		this_thread::yield();//��cpuִ�����������߳�
		this_thread::sleep_for(chrono::milliseconds(1000));//�ȴ�1s
		cout <<"2:2++++++" << endl;
		cout << endl;
	}
	void fun3(int& n) {
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));//�ȴ�1s
		cout << "3:2++++++" << endl;
		cout << endl;
	}
	void ThreadTutorialTest() //���߳�
	{
		thread f1(fun1); //�������߳�,ͬʱ��ʼִ��
		thread f2(fun2, 1);
		
		int n = 10;
		thread f3(fun3, ref(n));
		thread f4(move(f3));//�߳��ƶ���f4�̻߳�ȡf3�̵߳�ȫ�����ԣ�f3�̱߳�����
		cout << "==============" << endl;//������fun֮ǰ��֮��ִ�У���һ�������
		f1.detach();//�������̣߳���������ִ�У�����Ӱ�����̡߳�����Ϊ�ػ����̡��������߳̽���ʱ���������߳��Զ�������
		f2.join(); 
		if (f3.joinable())//joinǰ����ж���
		{
			cout <<"================================================" << endl;
			f3.join();//�������̣߳�ֱ���߳����
		}	
		f4.join();
	}
}