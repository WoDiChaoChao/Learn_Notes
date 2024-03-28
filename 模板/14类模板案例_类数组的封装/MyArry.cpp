#include <iostream>
#include "MyArry.hpp"

void test01() {

	MyArray<int> arr1(10);
	MyArray<int> arr2(arr1);

	MyArray<int> arr3(100);
	arr3 = arr1;
}

void printInt(MyArray<int>& arr) {
	for (int i = 0; i < arr.get_Size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout<<std::endl;
}

void test02() {
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.Push_Back(i);
	}
	printInt(arr1);
	arr1.Pop_Back();
	printInt(arr1);
	std::cout << arr1.get_Capacity() << std::endl;
	std::cout << arr1.get_Size() << std::endl;
}

class Person {
public:

	Person() {};

	Person(std::string name, int age) {
		m_name = name;
		m_age = age;
	}
	
	std::string m_name;
	int m_age;
};

void printPerson(MyArray<Person>& arr) {
	for (int i = 0; i < arr.get_Size(); i++) {
		std::cout << "姓名：" << arr[i].m_name << "  " << "年龄：" << arr[i].m_age << std::endl;
	}
}

void test03() {
	MyArray<Person> arr(5);
	Person p1("张三", 15);
	Person p2("李四", 20);
	Person p3("王五", 25);
	Person p4("赵四", 30);
	Person p5("校长", 35);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	printPerson(arr);
	arr.Pop_Back();
	printPerson(arr);
	std::cout << arr.get_Capacity() << std::endl;
	std::cout << arr.get_Size() << std::endl;

}

int main() {
	//test01();
	//test02();
	test03();
	return 0;
}