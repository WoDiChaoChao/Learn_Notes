#include <iostream>
#include <string>

//����ģ�����ģ�������

//��ģ�������Ĭ�ϳ�ʼ���б����������ģ��û��
template<typename NameT, typename AgeT = int>
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
	//��ģ����û�������Զ��Ƶ���ֻ���Զ���ǿ������
	//����Person p("�����", 999);
	Person<std::string, int> p1("�����", 999);
	p1.show();
}

void test02() {
	//����ģ����Ĭ�ϳ�ʼ���б������ʱ�򣬿��Ժ��Բ����Ĵ���
	Person<std::string> p1("��˽�", 1000);
	p1.show();
}

int main() {
	//test01();
	test02();
	return 0;
}