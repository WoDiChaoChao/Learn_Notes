#include <iostream>
using namespace std;

//Ĭ������£�C++�ڶ������ʱ�򣬻��Զ�������������
//1.Ĭ�Ϲ��캯����������Ϊ�գ�
//2.�вι��캯����������Ϊ�գ�
//3.�������캯�����Գ�Ա���Խ��п�����ֵ��

//���캯�����ù������£�
//1.���д���вι��캯��������Ա�Լ���д�޲ι��캯���Ļ��������������Զ������޲ι��캯����������ÿ������캯��
//2.���д�˿������캯��������Ա�Լ���д�޲ι��캯�����вι��캯���Ļ��������������Զ������޲ι��캯�����вι��캯��

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
	//��������
	~Person() {
		cout << "Person ���������ĵ���" << endl;
	}

	int m_Age;

private:
};

//void test01() {
//	//Person p; //�� "Person" ������Ĭ�Ϲ��캯��	
//
//	Person p1(10);
//	Person p2(p1);
//	cout << "p2������" << p2.m_Age << endl;
//}

void test02() {
	//�������д���ᱨ��
	/*Person p1;
	Person p2(10);*/
	
}

int main() {
	
	/*test01();*/
	system("pause");
	return 0;
}