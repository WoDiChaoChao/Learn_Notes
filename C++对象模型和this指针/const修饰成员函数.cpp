#include <iostream>
using namespace std;

//const���γ�Ա����

class Person
{
public:
	
	//����ͨ�����¿����޸ĳ�Ա���Ե�ֵ
	void func1() {
		m_A = 100;
	}

	//const���εĺ����������޸ĳ�Ա���Ե�ֵ
	//ÿ����Ա�����ж���Ĭ�ϴ���thisָ��
	//������
	void func2()const {
		
		//thisָ�뱾������һ��ָ�볣�� Person * const this; �����Ը���thisָ���ָ��
		//this = nullptr;
		//const���γ�Ա���� �������� const Person* const this; �����Ը���thisָ��ָ������ֵ
		//this->m_A = 100;

		m_B = 100;
	}

	int m_A;
	mutable int m_B; //����mutable�ؼ��ֿ����ڳ��������޸ĳ�Ա���Ե�ֵ
private:

};

//������
void test() {
	const Person p1;
	//p1.m_A = 100; //������Ҳ�������޸ĳ�Ա���ԣ�
	//ԭ������Ϊ p1��thisָ��ָ������ݣ�ǰ�����const,const Person* const this;�����Ը���thisָ��ָ������ֵ

	p1.m_B = 100;//����mutable�ؼ��ֿ����ڳ��������޸ĳ�Ա���Ե�ֵ

	//������ֻ�ܵ��ó�����
	//p1.func1();
	p1.func2();  
}

int main() {


	system("pause");
	return 0;
}