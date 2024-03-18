#include <iostream>
using namespace std;


class Person
{
public:
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {

	}
	int m_A;
	int m_B;
	int m_C;

private:

};



int main() {

	Person P(10, 20, 30);
	cout << "m_A:" << P.m_A << "m_B:" << P.m_B << "m_C:" << P.m_C << endl;

	system("pause");
	return 0;
}