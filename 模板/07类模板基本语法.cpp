#include <iostream>
#include <string>

//��ģ��
//��ģ��ͺ���ģ����﷨�ǳ����ƣ���template����д��Ϳ�����
template<typename NameT, typename AgeT>
class Person {
public:

	Person(NameT name, AgeT age) {
		this->_name = name;
		this->_age = age;
	}

	void show() {
		std::cout << "name��" << _name << " age��" << _age << std::endl;
	}

	NameT _name;
	AgeT _age;
};

void test01() {
	Person<std::string, int> p1("�����", 999);
	p1.show();
}

int main() {
	test01();

	return 0;
}