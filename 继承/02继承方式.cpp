#include <iostream>
using namespace std;

//�̳з�ʽ
//public protected private

class BasePage
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//�����̳�
class Son1 :public BasePage {
public:
	void func() {
		m_A = 100; //�����̳У����๫����Ա��Ϊ����Ĺ�����Ա
		m_B = 100; //�����̳У����ౣ����Ա��Ϊ����ı�����Ա
		//m_C = 100; //�����̳У������˽�г�Ա�����Է���
	}
};

//�����̳�
class Son2 :protected BasePage {
public:
	void func() {
		m_A = 100; //�����̳У����๫����Ա��Ϊ����ı�����Ա
		m_B = 100; //�����̳У����ౣ����Ա��Ϊ����ı�����Ա
		//m_C = 100; //�����̳У������˽�г�Ա�����Է���
	}
};

//˽�м̳�
class Son3 :private BasePage {
public:
	void func() {
		m_A = 100; //˽�м̳У����๫����Ա��Ϊ�����˽�г�Ա
		m_B = 100; //˽�м̳У����ౣ����Ա��Ϊ�����˽�г�Ա
		//m_C = 100; //˽�м̳У������˽�г�Ա�����Է���
	}
};

//�����̳в��Դ���
void test02() {
	Son2 s1;
	//s1.m_A = 100;  ////�����̳У����๫����Ա��Ϊ����ı�����Ա
	//s1.m_B = 100; ////�����̳У����ౣ����Ա��Ϊ����ı�����Ա
}

//�����̳в��Դ���
void test01() {
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100; ////�����̳У����ౣ����Ա��Ϊ����ı�����Ա
}

//˽�м̳в��Դ���
void test03() {
	Son3 s1;
	//s1.m_A = 100;//˽�м̳У����ౣ����Ա��Ϊ�����˽�г�Ա
	//s1.m_B = 100; ////˽�м̳У����ౣ����Ա��Ϊ�����˽�г�Ա
}

int main() {

	test();

	system("pause");
	return 0;
}