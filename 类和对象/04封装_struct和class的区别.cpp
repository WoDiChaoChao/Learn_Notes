#include <iostream>
using namespace std;

class C1 {
	int num;
};

struct C2 {
	int num;
};

int main() {

	C1 c1;
	//c1.num = 10; //class��Ա��Ĭ��Ȩ����˽�У����������ʲ���

	C2 c2;
	c2.num = 10; //struct��Ա��Ĭ��Ȩ���ǹ��������������Է���

	return 0;
	system("pause");
}