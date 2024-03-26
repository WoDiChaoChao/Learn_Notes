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
	//�вι��캯��(һ�㹹�캯��)
	Person(int a) {
		cout << "Person �вι��캯��" << endl;
	}
	//�������캯��
	Person(const Person& p) {
		cout << "Person �������캯��" << endl;
	}
	//������ֵ����
	Person& operator= (const Person& p) {
		if (p._data == this->_data)
			return *this;
		this->_data = p._data;
		cout << "Person ������ֵ" << endl;
		return *this;
	}
	//�ƶ����캯��
	Person(Person&& other) {
		this->_data = other._data;
		cout << "Person �ƶ����캯��" << endl;
	}

	//�ƶ���ֵ����
	Person& operator=(Person&& other) {
		std::cout << "Person �ƶ���ֵ" << std::endl;
		this->_data = other._data;
		return *this;
	}

	~Person() {
		cout << "Person ���������ĵ���" << endl;
	}

	int _data;
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

	//4.���ø�ֵ���캯��
	Person p3;
	p3._data = 10;
	Person p4;
	p4 = p3;
	cout << p4._data << endl;

	//5.�����ƶ����캯��
	Person p5;
	p5._data = 10;
	Person p6 = std::move(p5);
	cout << p6._data << endl;
}	

int main() {

	test01();

	system("pause");
	return 0;
}