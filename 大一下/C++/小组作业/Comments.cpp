#include "Comments.h"

Comments::Comments() :size(0), below60(0), Sto85(0), Eto100(0)
{
	comment* head = new comment();
	head->next = NULL;
	this->head = head;
}

Comments::~Comments()
{
	while (head)
	{
		comment* current = head;
		head = head->next;
		delete current;
	}
}

//ͨ��ѧ�Ż�ȡ����
bool Comments::getCommentBySid(const string& sid)
{
	comment* current = head;
	while (current) {
		if (current->sId == sid) {
			cout << sid << " " << current->sName << "�����ۣ�" << endl;
			cout << "����Ϊ��" << current->score << endl;
			cout << "����Ϊ��" << current->commentText << endl;
			return true;
		}
		current = current->next;
	}
	return false;
}

//ͨ��������ȡ����
bool Comments::getCommentBySname(const string& sname) {
	comment* p = this->head;
	while (p) {
		if (p->sName == sname) {
			cout << p->sId << " " << sname << "�����ۣ�" << endl;
			cout << "����Ϊ��" << p->score << endl;
			cout << "����Ϊ��" << p->commentText << endl;
			return true;
		}
		p = p->next;
	}
	return false;
}

//չʾ����������Ϣ
void Comments::showComments() {
	comment* current = head->next;
	if (!current) {
		cout << "�������ۣ�" << endl;
		return;
	}
	cout << endl <<  "���ύ�������£�" << endl;
	while (current) {
		cout << "ѧ�ţ�" << current->sId << "\t������" << current->sName
			<< "\t���֣�" << current->score << "\n���" << current->commentText << endl << endl;
		current = current->next;
	}
}


// �������
bool Comments::insertComment(const string& sid, const string& sname, int score, const string& commentText) {
	if (!getCommentBySid(sid) && !getCommentBySname(sname)) {
		// �����µ�����
		comment* newComment = new comment;
		newComment->sId = sid;
		newComment->sName = sname;
		newComment->score = score;
		newComment->commentText = commentText;
		newComment->next = NULL;

		// �������۲��뵽����
		comment* pre = head;
		comment* current = head->next;
		while (current&&stol(current->sId)<stol(sid)) {
			pre = current;
			current = current->next;
		}
		pre->next = newComment;
		newComment->next = current;

		// ����������
		size++;

		// ͳ��
		if (score < 60)this->below60++;
		else if (score < 85)this->Sto85++;
		else this->Eto100++;

		return true;
	}
	return false;
}

// ͨ��ѧ�Ÿ�������  
bool Comments::updateCommentBySid(const string& sid, int newScore, const string& newCommentText) {
	comment* temp = this->head;
	while (temp != nullptr && temp->sId != sid) {
		temp = temp->next;
	}

	if (temp != nullptr) {
		//����ͳ��
		int scoreTemp = temp->score;
		if (scoreTemp < 60)this->below60--;
		else if (scoreTemp < 85)this->Sto85--;
		else this->Eto100--;

		//����
		temp->score = newScore;
		temp->commentText = newCommentText;
		
		//����ͳ��
		if (newScore < 60)this->below60++;
		else if (newScore < 85)this->Sto85++;
		else this->Eto100++;

		return true; // ���³ɹ�  
	}

	return false; // δ�ҵ���Ӧѧ�ŵ����ۣ�����ʧ��  
}
//ͨ��������������
bool Comments::updateCommentBySname(const string& sname, int newScore, const string& newCommentText) {
	comment* temp = this->head;
	while (temp != nullptr && temp->sName != sname) {
		temp = temp->next;
	}

	if (temp != nullptr) {
		//����ͳ��
		int scoreTemp = temp->score;
		if (scoreTemp < 60)this->below60--;
		else if (scoreTemp < 85)this->Sto85--;
		else this->Eto100--;

		temp->score = newScore;
		temp->commentText = newCommentText;
		return true; // ���³ɹ�  

		//����ͳ��
		if (newScore < 60)this->below60++;
		else if (newScore < 85)this->Sto85++;
		else this->Eto100++;
	}

	return false; // δ�ҵ���Ӧ���������ۣ�����ʧ��  
}


// ͨ��ѧ��ɾ������
bool Comments::deleteCommentBySid(const string& sid)
{
	if (size > 0) {
		// ȷ����Ӧ����λ��
		comment* pre = head;
		comment* current = head->next;
		while (current) {
			if (current->sId == sid) {
				break;
			}
			current = current->next;
			pre = pre->next;
		}
		if (!current)return false;

		// ɾ��Ŀ������
		comment* deleted = current;
		int deletedScore = current->score;
		pre->next = current->next;
		delete deleted;

		//����ͳ��
		if (deletedScore < 60)this->below60--;
		else if (deletedScore < 85)this->Sto85--;
		else this->Eto100--;

		// ɾ���ɹ�
		size--;
		return true;
	}
	return false;
}

// ͨ������ɾ������
bool Comments::deleteCommentBySname(const string& sname)
{
	if (size > 0) {
		// ȷ����Ӧ����λ��
		comment* pre = head;
		comment* current = head->next;
		while (current) {
			if (current->sName == sname) {
				break;
			}
			current = current->next;
			pre = pre->next;
		}
		if (!current)return false;

		// ɾ��Ŀ������
		comment* deleted = current;
		int deletedScore = current->score;
		pre->next = current->next;
		delete deleted;

		//����ͳ��
		if (deletedScore < 60)this->below60--;
		else if (deletedScore < 85)this->Sto85--;
		else this->Eto100--;

		// ɾ���ɹ�
		size--;
		return true;
	}
	return false;
}

// ��������
int Comments::getCommentCount() {
	return this->size;
}

void Comments::getCommentCountByGroup()
{
	cout << endl << "������ͳ�ơ�" << endl
		<< "85�����ϣ�\t" << this->Eto100 << "��" << endl
		<< "60��85��\t" << this->Sto85 << "��" << endl
		<< "����60��\t" << this->below60 << "��" << endl;
}
