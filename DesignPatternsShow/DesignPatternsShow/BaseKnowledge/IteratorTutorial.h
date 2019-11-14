/*文件名：IteratorTutorial.h 
作者：YZY
说明：迭代器案例（迭代器是容器类中的一个变量名，可以通过++计算获取下个元素）
上次修改时间：2019/11/14 
*/
#pragma once
#include <xmemory>
#include <stdexcept>
namespace IteratorTutorial {
	void IteratorTutorialTest(){
		vector<int> v;  //v是存放int类型变量的可变长数组，开始时没有元素
		for (int n = 0; n < 5; ++n)
			v.push_back(n);  //push_back成员函数在vector容器尾部添加一个元素
		vector<int>::iterator i;  //定义正向迭代器
		for (i = v.begin(); i != v.end(); ++i) {  //用迭代器遍历容器
			cout << *i << " ";  //*i 就是迭代器i指向的元素
			*i *= 2;  //每个元素变为原来的2倍
		}
		cout << endl;
		//用反向迭代器遍历容器
		for (vector<int>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j)
			cout << *j << " ";		
	}
}