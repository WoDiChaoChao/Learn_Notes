#include <iostream>
using namespace std;

//�̳з�ʽ
//public protected private

class BasePage
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class base : public BasePage {
public:
	int m_D;
};

void test() {
	base b;
	//16 �����ĸ�int ����һ��int
	//�����е�˽�г�ԱҲ��̳У����Ƿ��ʲ���
	cout << "size of b is " << sizeof(b) << endl;
}

int main() {

	test();

	system("pause");
	return 0;
}