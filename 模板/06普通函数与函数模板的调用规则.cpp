#include <iostream>

void Myfunc(int a, int b) {
	std::cout << "��ͨ�����ĵ���" << std::endl;
}

template<typename T>
void Myfunc(T a, T b) {
	std::cout << "����ģ��ĵ���" << std::endl;
}

template<typename T>
void Myfunc(T a, T b, T c) {
	std::cout << "����ģ�����صĵ���" << std::endl;
}

void test01() {
	int a = 10;
	int b = 20;
	int c = 30;
	//��ͨ�����ͺ���ģ��ͬʱ����ʱ���ȵ�����ͨ����
	Myfunc(a, b);

	//����ʹ�ÿ�ģ������б���ǿ�Ƶ��ú���ģ��
	Myfunc<>(a, b);

	//����ģ��Ҳ���Է�������
	Myfunc(a, b, c);

	//�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	char x = 'x', y = 'y';
	//��ͨ������Ҫchar��int����ʽת��������ģ�岻�ã����ȵ��ú���ģ��
	Myfunc(x, y);
}

int main() {
	test01();

	return 0;
}