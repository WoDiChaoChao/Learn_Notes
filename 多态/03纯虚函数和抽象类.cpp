/*
��ʹ�ö�̬��ʱ��������Ҫ�ĸ��������еĺ����������еĺ���������ûʲô��
��ô���ǾͿ��԰��������д�ɳ�����

��˿��԰��麯��д�ɴ��麯��
���麯���﷨��virtual ����ֵ���� ������ (�����б�) = 0;

���������˴��麯���������Ҳ��Ϊ������

�������ص㣺
�޷�ʵ��������
���������д�������еĴ��麯��������Ҳ�ǳ����࣬�޷�ʵ��������

*/

#include <iostream>
using namespace std;

//������
class Base {
public:
	//���麯��
	virtual void func() = 0;
};

class Son : public Base {
public:
	virtual void func() {
		cout << "func�����ĵ���" << endl;
	}
};

void test01() {
	//Base base; //�������޷�ʵ��������
	Base* s = new Son;
	s->func();
}

int main() {
	test01();

	return 0;
}