#include <iostream>
using namespace std;

class Phone
{
public:
	Phone(string phone) {
		cout << "Phone ���캯���ĵ���" << endl;
		phone_name = phone;
	}
	~Phone() {
		cout << "Phone ���������ĵ���" << endl;
	}

	string phone_name;

private:

};

class Person
{
public:

	Person(string name, string phone):m_phone(phone)
		//�����������Ϊ��ʼ���б�Ĳ�������ʱ���ȴ�������Ķ����ٽ��и�ֵ���൱�� Phone m_phone = phone;
	{
		cout << "Person ���캯���ĵ���" << endl;
		m_name = name;
		//m_phone = phone; //������ֵ�Ǵ���ģ���Ϊ����û��string��Phone��ת��
	}

	~Person() {
		cout << "Person ���������ĵ���" << endl;
	}

	string m_name; //����
	Phone m_phone; //�ֻ�����  �������Ϊ���Ա

private:

};

void test() {
	Person p("����","HuaWei");
	cout << p.m_name << "����" << p.m_phone.phone_name << "�ֻ�" << endl;
}

//�������Ϊ���Աʱ�����ȴ������Ա���ٴ����������,��������ʱ�������෴

int main() {

	test();

	system("pause");
	return 0;
}