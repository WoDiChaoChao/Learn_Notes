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
	//c1.num = 10; //class成员的默认权限是私有，因此类外访问不了

	C2 c2;
	c2.num = 10; //struct成员的默认权限是公共，因此类外可以访问

	return 0;
	system("pause");
}