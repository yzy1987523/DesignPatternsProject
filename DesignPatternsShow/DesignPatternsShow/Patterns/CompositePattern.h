/*文件名：CompositePattern.h
作者：Yzy
说明：组合模式（基础模块可以组合成新的模块，新的模块又能作为子模块与其他模式组合）
上次修改时间：2019/11/12
*/
#pragma once
namespace CompositePattern {
	using namespace std;	
	//抽象类
	class Company
	{
	public:
		Company(string name) { m_name = name; }
		virtual ~Company() { cout << "删除 " <<m_name << endl; }
		virtual void Add(shared_ptr<Company> pCom) {}
		virtual void remove(shared_ptr<Company> pCom) {}

		virtual void Show(int depth)
		{
			for (int i = 0; i < depth; i++)
				cout << "-";
			cout << m_name << endl;
		}
	protected:
		string m_name;
	};

	//具体公司
	class ConcreteCompany : public Company
	{
		
	public:
		ConcreteCompany(string name) : Company(name) {}
		virtual ~ConcreteCompany() {}
		void Add(shared_ptr<Company> pCom) { m_listCompany.push_back(pCom); } //位于树的中间，可以增加子树
		void remove(shared_ptr<Company> pCom) { m_listCompany.remove(pCom); }
		void Show(int depth)
		{
			for (int i = 0; i < depth; i++)
				cout << "-";
			cout << m_name << endl;
			//        list<shared_ptr<Company>>::iterator iter=m_listCompany.begin();
			//        for(; iter != m_listCompany.end(); iter++) //显示下层结点
			//            (*iter)->Show(depth + 2);
			for (const auto& company : m_listCompany)
				company->Show(depth + 2);
		}
	private:
		list<shared_ptr<Company>> m_listCompany;
	};
	//具体的部门，财务部
	class FinanceDepartment : public Company
	{
	public:
		FinanceDepartment(string name) :Company(name) {}
		virtual ~FinanceDepartment() {}
		virtual void Show(int depth) //只需显示，无需添加函数，因为已是叶结点
		{
			for (int i = 0; i < depth; i++)
				cout << "-";
			cout << m_name << endl;
		}
	};
	//具体的部门，人力资源部
	class HRDepartment :public Company
	{
	public:
		HRDepartment(string name) :Company(name) {}
		virtual ~HRDepartment() {}
		virtual void Show(int depth) //只需显示，无需添加函数，因为已是叶结点
		{
			for (int i = 0; i < depth; i++)
				cout << "-";
			cout << m_name << endl;
		}
	};
	//////////////////////////////////////////////////////////////////////////
	void CompositePatternTest()
	{
		shared_ptr<Company> root = make_shared<ConcreteCompany>("总公司");
		shared_ptr<Company> leaf1 = make_shared<FinanceDepartment>("总公司人力资源部");
		shared_ptr<Company> leaf2 = make_shared<HRDepartment>("总公司财务部");
		root->Add(leaf1);
		root->Add(leaf2);

		//分公司A
		shared_ptr<Company> midA = make_shared<ConcreteCompany>("分公司A");
		shared_ptr<Company> leaf3 = make_shared< FinanceDepartment>("分公司A人力资源部");
		shared_ptr<Company> leaf4 = make_shared< HRDepartment>("分公司A财务部");
		midA->Add(leaf3);
		midA->Add(leaf4);
		root->Add(midA);
		//分公司B
		shared_ptr<Company> midB = make_shared< ConcreteCompany>("分公司B");
		shared_ptr<Company> leaf5 = make_shared< FinanceDepartment>("分公司B人力资源部");
		shared_ptr<Company> leaf6 = make_shared< HRDepartment>("分公司B财务部");
		midB->Add(leaf5);
		midB->Add(leaf6);
		root->Add(midB);

		//分公司B_1
		shared_ptr<Company> midB_1 = make_shared< ConcreteCompany>("分公司B_1");
		shared_ptr<Company> leaf7 = make_shared< FinanceDepartment>("分公司B_1人力资源部");
		shared_ptr<Company> leaf8 = make_shared< HRDepartment>("分公司B_1财务部");
		midB_1->Add(leaf7);
		midB_1->Add(leaf8);
		midB->Add(midB_1);

		//分公司A_1
		shared_ptr<Company> midA_1 = make_shared< ConcreteCompany>("分公司A_1");
		shared_ptr<Company> leaf9 = make_shared< FinanceDepartment>("分公司A_1人力资源部");
		shared_ptr<Company> leaf10 = make_shared< HRDepartment>("分公司A_1财务部");
		midA_1->Add(leaf9);
		midA_1->Add(leaf10);
		midA->Add(midA_1);

		shared_ptr<Company> leaf11 = make_shared< HRDepartment>("分公司A_2财务部");
		midA->Add(leaf11);
		midA->remove(leaf11);


		root->Show(0);
	}
}