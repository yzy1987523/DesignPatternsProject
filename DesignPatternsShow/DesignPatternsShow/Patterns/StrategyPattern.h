/*�ļ�����StrategyPattern.h
���ߣ�YZY
˵��������ģʽ��ĳ�������ж����ɲ��֣�ÿ�����ֶ����������ͣ�����һ������ʱ��ѡ��ָ�������ͣ�
�ϴ��޸�ʱ�䣺2019/11/11
*/
#pragma once
namespace StrategyPattern {
#include <iostream>
	//������Ϊ���ó������ʾ
	class FlyBehavior {
	public:
		virtual ~FlyBehavior() {};
		virtual void fly() = 0;
	};
	//������Ϊ���ó������ʾ
	class QuackBehavior {
	public:
		virtual ~QuackBehavior() {};
		virtual void quack() = 0;
	};
	//Ѽ�ӻ��࣬��display��performFly�� performQuack��swim�ȷ�����
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
	//ʵ�ַ�����Ϊ�ķ�����
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
	//ʵ�ֽ�����Ϊ����
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
	//��ͷѼ��
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