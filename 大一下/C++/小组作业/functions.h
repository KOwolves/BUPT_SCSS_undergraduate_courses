/*
* ����ʵ���ࣺ
* ��װϵͳ����
*/

#pragma once
#include"Students.h"
#include"Comments.h"

class functions
{
public:
	bool inputComment(int& score, string& comment,const bool status);//�Ϸ��������ۣ�status�����Ƿ�Ϊ����
	bool INSERT(Students& studentsList, Comments& commentsList);//�ύ����
	bool UPDATE(Students& studentsList, Comments& commentsList);//��������
	bool DELETE(Students& studentsList, Comments& commentsList);//ɾ������
	bool FIND(Students& studentsList, Comments& commentsList);//��������
	void SHOWCOMMENTS(Comments& commentsList);//չʾ��������
};