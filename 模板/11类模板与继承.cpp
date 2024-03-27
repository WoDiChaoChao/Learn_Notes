#include <iostream>

template<typename T>
class Base {
	T m;
};

//子类继承父类模板的时候，需要指明父类的模板参数列表的具体类型
//class Son1 : public Base	//错误
class Son1 : public Base<int>	//正确
{

};

//如果子类想要灵活指定父类的模板参数列表的具体类型，那么子类也需要变为类模板
template<typename T>
class Son2 : public Base<T>	//正确
{
public:
	Son2() {
		std::cout << "T的类型为：" << typeid(T).name() << std::endl;
	}
	int m;
};

void test01() {
	//子类可以灵活指定父类的模板参数列表的具体类型
	Son2<int> s;
}

int main() {
	test01();

	return 0;
}