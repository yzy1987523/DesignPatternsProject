/*文件名：MementoPattern.h
作者：Yzy
说明：备忘录模式（就是存档）
上次修改时间：2019/11/12 
*/
#pragma once
namespace MementoPattern {
#include <iostream>
#include <vector>
	using namespace std;
	//存档类
	class Memento
	{
	public:
		int m_vitality; //生命值
		int m_attack;   //进攻值
		int m_defense;  //防守值
	public:
		Memento(int vitality, int attack, int defense) :
			m_vitality(vitality), m_attack(attack), m_defense(defense) {}
		Memento& operator=(const Memento &memento)
		{
			m_vitality = memento.m_vitality;
			m_attack = memento.m_attack;
			m_defense = memento.m_defense;
			return *this;
		}
	};
	//游戏角色
	class GameRole
	{
	private:
		int m_vitality;
		int m_attack;
		int m_defense;
	public:
		GameRole() : m_vitality(100), m_attack(100), m_defense(100) {}
		Memento Save()  //保存进度，只与Memento对象交互，并不牵涉到Caretake
		{
			Memento memento(m_vitality, m_attack, m_defense);
			return memento;
		}
		void Load(Memento memento)  //载入进度，只与Memento对象交互，并不牵涉到Caretake
		{
			m_vitality = memento.m_vitality;
			m_attack = memento.m_attack;
			m_defense = memento.m_defense;
		}
		void Show() { cout << "vitality : " << m_vitality << ", attack : " << m_attack << ", defense : " << m_defense << endl; }
		void Attack() { m_vitality -= 10; m_attack -= 10;  m_defense -= 10; }
	};
	//保存存档的库
	class Caretake
	{
	public:
		Caretake() {}
		void Save(Memento menento) { m_vecMemento.push_back(menento); }
		Memento Load(int state) { return m_vecMemento[state]; }
	private:
		vector<Memento> m_vecMemento;
	};
	//////////////////////////////////////////////////////////////////////////
	//测试案例
	void MementoPatternTest()
	{
		Caretake caretake;
		GameRole role;
		role.Show();   //初始值
		caretake.Save(role.Save()); //保存状态
		role.Attack();
		role.Show();  //进攻后
		role.Load(caretake.Load(0)); //载入状态 
		role.Show();  //展示存档的数据
	}
}