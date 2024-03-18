/*
开发的原则：对拓展进行开放，对修改进行关闭

利用多态：利于维护，代码组织结构强

*/

#include <iostream>
using namespace std;

class AbstractCalculator {
public:
	virtual int GetResult() {
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

class AddCalculator : public AbstractCalculator {
public:
	int GetResult() {
		return m_Num1 + m_Num2;
	}
};

class SubCalculator : public AbstractCalculator {
public:
	int GetResult() {
		return m_Num1 - m_Num2;
	}
};

class MulCalculator : public AbstractCalculator {
public:
	int GetResult() {
		return m_Num1 * m_Num2;
	}
};

void test01() {
	AbstractCalculator* x = new AddCalculator;;
	x->m_Num1 = 100;
	x->m_Num2 = 100;

	cout << x->m_Num1 << "+" << x->m_Num2 << "=" << x->GetResult() << endl;
	delete x;

	x = new SubCalculator;
	x->m_Num1 = 100;
	x->m_Num2 = 100;
	cout << x->m_Num1 << "-" << x->m_Num2 << "=" << x->GetResult() << endl;
	delete x;

	x = new MulCalculator;
	x->m_Num1 = 100;
	x->m_Num2 = 100;
	cout << x->m_Num1 << "*" << x->m_Num2 << "=" << x->GetResult() << endl;
	delete x;
}

int main() {
	test01();

	return 0;
}