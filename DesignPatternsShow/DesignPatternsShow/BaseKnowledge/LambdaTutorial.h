/*�ļ�����LambdaTutorial.h 
���ߣ�YZY
˵����lambda���ʽ
�ϴ��޸�ʱ�䣺2019/11/15 
*/
#pragma once
namespace LambdaTutorial {
	void LambdaTutorialTest() {
		auto fun1=[](int x, int y) {return x + y; };
		auto fun2 = [](int x, int y)->int {return x + y; };

		cout << fun1(1, 2) << endl;
		cout << [](int x, int y)->int {return x + y; }(2, 3)<< endl;

		int m = 0, n = 0,l=0;
		[&, m,n](int a) mutable { m = ++n + a; l++; }(4);//����m��n�������������Ǵ�ַ�����ı�ʱ����Ҳ�ı䣩
		cout <<m<<";"<<n <<";"<<l<< endl;
	}
}