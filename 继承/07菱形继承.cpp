#include <iostream>
using namespace std;

class Animal
{
public:
	int m_A;
};

//������μ̳еķ������ڼ̳з�ʽǰ����virtual�ؼ���
//ʹ�����м̳е�������ָ�룬����ƫ���������ʸ����Ա
//����ֱ�ӷ��ʼȲ���������飬Ҳ���������Դ�˷�
class sheep : virtual public Animal
{
public:
	
};

class Tuo : virtual public Animal
{
public:
	
};

class sheepTuo : public sheep, public Tuo
{
public:
	
};

void test() {
	sheepTuo s;
	//���μ̳е����⣺��������飬���һ������Դ�˷�
	//�ڴ����У�s���ʵ�m_A��sheep�к���Tuo�ж��У���������ֱ�ӷ��ʻ�������飬���������Դ�˷�
	//s.m_A;

	
}

int main() {


	system("pause");
	return 0;
}