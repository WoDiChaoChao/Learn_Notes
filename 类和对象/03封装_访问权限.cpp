#include <iostream>
using namespace std;

//����Ȩ��
//����Ȩ�� public  ���ڿ��Է��ʣ�������Է���
//˽��Ȩ�� private ���ڿ��Է��ʣ����ⲻ���Է���     ������Լ̳и����˽��Ȩ�޵ĳ�Ա
//����Ȩ�� protected ���ڿ��Է��ʣ����ⲻ���Է���   ���಻���Լ̳и��ౣ��Ȩ�޵ĳ�Ա

class Person
{
//����Ȩ��
public:
	string name = "����";
//˽��Ȩ��
private:
	string car = "���ǵ�";
//����Ȩ��
protected:
	int password = 123456;

public:
	//����Ȩ�޵ĳ�Ա�����ڶ����Է��ʣ����������ᱨ��
	void test() {
		name = "lina";
		car = "������";
		password = 11111;
	}
};


int main() {

	//ʵ����
	Person P1;
	
	P1.name = "����"; //����Ȩ�޵ĳ�Ա������Է��ʡ�
	//P1.car = "����";//˽��Ȩ�޵ĳ�Ա���ⲻ���Է���
	//P1.password = 666666; //����Ȩ�޵ĳ�Ա���ⲻ���Է���

	system("pause");
	return 0;
}