/*
* 系统类：
* 封装系统基础功能
*/

#pragma once
#include"functions.h"

class CESSystem
{
public:
	CESSystem();//构造函数
	~CESSystem();//析构函数
	void showMenu();//主菜单页面
	bool takeSelection(int select);//操作选择

private:
	//信息存储
	Students* studentsList;//学生信息
	Comments* commentsList;//评论信息
	//操作
	functions* fTool;//可使用操作
};