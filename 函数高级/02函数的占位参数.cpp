#include <iostream>
using namespace std;

//������ռλ����
//�﷨����������ֵ���� ������ (��������){}

void func1(int) {
	cout << "hello world" << endl;
}

//ռλ����Ҳ������Ĭ��ֵ
void func2(int = 10) {
	cout << "hello world" << endl;
}

int main() {

	func1(10);
	func2();
	system("pause");
	return 0;
}