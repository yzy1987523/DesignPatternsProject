/*文件名：ProxyPattern.h
作者：Yzy
说明：代理模式(不用管怎么创建，调用代理，让代理生成)
上次修改时间：2019/11/8 17：16：39 *
*/
#pragma once
#include <string>
#include <iostream>
namespace ProxyPattern {
	using namespace std;
	// 抽象类 
	class Image
	{
	public:
		Image(string name) : m_name(name) { }
		virtual ~Image() { }

		virtual void Show() = 0;      // 显示文档的函数  

	protected:
		string m_name;       // 文档名 
	};

	// 大型实体类  
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

	// 大型图片代理器  
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

	// 客户端代码  
	void ProxyPatternTest()
	{
		Image *image = new BigImageProxy("Image.txt");
		image->Show();
		delete image;
		image = nullptr;

	}
}