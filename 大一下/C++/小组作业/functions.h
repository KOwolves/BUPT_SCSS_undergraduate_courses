/*
* 功能实现类：
* 封装系统操作
*/

#pragma once
#include"Students.h"
#include"Comments.h"

class functions
{
public:
	bool inputComment(int& score, string& comment,const bool status);//合法输入评论，status代表是否为更新
	bool INSERT(Students& studentsList, Comments& commentsList);//提交评论
	bool UPDATE(Students& studentsList, Comments& commentsList);//更新评论
	bool DELETE(Students& studentsList, Comments& commentsList);//删除评论
	bool FIND(Students& studentsList, Comments& commentsList);//查找评论
	void SHOWCOMMENTS(Comments& commentsList);//展示所有评论
};