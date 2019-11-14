/*文件名：TimeTutorial.h 
作者：Yzy
说明：时间相关案例（32位系统的时间戳到2038年时会溢出）
上次修改时间：2019/11/14
*/
#pragma once
namespace TimeTutorial {
	//延迟执行
	void Delay(int time) {
		clock_t now = clock();
		while (clock() - now < time*1000);//因为单位是ms，所以需要乘以1000		
	}
	
	void TimeTutorialTest() {
		//Delay(10);
		Sleep(1 * 1000);//系统自带的延时函数_sleep已被废弃

		time_t now;
		tm t;//一个装时间数据的结构体
		time(&now);//赋值当前时间戳
		localtime_s(&t, &now);//将时间戳转为本地时间并装入t
		cout << now << endl;//1573720910

		char stTmp[32];
		asctime_s(stTmp,&t);//格式化时间

		cout << stTmp << endl;//Thu Nov 14 16:41:50 2019
	}
}