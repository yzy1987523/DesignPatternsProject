/*�ļ�����IteratorTutorial.h 
���ߣ�YZY
˵�������������������������������е�һ��������������ͨ��++�����ȡ�¸�Ԫ�أ�
�ϴ��޸�ʱ�䣺2019/11/14 
*/
#pragma once
#include <xmemory>
#include <stdexcept>
namespace IteratorTutorial {
	void IteratorTutorialTest(){
		vector<int> v;  //v�Ǵ��int���ͱ����Ŀɱ䳤���飬��ʼʱû��Ԫ��
		for (int n = 0; n < 5; ++n)
			v.push_back(n);  //push_back��Ա������vector����β�����һ��Ԫ��
		vector<int>::iterator i;  //�������������
		for (i = v.begin(); i != v.end(); ++i) {  //�õ�������������
			cout << *i << " ";  //*i ���ǵ�����iָ���Ԫ��
			*i *= 2;  //ÿ��Ԫ�ر�Ϊԭ����2��
		}
		cout << endl;
		//�÷����������������
		for (vector<int>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j)
			cout << *j << " ";		
	}
}