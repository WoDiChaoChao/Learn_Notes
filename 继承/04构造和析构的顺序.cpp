#include <iostream>
using namespace std;

//�̳з�ʽ
//public protected private

class BasePage
{
public:
	BasePage() {
		cout << "���๹�캯��" << endl;
	}
	~BasePage() {
		cout << "������������" << endl;
	}
};

class base : public BasePage {
public:
	base() {
		cout << "���๹�캯��" << endl;
	}

	~base() {
		cout << "������������" << endl;
	}

};

void test() {
	//�����ȹ��츸�࣬�ڹ�������
	//�������������࣬����������
	base b;
}

int main() {

	test();

	system("pause");
	return 0;
}