#include <iostream>

//��ģ��ĳ�Ա��������ʱ��
//��ģ���Ա�����ڶ����ʱ�򲻻ᴴ�����������ͨ��
//ֻ����ȷ��ģ������б�����ͺ󣬲Żᱻ����

class Person1 {
public:
	void showPerson1() {
		std::cout << "Person1 show" << std::endl;
	}
};

class Person2 {
public:
	void showPerson2() {
		std::cout << "Person2 show" << std::endl;
	}
};

template<typename T>
class MyClass {
public:
	T obj;
	
	void f1(){
		obj.showPerson1();
	}
	
	void f2(){
		obj.showPerson2();
	}
};

//���ϴ�����Ա���ͨ������Ϊ����������֪����ģ���в����б��е�ȷ������

void test01(){
	MyClass<Person1> m;
	//��ȷ����ģ������б���ٵ��ó�Ա��������ʱ��Ա�����Żᱻ����
	m.f1();
	//m.f2();
}

int main() {
	test01();

	return 0;
}

