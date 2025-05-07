/*
* ѧ���ࣺ
* ���ڴ洢ѧ����Ϣ
*/

#pragma once
#include<iostream>
#include<string>
#include"Comments.h"
using namespace std;

//���
typedef struct STUDENT
{
	STUDENT* next;//��һ�����
	string sName;//ѧ������
	string groupId;//���
	string sId;//ѧ��

	//���캯��
	STUDENT(string sname, string gid, string sid) :next(NULL), sName(sname), groupId(gid), sId(sid) {}
}student;

//ѧ����
class Students
{
	friend class Comments;//��Ԫ��

public:
	Students();
	~Students();
	bool findStudentByID(const string& sid);//ʹ��ѧ�Ų���
	bool findStudentByName(const string& sname);//ʹ����������
	bool insertStudent(const string& name, const string& groupId, const string& sId);//���ѧ����Ϣ
	bool deleteStudentByID(const string& sid);//ʹ��ѧ��ɾ��ѧ����Ϣ
	bool deleteStudentByName(const string& name);//ʹ������ɾ��ѧ����Ϣ

private:
	int size;//������ѧ������
	student* head;//ͷ���
};