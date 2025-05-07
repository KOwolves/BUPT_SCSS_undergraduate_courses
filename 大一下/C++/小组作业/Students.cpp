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

//通过学号查找
bool Students::findStudentByID(const string& id) {
	student* current = head;
	while (current) {
		if (current->sId == id) {
			return true;
		}
		current = current->next;
	}
	//查找不成功则返回空指针
	return false;
}

//通过姓名查找
bool Students::findStudentByName(const string& name) {
	student* current = head;
	while (current) {
		if (current->sName == name) {
			return true;
		}
		current = current->next;
	}
	//查找不成功则返回空指针
	return false;
}

//添加学生信息
bool Students::insertStudent(const string& name, const string& groupId, const string& sId) {
	if (!findStudentByID(sId) && !findStudentByName(name)) {
		//通过查找确认学生是否存在
		//若学生不存在则创建新节点
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
		cout << "学生添加成功！" << endl;
		return true;
	}
	else return false;
}

// 通过学号删除学生信息
bool Students::deleteStudentByID(const string& sid)
{
	// 确定目标学生信息位置
	student* temp = this->head;
	while (temp->sId != sid)
	{
		temp = temp->next;
		// 无目标信息，删除失败
		if (!temp)return false;
	}

	// 删除目标学生信息
	student* deleted = temp->next;
	temp->next = deleted->next;
	delete deleted;

	// 删除成功
	return true;
}

// 通过名字删除学生信息
bool Students::deleteStudentByName(const string& name)
{
	// 确定目标学生信息位置
	student* temp = this->head;
	while (temp->sName != name)
	{
		temp = temp->next;
		// 无目标信息，删除失败
		if (!temp)return false;
	}

	// 删除目标学生信息
	student* deleted = temp->next;
	temp->next = deleted->next;
	delete deleted;

	// 删除成功
	return true;
}
