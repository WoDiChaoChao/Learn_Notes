#include <iostream>
using namespace std;

//����
//�вι��캯�� �޲ι��캯��
//Ĭ�Ϲ��캯�� �������캯��

class Person
{
//����
public:
	//�޲ι��캯��(Ĭ�Ϲ��캯��)
	Person() {
		cout << "Person �޲ι��캯��" << endl;
	}
	//�вι��캯��
	Person(int a) {
		cout << "Person �вι��캯��" << endl;
	}
	//�������캯��
	Person(const Person& p) {
		cout << "Person �������캯��" << endl;
	}
	~Person() {
		cout << "Person ���������ĵ���" << endl;
	}

private:

};

//����
void test01() {
	//1.���ŷ�
	//Person p1;	//�޲�/Ĭ�Ϲ��캯���ĵ���
	//Person p2(10); //�вι��캯���ĵ���
	//Person p3(p1); //�������캯���ĵ���

	//2.��ʾ��
	/*Person p2 = Person(10);
	Person p3 = Person(p2);*/

	//3.��ʽת����
	Person p1 = 10;
	Person p2 = p1;
}

int main() {

	test01();

	system("pause");
	return 0;
}