#include <iostream>

template<typename T>
class Base {
	T m;
};

//����̳и���ģ���ʱ����Ҫָ�������ģ������б�ľ�������
//class Son1 : public Base	//����
class Son1 : public Base<int>	//��ȷ
{

};

//���������Ҫ���ָ�������ģ������б�ľ������ͣ���ô����Ҳ��Ҫ��Ϊ��ģ��
template<typename T>
class Son2 : public Base<T>	//��ȷ
{
public:
	Son2() {
		std::cout << "T������Ϊ��" << typeid(T).name() << std::endl;
	}
	int m;
};

void test01() {
	//����������ָ�������ģ������б�ľ�������
	Son2<int> s;
}

int main() {
	test01();

	return 0;
}