#include <iostream>
using namespace std;

class MyIntager
{
	friend ostream& operator<<(ostream& cout,const MyIntager& myint);
public:
	MyIntager() {
		m_A = 0;
	}
	
	//ǰ��++���������
	MyIntager& operator++() {
		//��++;
		m_A++;
		//�ٷ��ؽ��
		return *this;
	}

	//����++���������
	MyIntager operator++(int dumpy) {
		//��ʱ��������
		MyIntager temp = *this;
		//��++
		m_A++;
		//������ʱ����
		return temp;
	}

private:
	int m_A;
};

ostream& operator<<(ostream& cout, const MyIntager& myint) {
	cout << myint.m_A;
	return cout;
}

void test01() {
	MyIntager myint;
	cout << ++myint << endl;
}

void test02() {
	MyIntager myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}