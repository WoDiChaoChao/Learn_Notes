#include <iostream>
using namespace std;

class AbstractDrink {
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void PourIntoCup() = 0;
	virtual void PutSomething() = 0;

	void makeDrink() {
		Boil();
		Brew();
		PourIntoCup();
		PutSomething();
	}
};

class Coffice : public AbstractDrink {
	virtual void Boil() {
		cout << "��ũ��ɽȪ" << endl;
	}
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	}
	virtual void PourIntoCup() {
		cout << "���뱭��" << endl;
	}
	virtual void PutSomething() {
		cout << "�����Ǻ�ţ��" << endl;
	}
};

class Tea : public AbstractDrink {
	virtual void Boil() {
		cout << "���Ȫˮ" << endl;
	}
	virtual void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	}
	virtual void PourIntoCup() {
		cout << "���뱭��" << endl;
	}
	virtual void PutSomething() {
		cout << "��������" << endl;
	}
};

void doWork(AbstractDrink* abs) {
	abs->makeDrink();
	delete abs;
}

void test01() {
	doWork(new Coffice);
	cout << "--------------------------" << endl;
	doWork(new Tea);
}

int main() {
	test01();
	return 0;
}