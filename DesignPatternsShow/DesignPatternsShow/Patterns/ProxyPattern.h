/*�ļ�����ProxyPattern.h
���ߣ�Yzy
˵��������ģʽ(���ù���ô���������ô����ô�������)
�ϴ��޸�ʱ�䣺2019/11/8 17��16��39 *
*/
#pragma once
#include <string>
#include <iostream>
namespace ProxyPattern {
	using namespace std;
	// ������ 
	class Image
	{
	public:
		Image(string name) : m_name(name) { }
		virtual ~Image() { }

		virtual void Show() = 0;      // ��ʾ�ĵ��ĺ���  

	protected:
		string m_name;       // �ĵ��� 
	};

	// ����ʵ����  
	class BigImage : public Image
	{
	public:
		BigImage(string name) : Image(name) { }
		virtual ~BigImage() { }

		void Show()
		{
			cout << "This is Big Image..."<<m_name << endl;
		}
	};

	// ����ͼƬ������  
	class BigImageProxy : public Image
	{
	public:
		BigImageProxy(string name) :Image(name), m_bigImage(NULL) { }
		virtual ~BigImageProxy()
		{
			delete m_bigImage;
			m_bigImage = nullptr;
		}

		void Show()
		{
			if (this->m_bigImage == NULL)
			{
				m_bigImage = new BigImage(this->m_name);
			}
			m_bigImage->Show();
		}

	private:
		BigImage *m_bigImage;
	};

	// �ͻ��˴���  
	void ProxyPatternTest()
	{
		Image *image = new BigImageProxy("Image.txt");
		image->Show();
		delete image;
		image = nullptr;

	}
}