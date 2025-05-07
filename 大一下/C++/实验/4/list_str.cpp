#include "list_str.h"

// 加密算法（异或）
void security::encry_str(str_list& list)
{
	str_node* tmp = list.head->next;
	while (tmp) {
		for (int i = 0; i < tmp->value.size(); i++) {
			tmp->value[i] ^= key[i % key.size()];
		}
		tmp = tmp->next;
	}
	// 记录状态
	list.codeStatus = true;
}

// 解密算法（异或）
void security::decry_str(str_list& list)
{
	str_node* tmp = list.head->next;
	while (tmp) {
		for (int i = 0; i < tmp->value.size(); i++) {
			tmp->value[i] ^= key[i % key.size()];
		}
		tmp = tmp->next;
	}
	// 记录状态
	list.codeStatus = false;
}

// 结点构造函数
str_node::str_node(const string& s)
{
	this->value = s;
	this->next = NULL;
}

// 链表构造函数
str_list::str_list()
{
	head = new str_node;
}

// 链表析构函数
str_list::~str_list()
{
	// 手动释放内存（每个结点都要释放）
	while (head) {
		str_node* tmp = head->next;
		delete head;
		head = tmp;
	}
}

// 添加结点
bool str_list::insert(str_node& node)
{
	// 空字符串则添加失败
	if (node.value == "")return false;

	// 深拷贝
	str_node* tmp = new str_node;
	tmp->value = node.value;
	tmp->next = NULL;

	// 添加
	str_node* h_tmp = head;
	while (h_tmp->next) {
		h_tmp = h_tmp->next;
	}
	h_tmp->next = tmp;
}

// 打印明文
void str_list::printStr()
{
	// 密文状态
	if (this->codeStatus) {
		cout << "当前内容为密文，请先进行解密操作（decry）" << endl;
		return;
	}

	// 头结点为空，从第二个结点输出
	str_node* tmp = head->next;
	while (tmp) {
		cout << tmp->value << "  ";
		tmp = tmp->next;
	}
	cout << endl;
}

// 打印密文
void str_list::printCode()
{
	// 明文状态
	if (!this->codeStatus) {
		cout << "当前内容为明文，请先进行加密操作（encry）" << endl;
		return;
	}

	// 头结点为空，从第二个结点输出
	str_node* tmp = head->next;
	while (tmp) {
		// 16进制输出
		for (int i = 0; i < tmp->value.size(); i++) {
			cout.fill(0);
			cout.width(2);
			cout << hex << (int)(tmp->value[i]);
		}
		cout << "  ";
		tmp = tmp->next;
	}
	cout << endl;
}
