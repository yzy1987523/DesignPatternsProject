/*�ļ�����ForeachTutorial.h 
���ߣ�YZY
˵����for_each��ʹ��
�ϴ��޸�ʱ�䣺2019/11/13 
*/
#pragma once
namespace ForeachTutorial {
	struct Play
	{
		void operator () (int i)  //��С���Ž�������
		{
			a = i;
			cout << a << endl;
		}
		Play() {			
			cout << "new a Play" << endl;
		}		
		Play(const int& c)//������Ա����
		{
			cout << "new a copy Play"<<c<< endl;
		}
		Play(const Play& c)//������Ա����
		{
			cout << "new a copy Play" << c.a << endl;
		}
		~Play()//�����������ã������ܻ��ڳ������ʱ�ٴε���
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
		vector<int> vc(a, a + sizeof(a) / sizeof(int));//��vector<int> vc(a, a + 4);������һ������������Ԫ��������a��Ӧ
		for_each(vc.begin(), vc.end(), Play());//Play�ṹ���лᴫ��һ��vc�е�Ԫ�أ����ȳ�ʼ��Play���ٵ���С���ŵ����أ���Ϊ�λ���ÿ���������������
	}
}