#include <iostream>
using namespace std;


class Person
{
public:
	//�޲ι��캯��(Ĭ�Ϲ��캯��)
	Person() {
		cout << "Person �޲ι��캯��" << endl;
	}
	//�вι��캯��
	Person(int a) {
		m_Age = a;
		cout << "Person �вι��캯��" << endl;
	}
	//�������캯��
	Person(const Person& p) {
		m_Age = p.m_Age;
		cout << "Person �������캯��" << endl;
	}
	~Person() {
		cout << "Person ���������ĵ���" << endl;
	}

	int m_Age;

private:
};

//����
//1.����һ�������õĶ���������һ���¶���
void test01() {
	Person p1;
	p1.m_Age = 10;
	Person p2(p1);
	cout << "p2�����䣺" << p2.m_Age << endl;
}

//2.���ú���������ֵ���ݷ�ʽ�����ÿ������캯��
void test02(Person p) {

}

//3.���ú�������ֵ�����ÿ������캯��
Person dowork() {
	Person p;
	return p;
}

void test03() {
	Person p = dowork();	//VS�߰汾�н����˷���ֵ�Ż������ﲻ����ÿ������캯��
}

int main() {

	//test01();
	/*Person p;
	test02(p);
	*/
	test03();
	system("pause");
	return 0;
}