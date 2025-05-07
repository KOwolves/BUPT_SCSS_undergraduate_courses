/*
* 评论信息类：
* 存储提交的评论信息
*/

#pragma once
#include"Students.h"
#include<iostream>
using namespace std;

//结点
typedef struct COMMENT
{
	COMMENT* next;//下一个结点
	string sName;//评价者
	string sId;//评价者学号
	int score;//课堂评分
	string commentText;//评论内容
}comment;

//评论类
class Comments
{
	friend class Students;//友元类

public:
	Comments();
	~Comments();
	bool insertComment(const string& sid, const string& sname, int score, const string& commentText);//添加评价
	bool updateCommentBySid(const string& sid, int newScore, const string& newCommentText);//通过学号更新评价
	bool updateCommentBySname(const string& sname, int newScore, const string& newCommentText);//通过姓名更新评价
	bool deleteCommentBySid(const string& sid);//通过学号删除评价
	bool deleteCommentBySname(const string& sname);//通过姓名删除评价
	bool getCommentBySid(const string& sid);//通过学号获取评价
	bool getCommentBySname(const string& sname);//通过姓名获取评价
	void showComments();//展示全部评价
	int getCommentCount();//获取评价数量
	void getCommentCountByGroup();//获取统计后的各等级评价数量

private:
	comment* head;//头结点
	int size;//评价数
	int below60, Sto85, Eto100;//各个等级评价数
	static Students students;//学生列表
};