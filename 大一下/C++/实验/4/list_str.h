#pragma once
#include<iostream>
#include<string>
using namespace std;

class str_list;	// ������

// ������
class security
{
public:
	// ���캯��
	security(const string key = "default string") { this->key = key; }
	// ����
	void encry_str(str_list&);
	// ����
	void decry_str(str_list&);

private:
	string key;	// ��Կ
};

// �����
class str_node
{
public:
	string value = "";	// ���ֵ
	str_node* next = NULL;	// ��һ�����

	// ���캯��
	str_node(){}
	str_node(const string& s);
};

// �ַ���������
class str_list
{
	// ��Ԫ����
	friend void security::encry_str(str_list&);	// ����
	friend void security::decry_str(str_list&);	// ����

public:
	// ���캯��
	str_list();
	// ��������
	~str_list();
	// ��ӽ��
	bool insert(str_node&);
	// ��ӡ����
	void printStr();
	// ��ӡ����
	void printCode();

private:
	str_node* head;	// ͷ���
	bool codeStatus = false;	// ��¼��¼����״̬��trueΪ���ġ�falseΪ����
};