/*

��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷŵ�ʱ���޷������������������
��ν�����Ѹ������������д��������������������������
ע��
	�����������ʹ���������������Ҫдʵ�֣�����ֻд����
	���д�˴���������������ô�����Ҳ�ͳ��˳�����
*/
#include <iostream>
using namespace std;

class Animal {
public:
	Animal();
	//�Ѹ������������д������������
	//virtual ~Animal();
	//�Ѹ������������д�ɴ�����������
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};

Animal::Animal() {
	cout << "Animal���캯��" << endl;

}

Animal::~Animal() {
	cout << "Animal������������" << endl;
}

class Cat :public Animal {
public:
	Cat(string name);
	~Cat();
	virtual void speak() {
		cout << *m_name<<"Сè��˵��" << endl;
	}

	string* m_name;
};

Cat::Cat(string name) {
	cout << "Cat���캯����ʹ��" << endl;
	m_name = new string(name);
}
Cat::~Cat() {
	if (m_name != NULL) {
		cout << "Cat������������" << endl;
		delete m_name;
	}
}

void test01(){
	Animal* animal = new Cat("Tom");
	animal->speak();
	//����ָ�����ͷŵ�ʱ���޷������������������
	delete animal;
}

int main() {
	test01();
	return 0;
}