/*�ļ�����InterpreterPattern.h
���ߣ�Yzy
˵����������ģʽ
�ϴ��޸�ʱ�䣺2019/11/12
*/
#pragma once
namespace InterpreterPattern {
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <typeinfo>

	using namespace std;

	//*******************************************������ʽ��***********************************
	class Expression
	{
	public:
		//������ʽ����ֵ������var�е�key�ǹ�ʽ�еĲ�����valueֵ�Ǿ��������
		//��a = 100; b = 20; c = 40
		virtual int interpreter(map<string, int>& var) = 0;
		virtual ~Expression() {};
	};


	//�������������ս�����ʽ��
	class VarExpression : public Expression
	{
		string key;
	public:
		VarExpression(string key)
		{
			this->key = key;
		}

		//��map��ȡ��������ֵ
		int interpreter(map<string, int>& var)
		{
			return var[key];
		}

		~VarExpression()
		{
			cout << "~VarExpression()" << endl;
		}
	};
	//**********����������Ž�����***********************
	//����������Ž�����
	class SymbolExpression : public Expression
	{
	protected:
		Expression* left;
		Expression* right;
	public:
		SymbolExpression(Expression* left, Expression* right)
		{
			this->left = left;
			this->right = right;
		}

		Expression* getLeft()
		{
			return left;
		}
		Expression* getRight()
		{
			return right;
		}
	};

	//�ӷ�������
	class AddExpression : public SymbolExpression
	{
	public:
		AddExpression(Expression* left, Expression* right) : SymbolExpression(left, right)
		{
		}

		//�������������ʽ����Ľ��������
		int interpreter(map<string, int>& var)
		{
			return left->interpreter(var) + right->interpreter(var);
		}
		~AddExpression()
		{
			cout << "~AddExpression()" << endl;
		}
	};

	//����������
	class SubExpression : public SymbolExpression
	{
	public:
		SubExpression(Expression* left, Expression* right) : SymbolExpression(left, right)
		{
		}

		//�������������ʽ����Ľ�����
		int interpreter(map<string, int>& var)
		{
			return left->interpreter(var) - right->interpreter(var);
		}

		~SubExpression()
		{
			cout << "~SubExpression()" << endl;
		}
	};

	//*********************************��������װ��***************************************
	//��������װ�࣬������Ǹ��ݵ����ط�����з�װ��Ŀ������Clientֻ��ֱ�����Ѵ򽻵����൱��Facade
	class Calculator
	{
	private:
		Expression* expression;
	public:
		//���캯�����Σ����������ʽ�������﷨��
		Calculator(string expStr)
		{
			expression = NULL;

			//ջ�������ݴ��м���
			stack<Expression*> stkExp;

			Expression* left = NULL;
			Expression* right = NULL;

			/*������������ʽ����:a+b-c)�����յ��﷨�����£�
			 *           -
			 *         /   \
			 *       +     c
			 *     /   \
			 *    a     b
			*/
			for (unsigned int i = 0; i < expStr.length(); i++)
			{
				switch (expStr[i])
				{
				case '+':  //�ӷ�
					//1.�ȴ�ջ��ȡ���������
					left = stkExp.top();
					stkExp.pop();

					//2.�ӱ��ʽ��ȡ��+�ź�����Ҳ��������������ս����������
					right = new VarExpression(expStr.substr(++i, 1));

					//3.�����Ҳ�������ӣ����ѽ������ջ��
					stkExp.push(new AddExpression(left, right));

					break;

				case '-':
					//1.�ȴ�ջ��ȡ���������
					left = stkExp.top();
					stkExp.pop();

					//2.�ӱ��ʽ��ȡ��+�ź�����Ҳ��������������ս����������
					right = new VarExpression(expStr.substr(++i, 1));

					//3.�����Ҳ�������������ѽ������ջ��
					stkExp.push(new SubExpression(left, right));

					break;

				default:
					//����Ǳ������ս��������a+b+c�е�a\b\c��
					//��ֱ�����ɶ�Ӧ�ı�������������
					stkExp.push(new VarExpression(expStr.substr(i, 1)));
				}
			}

			//ջ�б���ľ��������﷨���ĸ���㣨����ΪSuuExpression����
			if (!stkExp.empty())
			{
				expression = stkExp.top();
				stkExp.pop();
			}
		}

		void deltree(Expression* expression)
		{
			SymbolExpression* branch = dynamic_cast<SymbolExpression*>(expression);
			//Ҷ�ӽ��
			if (branch == NULL)
			{
				delete expression;
			}
			else  //��֧���
			{
				//������
				deltree(branch->getLeft());

				//������
				deltree(branch->getRight());

				//���
				delete expression;
			}
		}

		~Calculator()
		{
			deltree(expression);
			expression = NULL;
		}

		//��ʼ����
		int run(map<string, int>& var)
		{
			return (expression == NULL) ? 0 : expression->interpreter(var);
		}
	};
	void InterpreterPatternTest()
	{
		string expStr = "a+b-c"; //Ϊ�򻯴�����������ǺϷ��ı��ʽ

		map<string, int> var;   //�൱��Interpreterģʽ�е�Context
		var["a"] = 100;
		var["b"] = 20;
		var["c"] = 40;

		Calculator cal(expStr);

		cout << "������Ϊ��" << expStr << " = " << cal.run(var) << endl;
	}
}
