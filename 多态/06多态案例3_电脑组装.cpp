#include <iostream>
using namespace std;

class CPU {
public:
	virtual void calculate() = 0;
};

class VideoCard {
public:
	virtual void display() = 0;
};

class Memeroy {
public:
	virtual void sortage() = 0;
};

class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memeroy* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	~Computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}

	void work() {
		m_cpu->calculate();
		m_vc->display();
		m_mem->sortage();
	}

private:
	CPU* m_cpu; //CPU零件指针
	VideoCard* m_vc; //显卡的零件指针
	Memeroy* m_mem; //内存条的零件指针
};



class InterCPU : public CPU {
public:
	void calculate() {
		cout << "InterCpu" << endl;
	}
};

class InterVideoCard : public VideoCard {
public:
	void display() {
		cout << "Inter显卡" << endl;
	}
};

class InterMemory : public Memeroy {
public:
	void sortage() {
		cout << "Inter内存条" << endl;
	}
};



class LenvnoCPU : public CPU {
public:
	void calculate() {
		cout << "LenvnoCpu" << endl;
	}
};

class LenvnoVideoCard : public VideoCard {
public:
	void display() {
		cout << "Lenvno显卡" << endl;
	}
};

class LenvnoMemory : public Memeroy {
public:
	void sortage() {
		cout << "Lenvno内存条" << endl;
	}
};

void test01(){
	CPU * I_cpu = new InterCPU;
	VideoCard* I_vc = new InterVideoCard;
	Memeroy* I_mem = new InterMemory;

	Computer c1(I_cpu, I_vc, I_mem);
	c1.work();

	I_cpu = new LenvnoCPU;
	I_vc = new LenvnoVideoCard;
	I_mem = new LenvnoMemory;

	Computer c2(I_cpu, I_vc, I_mem);
	c2.work();
}

int main() {
	test01();

	return 0;
}