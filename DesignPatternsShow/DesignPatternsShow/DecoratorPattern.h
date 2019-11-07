/*文件名：DecoratorPattern.h
作者：Yzy
说明：装饰模式（其实就是创建多个子类，然后将类作为参数传递，每次传递就会添加上一个子类的功能）
上次修改时间：2019/11/7 09：21：09 *
*/
#pragma once
namespace DecoratorPattern {
#include <iostream>
	using namespace std;

	//坦克抽象类 component
	class Tank
	{
	public:
		virtual void shot() = 0;		
	};

	//Concrete Component  
	class T50 :public Tank //具体的一种坦克 型号为T50 也可以有很多其它种类的坦克
	{
	public:
		void shot()
		{
			cout << "T50开炮" << endl;
		}
	};

	//Decorator   
	class Decorator : public Tank//此处不应认为是is_a关系 而应该认为是like_a
	{
	public:
		void decorator(Tank *_tank)
		{
			this->tank = _tank;
		}
		void shot()
		{
			tank->shot();
		}
	protected:  //这里必须是protect哦  因为其它继承Decorator的类要用
		Tank *tank;//has_a的关系
	};


	//DecoratorA  加大火力
	class BigShot :public  Decorator
	{

	public:
		void shot()
		{
			//为了死的安详，我想被大火力打死，另外请静音
			cout << "大火力准备完毕" << endl;
			tank->shot();

		}
	};


	//DecoratorB     消音
	class SilentShot :public Decorator
	{

	public:
		void shot()
		{
			//为保证是被炮打死 而不是震死，请静音
			cout << "消音完毕" << endl;
			tank->shot();
		}
	};

	void DecoratorPatternTest()
	{
		Tank *ptank = new T50();
		Decorator *pDecorator = new Decorator();
		pDecorator->decorator(ptank);//装配上主体
		BigShot *pBig = new BigShot();
		pBig->decorator(pDecorator);//装配上饰品1
		SilentShot *pBigSlient = new SilentShot();
		pBigSlient->decorator(pBig);//装配上饰品2
		pBigSlient->shot();

	}
}