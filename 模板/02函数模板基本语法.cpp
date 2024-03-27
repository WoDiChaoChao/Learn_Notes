#include <iostream>

/*
�﷨��
template<typename T>
template --- ��������ģ��
typename --- 
*/

//�������ͽ����ĺ���
void swapInt(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

//���������ͽ����ĺ���
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	std::cout << "a=" << a << "b=" << b << std::endl;
	swapInt(a, b);
	std::cout << "a=" << a << "b=" << b << std::endl;
}

//����ģ��
template<typename T> //����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����,T��һ��ͨ����������
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test02() {
	int a = 10;
	int b = 20;
	std::cout << "a = " << a << " b = " << b << std::endl;
	//���ú���ģ����н���
	//����ģ�������ʹ�÷�ʽ
	//1. �����Զ��Ƶ�
	//mySwap(a, b); 
	//2. ��ʾָ����������
	mySwap<int>(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;
	
}

int main() {
	//test01();
	test02();
	return 0;
}