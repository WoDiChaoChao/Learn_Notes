#include <iostream>

/*
��ͨ�����ͺ���ģ�������
	��ͨ�������Խ�����ʽ����ת��
	����ģ�����Զ������Ƶ���ʱ�򲻻������ʽ����ת��������ʽָ���������͵�ʱ��������ʽ����ת��
*/

int Add01(int a, int b) {
	return a + b;
}

template<typename T>
T Add02(T a, T b) {
	return a + b;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//std::cout << Add01(a, b) << std::endl;
	//��ͨ�������Խ�����ʽ����ת��
	std::cout << Add01(a, c) << std::endl;
	//�Զ������Ƶ���ʱ�򲻻������ʽ����ת��
	//����std::cout << Add02(a, c) << std::endl;
	//��ʽָ���������͵�ʱ��������ʽ����ת��
	//��ȷ��
	std::cout << Add02<int>(a, c) << std::endl;
}

int main() {
	test01();

	return 0;
}