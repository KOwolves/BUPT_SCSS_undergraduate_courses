/*
* ϵͳ�ࣺ
* ��װϵͳ��������
*/

#pragma once
#include"functions.h"

class CESSystem
{
public:
	CESSystem();//���캯��
	~CESSystem();//��������
	void showMenu();//���˵�ҳ��
	bool takeSelection(int select);//����ѡ��

private:
	//��Ϣ�洢
	Students* studentsList;//ѧ����Ϣ
	Comments* commentsList;//������Ϣ
	//����
	functions* fTool;//��ʹ�ò���
};