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
		cout << "ÖóÅ©·òÉ½Èª" << endl;
	}
	virtual void Brew() {
		cout << "³åÅÝ¿§·È" << endl;
	}
	virtual void PourIntoCup() {
		cout << "µ¹Èë±­ÖÐ" << endl;
	}
	virtual void PutSomething() {
		cout << "·ÅÈëÌÇºÍÅ£ÄÌ" << endl;
	}
};

class Tea : public AbstractDrink {
	virtual void Boil() {
		cout << "Öó¿óÈªË®" << endl;
	}
	virtual void Brew() {
		cout << "³åÅÝ²èÒ¶" << endl;
	}
	virtual void PourIntoCup() {
		cout << "µ¹Èë±­ÖÐ" << endl;
	}
	virtual void PutSomething() {
		cout << "·ÅÈëÄûÃÊ" << endl;
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