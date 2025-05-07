/*
* 学生类：
* 用于存储学生信息
*/

#pragma once
#include<iostream>
#include<string>
#include"Comments.h"
using namespace std;

//结点
typedef struct STUDENT
{
	STUDENT* next;//下一个结点
	string sName;//学生姓名
	string groupId;//组号
	string sId;//学号

	//构造函数
	STUDENT(string sname, string gid, string sid) :next(NULL), sName(sname), groupId(gid), sId(sid) {}
}student;

//学生类
class Students
{
	friend class Comments;//友元类

public:
	Students();
	~Students();
	bool findStudentByID(const string& sid);//使用学号查找
	bool findStudentByName(const string& sname);//使用姓名查找
	bool insertStudent(const string& name, const string& groupId, const string& sId);//添加学生信息
	bool deleteStudentByID(const string& sid);//使用学号删除学生信息
	bool deleteStudentByName(const string& name);//使用姓名删除学生信息

private:
	int size;//已评价学生数量
	student* head;//头结点
};