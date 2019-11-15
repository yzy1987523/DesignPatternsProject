/*文件名：LambdaTutorial.h 
作者：YZY
说明：lambda表达式
上次修改时间：2019/11/15 
*/
#pragma once
namespace LambdaTutorial {
	void LambdaTutorialTest() {
		auto fun1=[](int x, int y) {return x + y; };
		auto fun2 = [](int x, int y)->int {return x + y; };

		cout << fun1(1, 2) << endl;
		cout << [](int x, int y)->int {return x + y; }(2, 3)<< endl;

		int m = 0, n = 0,l=0;
		[&, m,n](int a) mutable { m = ++n + a; l++; }(4);//除了m和n，其他变量都是传址（即改变时变量也改变）
		cout <<m<<";"<<n <<";"<<l<< endl;
	}
}