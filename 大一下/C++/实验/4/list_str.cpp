#include "list_str.h"

// �����㷨�����
void security::encry_str(str_list& list)
{
	str_node* tmp = list.head->next;
	while (tmp) {
		for (int i = 0; i < tmp->value.size(); i++) {
			tmp->value[i] ^= key[i % key.size()];
		}
		tmp = tmp->next;
	}
	// ��¼״̬
	list.codeStatus = true;
}

// �����㷨�����
void security::decry_str(str_list& list)
{
	str_node* tmp = list.head->next;
	while (tmp) {
		for (int i = 0; i < tmp->value.size(); i++) {
			tmp->value[i] ^= key[i % key.size()];
		}
		tmp = tmp->next;
	}
	// ��¼״̬
	list.codeStatus = false;
}

// ��㹹�캯��
str_node::str_node(const string& s)
{
	this->value = s;
	this->next = NULL;
}

// �����캯��
str_list::str_list()
{
	head = new str_node;
}

// ������������
str_list::~str_list()
{
	// �ֶ��ͷ��ڴ棨ÿ����㶼Ҫ�ͷţ�
	while (head) {
		str_node* tmp = head->next;
		delete head;
		head = tmp;
	}
}

// ��ӽ��
bool str_list::insert(str_node& node)
{
	// ���ַ��������ʧ��
	if (node.value == "")return false;

	// ���
	str_node* tmp = new str_node;
	tmp->value = node.value;
	tmp->next = NULL;

	// ���
	str_node* h_tmp = head;
	while (h_tmp->next) {
		h_tmp = h_tmp->next;
	}
	h_tmp->next = tmp;
}

// ��ӡ����
void str_list::printStr()
{
	// ����״̬
	if (this->codeStatus) {
		cout << "��ǰ����Ϊ���ģ����Ƚ��н��ܲ�����decry��" << endl;
		return;
	}

	// ͷ���Ϊ�գ��ӵڶ���������
	str_node* tmp = head->next;
	while (tmp) {
		cout << tmp->value << "  ";
		tmp = tmp->next;
	}
	cout << endl;
}

// ��ӡ����
void str_list::printCode()
{
	// ����״̬
	if (!this->codeStatus) {
		cout << "��ǰ����Ϊ���ģ����Ƚ��м��ܲ�����encry��" << endl;
		return;
	}

	// ͷ���Ϊ�գ��ӵڶ���������
	str_node* tmp = head->next;
	while (tmp) {
		// 16�������
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
