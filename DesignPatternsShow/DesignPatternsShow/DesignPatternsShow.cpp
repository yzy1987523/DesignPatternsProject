// DesignPatternsShow.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Patterns/SimpleFactoryPattern.h"//1
#include "Patterns/FactoryMethodPattern.h"//2
#include "Patterns/AbstractFactoryPattern.h"//3
#include "Patterns/BuilderPattern.h"//4
#include "Patterns/AdapterPattern.h"//5
#include "Patterns/BridgePattern.h"//6
#include "Patterns/DecoratorPattern.h"//7
#include "Patterns/FacadePattern.h"//8
#include "Patterns/FlyweightPattern.h"//9
#include "Patterns/ProxyPattern.h"//10
#include "Patterns/MediatorPattern.h"//11
#include "Patterns/ObserverPattern.h"//12
#include "Patterns/StatePattern.h"//13
#include "Patterns/StrategyPattern.h"//14
#include "Patterns/CommandPattern.h"//15
#include "Patterns/TemplateMethodPattern.h"
#include "Patterns/ChainOfResponsibilityPattern.h"
#include "Patterns/IteratorPattern.h"
#include "Patterns/VisitorPattern.h"
int main()
{
    std::cout << "Hello World!\n"; 
	//SimpleFactoryPattern::SimpleFactoryPatternTest();
	//FactoryMethodPattern::FactoryMethodPatternTest();
	//AbstractFactoryPattern::AbstractFactoryPatternTest();
	//BuilderPattern::BuilderPatternTest();
	//AdapterPattern::AdapterPatternTest();
	//BridgePattern::BridgePatternTest();
	//DecoratorPattern::DecoratorPatternTest();
	//FacadePattern::FacadePatternTest();
	//FlyweightPattern::FlyweightPatternTest();	
	//ProxyPattern::ProxyPatternTest();
	//MediatorPattern::MediatorPatternTest();
	//ObserverPattern::ObserverPatternTest();
	//StatePattern::StatePatternTest();
	//StrategyPattern::StrategyPatternTest();
	//CommandPattern::CommandPatternTest();
	//TemplateMethodPattern::TemplateMethodPatternTest();
	//ChainOfResponsibilityPattern::ChainOfResponsibilityPatternTest();
	//IteratorPattern::IteratorPatternTest();
	VisitorPattern::VisitorPatternTest();
}
