#include "Students.h"

Students::Students()
{
	student* head = new student("", "", "");
	head->next = NULL;
	this->head = head;
	this->size = 0;
}

Students::~Students()
{
	while (head)
	{
		student* current = head;
		head = head->next;
		delete current;
	}
}

//ͨ��ѧ�Ų���
bool Students::findStudentByID(const string& id) {
	student* current = head;
	while (current) {
		if (current->sId == id) {
			return true;
		}
		current = current->next;
	}
	//���Ҳ��ɹ��򷵻ؿ�ָ��
	return false;
}

//ͨ����������
bool Students::findStudentByName(const string& name) {
	student* current = head;
	while (current) {
		if (current->sName == name) {
			return true;
		}
		current = current->next;
	}
	//���Ҳ��ɹ��򷵻ؿ�ָ��
	return false;
}

//���ѧ����Ϣ
bool Students::insertStudent(const string& name, const string& groupId, const string& sId) {
	if (!findStudentByID(sId) && !findStudentByName(name)) {
		//ͨ������ȷ��ѧ���Ƿ����
		//��ѧ���������򴴽��½ڵ�
		student* newStudent = new student(name, groupId, sId);
		student* pre = head;
		student* current = head->next;
		while (current && stol(sId) > stol(current->sId)) {
			pre = current;
			current = current->next;
		}
		pre->next = newStudent;
		newStudent->next = current;
		head = newStudent;
		size++;
		cout << "ѧ����ӳɹ���" << endl;
		return true;
	}
	else return false;
}

// ͨ��ѧ��ɾ��ѧ����Ϣ
bool Students::deleteStudentByID(const string& sid)
{
	// ȷ��Ŀ��ѧ����Ϣλ��
	student* temp = this->head;
	while (temp->sId != sid)
	{
		temp = temp->next;
		// ��Ŀ����Ϣ��ɾ��ʧ��
		if (!temp)return false;
	}

	// ɾ��Ŀ��ѧ����Ϣ
	student* deleted = temp->next;
	temp->next = deleted->next;
	delete deleted;

	// ɾ���ɹ�
	return true;
}

// ͨ������ɾ��ѧ����Ϣ
bool Students::deleteStudentByName(const string& name)
{
	// ȷ��Ŀ��ѧ����Ϣλ��
	student* temp = this->head;
	while (temp->sName != name)
	{
		temp = temp->next;
		// ��Ŀ����Ϣ��ɾ��ʧ��
		if (!temp)return false;
	}

	// ɾ��Ŀ��ѧ����Ϣ
	student* deleted = temp->next;
	temp->next = deleted->next;
	delete deleted;

	// ɾ���ɹ�
	return true;
}
