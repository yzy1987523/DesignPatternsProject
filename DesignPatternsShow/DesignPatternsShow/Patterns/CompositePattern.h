/*�ļ�����CompositePattern.h
���ߣ�Yzy
˵�������ģʽ������ģ�������ϳ��µ�ģ�飬�µ�ģ��������Ϊ��ģ��������ģʽ��ϣ�
�ϴ��޸�ʱ�䣺2019/11/12
*/
#pragma once
namespace CompositePattern {
	using namespace std;	
	//������
	class Company
	{
	public:
		Company(string name) { m_name = name; }
		virtual ~Company() { cout << "ɾ�� " <<m_name << endl; }
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

	//���幫˾
	class ConcreteCompany : public Company
	{
		
	public:
		ConcreteCompany(string name) : Company(name) {}
		virtual ~ConcreteCompany() {}
		void Add(shared_ptr<Company> pCom) { m_listCompany.push_back(pCom); } //λ�������м䣬������������
		void remove(shared_ptr<Company> pCom) { m_listCompany.remove(pCom); }
		void Show(int depth)
		{
			for (int i = 0; i < depth; i++)
				cout << "-";
			cout << m_name << endl;
			//        list<shared_ptr<Company>>::iterator iter=m_listCompany.begin();
			//        for(; iter != m_listCompany.end(); iter++) //��ʾ�²���
			//            (*iter)->Show(depth + 2);
			for (const auto& company : m_listCompany)
				company->Show(depth + 2);
		}
	private:
		list<shared_ptr<Company>> m_listCompany;
	};
	//����Ĳ��ţ�����
	class FinanceDepartment : public Company
	{
	public:
		FinanceDepartment(string name) :Company(name) {}
		virtual ~FinanceDepartment() {}
		virtual void Show(int depth) //ֻ����ʾ��������Ӻ�������Ϊ����Ҷ���
		{
			for (int i = 0; i < depth; i++)
				cout << "-";
			cout << m_name << endl;
		}
	};
	//����Ĳ��ţ�������Դ��
	class HRDepartment :public Company
	{
	public:
		HRDepartment(string name) :Company(name) {}
		virtual ~HRDepartment() {}
		virtual void Show(int depth) //ֻ����ʾ��������Ӻ�������Ϊ����Ҷ���
		{
			for (int i = 0; i < depth; i++)
				cout << "-";
			cout << m_name << endl;
		}
	};
	//////////////////////////////////////////////////////////////////////////
	void CompositePatternTest()
	{
		shared_ptr<Company> root = make_shared<ConcreteCompany>("�ܹ�˾");
		shared_ptr<Company> leaf1 = make_shared<FinanceDepartment>("�ܹ�˾������Դ��");
		shared_ptr<Company> leaf2 = make_shared<HRDepartment>("�ܹ�˾����");
		root->Add(leaf1);
		root->Add(leaf2);

		//�ֹ�˾A
		shared_ptr<Company> midA = make_shared<ConcreteCompany>("�ֹ�˾A");
		shared_ptr<Company> leaf3 = make_shared< FinanceDepartment>("�ֹ�˾A������Դ��");
		shared_ptr<Company> leaf4 = make_shared< HRDepartment>("�ֹ�˾A����");
		midA->Add(leaf3);
		midA->Add(leaf4);
		root->Add(midA);
		//�ֹ�˾B
		shared_ptr<Company> midB = make_shared< ConcreteCompany>("�ֹ�˾B");
		shared_ptr<Company> leaf5 = make_shared< FinanceDepartment>("�ֹ�˾B������Դ��");
		shared_ptr<Company> leaf6 = make_shared< HRDepartment>("�ֹ�˾B����");
		midB->Add(leaf5);
		midB->Add(leaf6);
		root->Add(midB);

		//�ֹ�˾B_1
		shared_ptr<Company> midB_1 = make_shared< ConcreteCompany>("�ֹ�˾B_1");
		shared_ptr<Company> leaf7 = make_shared< FinanceDepartment>("�ֹ�˾B_1������Դ��");
		shared_ptr<Company> leaf8 = make_shared< HRDepartment>("�ֹ�˾B_1����");
		midB_1->Add(leaf7);
		midB_1->Add(leaf8);
		midB->Add(midB_1);

		//�ֹ�˾A_1
		shared_ptr<Company> midA_1 = make_shared< ConcreteCompany>("�ֹ�˾A_1");
		shared_ptr<Company> leaf9 = make_shared< FinanceDepartment>("�ֹ�˾A_1������Դ��");
		shared_ptr<Company> leaf10 = make_shared< HRDepartment>("�ֹ�˾A_1����");
		midA_1->Add(leaf9);
		midA_1->Add(leaf10);
		midA->Add(midA_1);

		shared_ptr<Company> leaf11 = make_shared< HRDepartment>("�ֹ�˾A_2����");
		midA->Add(leaf11);
		midA->remove(leaf11);


		root->Show(0);
	}
}