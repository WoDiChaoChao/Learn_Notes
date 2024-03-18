#include <iostream>
using namespace std;

//继承的语法
//class 子类 : 继承方式 父类

class BasePage
{
public:
	void head() {
		cout << "首页，帮助，免费学习视频" << endl;
	}

	void tail() {
		cout << "备案号，友情链接" << endl;
	}

	void left() {
		cout << "左侧公共分类标签" << endl;
	}

};

class Java : public BasePage
{
public:
	void content() {
		cout << "Java学习视频" << endl;
	}

private:

};

class Python : public BasePage
{
public:
	void content() {
		cout << "Python学习视频" << endl;
	}

private:

};

void test() {
	Java java;
	java.head();
	java.tail();
	java.left();
	java.content();

	Python python;
	python.head();
	python.tail();
	python.left();
	python.content();
}

int main() {

	test();

	system("pause");
	return 0;
}