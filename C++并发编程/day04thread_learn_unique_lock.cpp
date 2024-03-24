#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

std::mutex mtx;
int share_data = 0;

void use_unique_lock() {
	//unique_lock在构造函数的时候自动加锁，在析构函数自动解锁，但也可以手动解锁
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
		std::cout << "锁被占有" << std::endl;
	}
	else {
		std::cout << "锁未被占有" << std::endl;
	}

	lock.unlock();
	if (lock.owns_lock()) {
		std::cout << "锁被占有" << std::endl;
	}
	else {
		std::cout << "锁未被占有" << std::endl;
	}
}

void defer_lock() {
	//延迟加锁需要传递第二个参数，defer_lock
	//延迟加锁的意思是一开始创建锁的时候不会对互斥量进行加锁，而是在走到}的时候才会进行加锁
	std::unique_lock<std::mutex> lock(mtx, std::defer_lock);

	//如果不想走到}再加锁的话可以手动加锁
	lock.lock();

	//也可以手动解锁
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

		//手动加锁，但是因为主线程没有释放锁，这里手动加锁并不会执行
		lock.lock();
		//下面的代码也不会执行
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
	//利用领养操作初始化锁的时候必须手动加锁
	//因为领养操作并没有给互斥量加锁，只是得到了它的所属权，在离开作用域的时候会自动释放所属权
	mtx.lock();
	std::unique_lock<std::mutex> lock(mtx, std::adopt_lock);
	if (lock.owns_lock()) {
		std::cout << "owns lock" << std::endl;
	}
	else {
		std::cout << "no owns lock" << std::endl;
	}
	//可以手动解锁，也可以在离开作用域的时候自动释放所属权
	//lock.unlock();
}

//共享区的数据
int a = 100;
int b = 200;
std::mutex mtx1;
std::mutex mtx2;
void safe_swap1() {
	std::lock(mtx1, mtx2);
	std::unique_lock<std::mutex> lock1(mtx1, std::adopt_lock);
	std::unique_lock<std::mutex> lock2(mtx2, std::adopt_lock);
	std::swap(a, b);

	//错误用法
	/*
	一旦mutex被unique_lock管理，
	加锁和释放的操作就交给unique_lock，
	不能调用mutex加锁和解锁，因为锁的使用权已经交给unique_lock了。
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

	//错误用法
	/*
	一旦mutex被unique_lock管理，
	加锁和释放的操作就交给unique_lock，
	不能调用mutex加锁和解锁，因为锁的使用权已经交给unique_lock了。
	*/
	//mtx1.unlock();
	//mtx2.unlock();

	lock1.unlock();
	lock2.unlock();
}

std::unique_lock<std::mutex> get_lock() {
	//mutex不支持拷贝构造和移动构造，但是unique_lock支持移动构造
	//把锁交给unique_lock后，可以通过返回局部对象的方式将锁转移给外部调用者
	std::unique_lock<std::mutex> lock(mtx);
	return lock;
}

void use_return() {
	std::unique_lock<std::mutex> lock(get_lock());
}

//一个锁的粒度要足够大，可以访问整个共享区的数据
//一个锁的粒度也要足够小，防止非共享区数据和操作占有锁不释放
void precision_lock() {
	std::unique_lock<std::mutex> lock(mtx);
	share_data++;
	//对共享区数据操作完立马释放锁
	lock.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

class ShareLock {
public:
	ShareLock(){}
	//对于读操作，可以使用共享锁，即使一个线程占有了锁，其他线程也可以来占有
	//读操作不会更改共享区的数据，所以可以使用共享锁
	void read() {
		std::shared_lock<std::shared_mutex> lock(s_mtx);
		//读取数据，返回给用户
	}

	//对于写操作就需要使用独占锁了
	//写操作使用lock_guard，直到写操作完成，自动释放锁
	void write() {
		std::lock_guard<std::mutex> lock(_mtx);
		//进行数据修改操作
	}

private:
	std::shared_mutex s_mtx;
	std::mutex _mtx;
};

int main() {
	
	//1. unique_lock的基本使用
	//use_unique_lock();

	//2. 通过owns_lock判断是否持有锁
	//owns_lock();

	//3. 延迟加锁的基本使用
	//defer_lock();

	//4. owns_lock和defer_lock的结合使用
	// 主要注意死锁问题
	//use_own_defer_lock();

	//5. unique_lock同样支持领养操作
	//use_own_adopt_lock();

	//6. unique_lock同样支持交换操作
	//领养操作的交换
	safe_swap1();
	//7. 延迟加锁的交换
	safe_swap2();
	//8. 转移锁的归属权
	use_return();

	//9. 把控好锁的粒度
	precision_lock();

	//10. 共享锁
	//ShareLock s;

	//11. 递归锁
	//如果接口A对共享区加锁，在设计上又要接口B对共享区加锁，这时候可以使用递归锁
	std::recursive_mutex re_mtx;
	std::lock_guard<std::recursive_mutex> lock(re_mtx);

	return 0;
}