/*
* ������Ϣ�ࣺ
* �洢�ύ��������Ϣ
*/

#pragma once
#include"Students.h"
#include<iostream>
using namespace std;

//���
typedef struct COMMENT
{
	COMMENT* next;//��һ�����
	string sName;//������
	string sId;//������ѧ��
	int score;//��������
	string commentText;//��������
}comment;

//������
class Comments
{
	friend class Students;//��Ԫ��

public:
	Comments();
	~Comments();
	bool insertComment(const string& sid, const string& sname, int score, const string& commentText);//�������
	bool updateCommentBySid(const string& sid, int newScore, const string& newCommentText);//ͨ��ѧ�Ÿ�������
	bool updateCommentBySname(const string& sname, int newScore, const string& newCommentText);//ͨ��������������
	bool deleteCommentBySid(const string& sid);//ͨ��ѧ��ɾ������
	bool deleteCommentBySname(const string& sname);//ͨ������ɾ������
	bool getCommentBySid(const string& sid);//ͨ��ѧ�Ż�ȡ����
	bool getCommentBySname(const string& sname);//ͨ��������ȡ����
	void showComments();//չʾȫ������
	int getCommentCount();//��ȡ��������
	void getCommentCountByGroup();//��ȡͳ�ƺ�ĸ��ȼ���������

private:
	comment* head;//ͷ���
	int size;//������
	int below60, Sto85, Eto100;//�����ȼ�������
	static Students students;//ѧ���б�
};