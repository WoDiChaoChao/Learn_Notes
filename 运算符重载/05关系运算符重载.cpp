#include <iostream>
using namespace std;

class Person
{
public:
	
	Person(string name, int age) {
		m_name = name;
		m_age = age;
	}

	bool operator==(Person& p) {
		if (this->m_name == p.m_name && this->m_age == p.m_age) {
			return true;
		}
		return false;
	}

	string m_name;
	int m_age;
private:

};

void test() {
	Person p1("Tom", 23);
	Person p2("Tom", 23);

	if (p1 == p2) {
		cout << "p1和p2相等" << endl;
	}
	else {
		cout << "p1和p2不相等" << endl;
	}
}

int main() {

	test();

	system("pause");
	return 0;
}