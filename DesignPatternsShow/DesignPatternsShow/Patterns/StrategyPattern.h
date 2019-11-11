/*文件名：StrategyPattern.h
作者：YZY
说明：策略模式（某个对象有多个组成部分，每个部分都有若干类型，生成一个对象时会选择指定的类型）
上次修改时间：2019/11/11
*/
#pragma once
namespace StrategyPattern {
#include <iostream>
	//飞行行为，用抽象类表示
	class FlyBehavior {
	public:
		virtual ~FlyBehavior() {};
		virtual void fly() = 0;
	};
	//叫声行为，用抽象类表示
	class QuackBehavior {
	public:
		virtual ~QuackBehavior() {};
		virtual void quack() = 0;
	};
	//鸭子基类，有display，performFly， performQuack，swim等方法。
	class Duck {
	public:
		Duck(FlyBehavior*p_FlyBehavior, QuackBehavior* p_QuackBehavior)
		{
			pFlyBehavior = p_FlyBehavior;
			pQuackBehavior = p_QuackBehavior;

		}
		virtual ~Duck() {};
		virtual void display() {};
		void performFly()
		{
			pFlyBehavior->fly();
		}
		void performQuack()
		{
			pQuackBehavior->quack();
		}
		void swim()
		{
			std::cout << ("All ducks float, even decoys!") << std::endl;
		}
	private:
		FlyBehavior*pFlyBehavior;
		QuackBehavior*pQuackBehavior;
	};
	//实现飞行行为的方法类
	class FlyWithWings : public FlyBehavior {
	public:
		void fly() {
			std::cout << ("I'm flying!!") << std::endl;
		}
	};

	class FlyNoWay : public FlyBehavior {
	public:
		void fly() {
			std::cout << ("I can't fly") << std::endl;
		}
	};
	//实现叫声行为的类
	class Quack : public QuackBehavior {
	public:
		void quack() {
			std::cout << ("Quack") << std::endl;
		}
	};

	class MuteQuack : public QuackBehavior {
	public:
		void quack() {
			std::cout << ("<< Slience >>") << std::endl;
		}
	};

	class Squeak : public QuackBehavior {
	public:
		void quack() {
			std::cout << "Squeak" << std::endl;
		}
	};
	//绿头鸭类
	class MallardDuck : public Duck {
	public:
		MallardDuck(FlyBehavior*fly_behavior = new FlyWithWings(),
			QuackBehavior*quack_behavior = new Quack())
			:Duck(fly_behavior, quack_behavior) {}

		void display()
		{
			std::cout << "I'm a real Mallard duck" << std::endl;
		}
	};

	void StrategyPatternTest()
	{
		Duck*mallard = new MallardDuck();
		mallard->display();
		mallard->performFly();
		mallard->performQuack();
		mallard->swim();
	}
}