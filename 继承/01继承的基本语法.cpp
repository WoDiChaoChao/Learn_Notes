#include <iostream>
using namespace std;

//�̳е��﷨
//class ���� : �̳з�ʽ ����

class BasePage
{
public:
	void head() {
		cout << "��ҳ�����������ѧϰ��Ƶ" << endl;
	}

	void tail() {
		cout << "�����ţ���������" << endl;
	}

	void left() {
		cout << "��๫�������ǩ" << endl;
	}

};

class Java : public BasePage
{
public:
	void content() {
		cout << "Javaѧϰ��Ƶ" << endl;
	}

private:

};

class Python : public BasePage
{
public:
	void content() {
		cout << "Pythonѧϰ��Ƶ" << endl;
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