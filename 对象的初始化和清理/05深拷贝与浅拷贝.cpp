#include <iostream>
using namespace std;

//ǳ������������Ĭ�ϵĿ������캯����ĵȺŸ�ֵ����
//������Լ���д�������캯�����ڶ������ٿռ���и�ֵ

class Person
{
public:
	Person() {
		cout << "Person Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age, int H) {
		m_Age = age;
		m_H = new int(H);
		cout << "Person �вι��캯��" << endl;
	}

	Person(const Person& p) {
		m_Age = p.m_Age;
		//m_H = p.m_H; //������Ĭ�ϵĿ�������ǳ������ֱ�ӵȺŸ�ֵ����������������ʱ�������ڴ��ظ��ͷŵ�����
		m_H = new int(*p.m_H);	//�ڿ�����ʱ�򣬶��ڶ����ĳ�Ա���������ڶ�������һ��ռ���и�ֵ����������
		cout << "Person ���������ĵ���" << endl;
	}

	~Person() {
		//��������һ�������ͷ��ڴ濪���ڶ����ĳ�Ա����
		if (m_H != NULL) {
			delete m_H;
			m_H = NULL;
		}
		cout << "Person ������������" << endl;
	}

	int m_Age;
	int* m_H;

private:

};

void test() {
	Person p1(18,160);
	cout << "p1���䣺" << p1.m_Age << "  ��ߣ�" << *p1.m_H << endl;

	Person p2(p1);
	cout << "p2���䣺" << p2.m_Age << "  ��ߣ�" << *p2.m_H << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}