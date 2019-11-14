/*�ļ�����TimeTutorial.h 
���ߣ�Yzy
˵����ʱ����ذ�����32λϵͳ��ʱ�����2038��ʱ�������
�ϴ��޸�ʱ�䣺2019/11/14
*/
#pragma once
namespace TimeTutorial {
	//�ӳ�ִ��
	void Delay(int time) {
		clock_t now = clock();
		while (clock() - now < time*1000);//��Ϊ��λ��ms��������Ҫ����1000		
	}
	
	void TimeTutorialTest() {
		//Delay(10);
		Sleep(1 * 1000);//ϵͳ�Դ�����ʱ����_sleep�ѱ�����

		time_t now;
		tm t;//һ��װʱ�����ݵĽṹ��
		time(&now);//��ֵ��ǰʱ���
		localtime_s(&t, &now);//��ʱ���תΪ����ʱ�䲢װ��t
		cout << now << endl;//1573720910

		char stTmp[32];
		asctime_s(stTmp,&t);//��ʽ��ʱ��

		cout << stTmp << endl;//Thu Nov 14 16:41:50 2019
	}
}