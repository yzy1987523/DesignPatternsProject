/*文件名：ForeachTutorial.h 
作者：YZY
说明：for_each的使用
上次修改时间：2019/11/13 
*/
#pragma once
namespace ForeachTutorial {
	struct Play
	{
		void operator () (int i)  //对小括号进行重载
		{
			a = i;
			cout << a << endl;
		}
		Play() {			
			cout << "new a Play" << endl;
		}		
		Play(const int& c)//拷贝成员函数
		{
			cout << "new a copy Play"<<c<< endl;
		}
		Play(const Play& c)//拷贝成员函数
		{
			cout << "new a copy Play" << c.a << endl;
		}
		~Play()//可以主动调用，但是总会在程序结束时再次调用
		{
			cout << "dispose a Play" << endl;
		}
		 int a;

	};
	void ForeachTutorialTest()
	{
		Play p1;
		p1(1);
		p1.~Play();

		Play p2(p1);
		p2(2);
		p2.~Play();

		int a[] = { 1, 3, 4, 5 };
		vector<int> vc(a, a + sizeof(a) / sizeof(int));//即vector<int> vc(a, a + 4);，声明一个容器，其中元素与数组a对应
		for_each(vc.begin(), vc.end(), Play());//Play结构体中会传入一个vc中的元素；会先初始化Play，再调用小括号的重载，【为何会调用拷贝函数？？？】
	}
}