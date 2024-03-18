#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age) {
		m_A = new int(age);
	}

	~Person() {
		if (m_A != nullptr) {
			delete m_A;
			m_A = nullptr;
		}
	}

	Person& operator=(Person& p) {

		if (this->m_A != nullptr) {
			delete this->m_A;
			m_A  = nullptr;
		}

		m_A = new int(*p.m_A);

		return *this;
	}

	int* m_A;
private:

};

void test() {
	Person p(10);

	Person p2(20);

	Person p3(30);
	p3 = p2 = p;
	cout << "p.m_A=" << *p.m_A << endl;
	cout << "p2.m_A=" << *p2.m_A << endl;
	cout << "p3.m_A=" << *p3.m_A << endl;
}

int main() {
	test();

	system("pause");
	return 0;
}