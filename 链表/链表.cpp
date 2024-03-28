#include <iostream>

typedef struct ListNode {
	int elem;
	struct ListNode* next;
}node,*LinkList;

//初始化头节点
LinkList Init() {

	node* head = new node;
	if (head == nullptr) {
		std::cout << "初始化头节点失败" << std::endl;
		return nullptr;
	}
	head->next = nullptr;
	return head;
}

//头插法添加元素
void head_insert(LinkList& head, int value) {
	node* new_node = new node;
	new_node->elem = value;
	new_node->next = nullptr;

	new_node->next = head->next;
	head->next = new_node;
}

//尾插法添加元素
void tail_insert(LinkList& head, int value) {
	node* r = head;
	while (r->next) {
		r = r->next;
	}
	node* new_node = new node;
	new_node->elem = value;

	r->next = new_node;
	new_node->next = nullptr;
}

//在指定元素后面插入
node* find(LinkList head, int value) {
	node* p = head->next;
	while (p && p->elem != value) {
		p = p->next;
	}
	if (p == nullptr) {
		return nullptr;
	}
	return p;
}

void mid_insert(LinkList& head, int value, int x) {
	node* q = find(head, value);
	if (q == nullptr) {
		std::cout << "没有此元素" << std::endl;
		return;
	}
	node* new_node = new node;
	new_node->elem = x;
	new_node->next = nullptr;

	new_node->next = q->next;
	q->next = new_node;
	
}

//在指定位置插入
void index_insert(LinkList& head, int index, int value) {
	node* p = head;
	int cnt = 0;
	while (p && cnt < index - 1) {
		p = p->next;
		cnt++;
	}
	node* new_node = new node;
	new_node->elem = value;
	new_node->next = nullptr;

	new_node->next = p->next;
	p->next = new_node;
}

//删除元素k
void del(LinkList& head, int value) {
	node* index = find(head, value);
	if (index == nullptr) {
		std::cout << "没有此元素" << std::endl;
		return;
	}

	node* p = head;
	while (p && p->next != index) {
		p = p->next;
	}

	p->next = index->next;
	delete index;

}

void show(LinkList head) {
	node* p = head->next;
	while (p) {
		std::cout << p->elem << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

int main() {
	LinkList head = Init();
	
	tail_insert(head, 1);
	head_insert(head, 2);
	show(head);
	
	mid_insert(head, 3,4);
	show(head);
	tail_insert(head, 3);
	mid_insert(head, 3, 4);
	show(head);
	
	index_insert(head, 1, 0);
	show(head);
	del(head, 5);
	del(head, 0);
	show(head);
	
	return 0;
}