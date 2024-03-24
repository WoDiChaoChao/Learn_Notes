#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

std::mutex mtx;
int share_data = 0;

void use_unique_lock() {
	//unique_lock�ڹ��캯����ʱ���Զ������������������Զ���������Ҳ�����ֶ�����
	std::unique_lock<std::mutex> lock(mtx);
	std::cout << "lock success" << std::endl;
	share_data++;
	std::cout << "share_data is " << share_data << std::endl;
	lock.unlock();
}

void owns_lock() {
	std::unique_lock<std::mutex> lock(mtx);
	share_data++;
	if (lock.owns_lock()) {
		std::cout << "����ռ��" << std::endl;
	}
	else {
		std::cout << "��δ��ռ��" << std::endl;
	}

	lock.unlock();
	if (lock.owns_lock()) {
		std::cout << "����ռ��" << std::endl;
	}
	else {
		std::cout << "��δ��ռ��" << std::endl;
	}
}

void defer_lock() {
	//�ӳټ�����Ҫ���ݵڶ���������defer_lock
	//�ӳټ�������˼��һ��ʼ��������ʱ�򲻻�Ի��������м������������ߵ�}��ʱ��Ż���м���
	std::unique_lock<std::mutex> lock(mtx, std::defer_lock);

	//��������ߵ�}�ټ����Ļ������ֶ�����
	lock.lock();

	//Ҳ�����ֶ�����
	lock.unlock();
}

void use_own_defer_lock() {
	std::unique_lock<std::mutex> lock(mtx);

	if (lock.owns_lock()) {
		std::cout << "Main Thread has this lock" << std::endl;
	}
	else {
		std::cout << "Main Thread do not has this lock" << std::endl;
	}

	std::thread t([]() {
		std::unique_lock<std::mutex> lock(mtx,std::defer_lock);
		if (lock.owns_lock()) {
			std::cout << "Thread t has this lock" << std::endl;
		}
		else {
			std::cout << "Thread t do not has this lock" << std::endl;
		}

		//�ֶ�������������Ϊ���߳�û���ͷ����������ֶ�����������ִ��
		lock.lock();
		//����Ĵ���Ҳ����ִ��
		if (lock.owns_lock()) {
			std::cout << "Thread t has this lock" << std::endl;
		}
		else {
			std::cout << "Thread t do not has this lock" << std::endl;
		}
		lock.unlock();
		});
}

void use_own_adopt_lock() {
	//��������������ʼ������ʱ������ֶ�����
	//��Ϊ����������û�и�������������ֻ�ǵõ�����������Ȩ�����뿪�������ʱ����Զ��ͷ�����Ȩ
	mtx.lock();
	std::unique_lock<std::mutex> lock(mtx, std::adopt_lock);
	if (lock.owns_lock()) {
		std::cout << "owns lock" << std::endl;
	}
	else {
		std::cout << "no owns lock" << std::endl;
	}
	//�����ֶ�������Ҳ�������뿪�������ʱ���Զ��ͷ�����Ȩ
	//lock.unlock();
}

//������������
int a = 100;
int b = 200;
std::mutex mtx1;
std::mutex mtx2;
void safe_swap1() {
	std::lock(mtx1, mtx2);
	std::unique_lock<std::mutex> lock1(mtx1, std::adopt_lock);
	std::unique_lock<std::mutex> lock2(mtx2, std::adopt_lock);
	std::swap(a, b);

	//�����÷�
	/*
	һ��mutex��unique_lock����
	�������ͷŵĲ����ͽ���unique_lock��
	���ܵ���mutex�����ͽ�������Ϊ����ʹ��Ȩ�Ѿ�����unique_lock�ˡ�
	*/
	//mtx1.unlock();
	//mtx2.unlock();

	lock1.unlock();
	lock2.unlock();
}

void safe_swap2() {
	std::lock(mtx1, mtx2);
	std::unique_lock<std::mutex> lock1(mtx1, std::defer_lock);
	std::unique_lock<std::mutex> lock2(mtx2, std::defer_lock);
	std::swap(a, b);

	//�����÷�
	/*
	һ��mutex��unique_lock����
	�������ͷŵĲ����ͽ���unique_lock��
	���ܵ���mutex�����ͽ�������Ϊ����ʹ��Ȩ�Ѿ�����unique_lock�ˡ�
	*/
	//mtx1.unlock();
	//mtx2.unlock();

	lock1.unlock();
	lock2.unlock();
}

std::unique_lock<std::mutex> get_lock() {
	//mutex��֧�ֿ���������ƶ����죬����unique_lock֧���ƶ�����
	//��������unique_lock�󣬿���ͨ�����ؾֲ�����ķ�ʽ����ת�Ƹ��ⲿ������
	std::unique_lock<std::mutex> lock(mtx);
	return lock;
}

void use_return() {
	std::unique_lock<std::mutex> lock(get_lock());
}

//һ����������Ҫ�㹻�󣬿��Է�������������������
//һ����������ҲҪ�㹻С����ֹ�ǹ��������ݺͲ���ռ�������ͷ�
void precision_lock() {
	std::unique_lock<std::mutex> lock(mtx);
	share_data++;
	//�Թ��������ݲ����������ͷ���
	lock.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

class ShareLock {
public:
	ShareLock(){}
	//���ڶ�����������ʹ�ù���������ʹһ���߳�ռ�������������߳�Ҳ������ռ��
	//������������Ĺ����������ݣ����Կ���ʹ�ù�����
	void read() {
		std::shared_lock<std::shared_mutex> lock(s_mtx);
		//��ȡ���ݣ����ظ��û�
	}

	//����д��������Ҫʹ�ö�ռ����
	//д����ʹ��lock_guard��ֱ��д������ɣ��Զ��ͷ���
	void write() {
		std::lock_guard<std::mutex> lock(_mtx);
		//���������޸Ĳ���
	}

private:
	std::shared_mutex s_mtx;
	std::mutex _mtx;
};

int main() {
	
	//1. unique_lock�Ļ���ʹ��
	//use_unique_lock();

	//2. ͨ��owns_lock�ж��Ƿ������
	//owns_lock();

	//3. �ӳټ����Ļ���ʹ��
	//defer_lock();

	//4. owns_lock��defer_lock�Ľ��ʹ��
	// ��Ҫע����������
	//use_own_defer_lock();

	//5. unique_lockͬ��֧����������
	//use_own_adopt_lock();

	//6. unique_lockͬ��֧�ֽ�������
	//���������Ľ���
	safe_swap1();
	//7. �ӳټ����Ľ���
	safe_swap2();
	//8. ת�����Ĺ���Ȩ
	use_return();

	//9. �ѿغ���������
	precision_lock();

	//10. ������
	//ShareLock s;

	//11. �ݹ���
	//����ӿ�A�Թ��������������������Ҫ�ӿ�B�Թ�������������ʱ�����ʹ�õݹ���
	std::recursive_mutex re_mtx;
	std::lock_guard<std::recursive_mutex> lock(re_mtx);

	return 0;
}