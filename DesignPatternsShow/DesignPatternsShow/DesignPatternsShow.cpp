// DesignPatternsShow.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Patterns/SimpleFactoryPattern.h"
#include "Patterns/FactoryMethodPattern.h"
#include "Patterns/AbstractFactoryPattern.h"
#include "Patterns/BuilderPattern.h"
#include "Patterns/AdapterPattern.h"
#include "Patterns/BridgePattern.h"
#include "Patterns/DecoratorPattern.h"
#include "Patterns/FacadePattern.h"
#include "Patterns/FlyweightPattern.h"
#include "Patterns/ProxyPattern.h"
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
	ProxyPattern::ProxyPatternTest();
}
