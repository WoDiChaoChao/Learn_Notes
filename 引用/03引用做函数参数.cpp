#include <iostream>
using namespace std;

void Myswap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {

	int a = 10, b = 20;

	Myswap(a, b);

	cout << "a=" << a << " " << "b=" << b << endl;

	system("pause");
	return 0;
}