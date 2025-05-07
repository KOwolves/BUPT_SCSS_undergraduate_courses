#pragma once
#include<iostream>
#include<string>
using namespace std;

class str_list;	// 链表类

// 加密类
class security
{
public:
	// 构造函数
	security(const string key = "default string") { this->key = key; }
	// 加密
	void encry_str(str_list&);
	// 解密
	void decry_str(str_list&);

private:
	string key;	// 密钥
};

// 结点类
class str_node
{
public:
	string value = "";	// 结点值
	str_node* next = NULL;	// 下一个结点

	// 构造函数
	str_node(){}
	str_node(const string& s);
};

// 字符串链表类
class str_list
{
	// 友元函数
	friend void security::encry_str(str_list&);	// 加密
	friend void security::decry_str(str_list&);	// 解密

public:
	// 构造函数
	str_list();
	// 析构函数
	~str_list();
	// 添加结点
	bool insert(str_node&);
	// 打印明文
	void printStr();
	// 打印密文
	void printCode();

private:
	str_node* head;	// 头结点
	bool codeStatus = false;	// 记录记录内容状态：true为密文、false为明文
};