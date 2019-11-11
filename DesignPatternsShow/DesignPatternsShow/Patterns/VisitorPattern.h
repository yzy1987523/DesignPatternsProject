/*�ļ�����VisitorPattern.h
���ߣ�Yzy
˵����������ģʽ�����Ʒ���������ɾ�Ĳ飩
�ϴ��޸�ʱ�䣺2019/11/11
*/
#pragma once
namespace VisitorPattern {
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
	using namespace std;

	class Element;

	class Visitor
	{
	public:
		virtual void Visit(Element *element) {};
	};	
	class Element
	{
	public:
		// Methods
		virtual void Accept(Visitor *visitor) {};
	};


	// ������Ա
	class Employee : public Element
	{
	public:
		string name;
		double income;
		int vacationDays;

	public:
		Employee(string name, double income,
			int vacationDays)
		{
			this->name = name;
			this->income = income;
			this->vacationDays = vacationDays;
		}

		void Accept(Visitor *visitor)
		{
			visitor->Visit(this);
		}
	};
	//����
	class IncomeVisitor : public Visitor
	{
	public:
		void Visit(Element *element)
		{
			Employee *employee = ((Employee*)element);
			//employee->income *= 1.10;
			cout << employee->name << " 's  income: " << employee->income << endl;

		}
	};
	//����
	class VacationVisitor : public Visitor
	{
	public:
		void Visit(Element *element)
		{
			Employee *employee = ((Employee*)element);
			// Provide 3 extra vacation days
			//employee->vacationDays += 3;
			cout << employee->name << " 's  vacation days: " << employee->vacationDays << endl;
		}
	};

	//��˾
	class Employees
	{
	private:
		list<Employee*> employees;

	public:

		void Attach(Employee *employee)
		{
			employees.push_back(employee);
		}

		
		Employee* GetElement(string name) {		
			list<Employee*>::iterator itr = employees.begin();
			while (&itr!=nullptr)
			{				
				if ((*itr)->name == name) {
					return *itr;
				}
				itr++;
			}
			return nullptr;
		}
		void Change(string name,Employee *employee) {
			Employee*temp = GetElement(name);
			temp->name = employee->name;
			temp->income = employee->income;
			temp->vacationDays = employee->vacationDays;
		}
		void Detach(string name)
		{			
			employees.remove(GetElement(name));
		}		
		void Accept(Visitor *visitor)
		{
			//for (std::list<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it)
			//	(*it)->Accept(visitor);
			for_each(employees.begin(), 
				employees.end(), 
				[visitor](Element*temp)->//��պ����ֲ�����������lambda�������ã�����λ�ڲ����б���,���������������[]�У���������ö��ŷָ�
				void {temp->Accept(visitor); });
		}
	};

	void VisitorPatternTest()
	{
		Employees *e = new Employees();
		e->Attach(new Employee("Tom", 2500, 4));//��
		e->Attach(new Employee("Thomas", 3500, 6));
		e->Attach(new Employee("Roy", 4500, 2));

		e->Detach("Tom");//ɾ
		e->Change("Roy", new Employee("Roy1", 200, 1));//��
		//��������
		Visitor *v1 = new IncomeVisitor();
		//���ʼ���
		Visitor *v2 = new VacationVisitor();

		e->Accept(v1);//��
		e->Accept(v2);


	}
}