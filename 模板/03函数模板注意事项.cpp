#include <iostream>

/*
ע�����
	�Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
	ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
*/

template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//�Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
	//��ȷ�� mySwap(a, b);
	//���� mySwap(a, c);
	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
}

template<typename T>
void func() {
	std::cout << "func ����" << std::endl;
}

void test02() {
	//ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
	//����func();
	//��ȷ��func<int>();
}

int main() {

	return 0;
}