#include <iostream>
using namespace std;

//һ�㶼�Ὣ��Ա��������Ϊ˽�У�Ȼ��ͨ�������ĳ�Ա�������Գ�Ա���Խ��ж�д�Ĳ���
//�ŵ�1�������Լ����Ƴ�Ա���ԵĶ�д����
//�ŵ�2�����Լ���Ա���Ե���Ч��

class Person
{
public:
	//��������
	void setName(string str) {
		m_Name = str;
	}
	//��ȡ����
	string getName() {
		return m_Name;
	}
	//��������
	void setAge(int age) {
		m_Age = 0;
		if (age < 0 || age>100) {
			cout << "��������" << endl;
			return;
		}
		m_Age = age;
	}
	//��ȡ����
	int getAge() {
		return m_Age;
	}
	//��������
	void setLover(string str) {
		m_Lover = str;
	}

	void show() {
		cout << "������" << m_Name << endl << "���䣺" << m_Age << endl << "���ˣ�" << m_Lover << endl;
	}

private:
	string m_Name;//���� �ɶ���д
	int m_Age; //���� �ɶ���д��д��ʱ�����Ч��(0-100)
	string m_Lover; //���� ��д
};


int main() {

	Person P1;
	P1.setName("����");
	cout << "������" << P1.getName() << endl;
	P1.setAge(10);
	cout << "���䣺" << P1.getAge() << endl;
	P1.setLover("�Ծ�");


	system("pause");
	return 0;
}