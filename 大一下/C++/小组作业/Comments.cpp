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

//通过学号获取评价
bool Comments::getCommentBySid(const string& sid)
{
	comment* current = head;
	while (current) {
		if (current->sId == sid) {
			cout << sid << " " << current->sName << "的评价：" << endl;
			cout << "评分为：" << current->score << endl;
			cout << "评语为：" << current->commentText << endl;
			return true;
		}
		current = current->next;
	}
	return false;
}

//通过姓名获取评价
bool Comments::getCommentBySname(const string& sname) {
	comment* p = this->head;
	while (p) {
		if (p->sName == sname) {
			cout << p->sId << " " << sname << "的评价：" << endl;
			cout << "评分为：" << p->score << endl;
			cout << "评语为：" << p->commentText << endl;
			return true;
		}
		p = p->next;
	}
	return false;
}

//展示所有评价信息
void Comments::showComments() {
	comment* current = head->next;
	if (!current) {
		cout << "暂无评价！" << endl;
		return;
	}
	cout << endl <<  "已提交评价如下：" << endl;
	while (current) {
		cout << "学号：" << current->sId << "\t姓名：" << current->sName
			<< "\t评分：" << current->score << "\n评语：" << current->commentText << endl << endl;
		current = current->next;
	}
}


// 添加评价
bool Comments::insertComment(const string& sid, const string& sname, int score, const string& commentText) {
	if (!getCommentBySid(sid) && !getCommentBySname(sname)) {
		// 创建新的评论
		comment* newComment = new comment;
		newComment->sId = sid;
		newComment->sName = sname;
		newComment->score = score;
		newComment->commentText = commentText;
		newComment->next = NULL;

		// 将新评论插入到链表
		comment* pre = head;
		comment* current = head->next;
		while (current&&stol(current->sId)<stol(sid)) {
			pre = current;
			current = current->next;
		}
		pre->next = newComment;
		newComment->next = current;

		// 增加评价数
		size++;

		// 统计
		if (score < 60)this->below60++;
		else if (score < 85)this->Sto85++;
		else this->Eto100++;

		return true;
	}
	return false;
}

// 通过学号更新评论  
bool Comments::updateCommentBySid(const string& sid, int newScore, const string& newCommentText) {
	comment* temp = this->head;
	while (temp != nullptr && temp->sId != sid) {
		temp = temp->next;
	}

	if (temp != nullptr) {
		//更新统计
		int scoreTemp = temp->score;
		if (scoreTemp < 60)this->below60--;
		else if (scoreTemp < 85)this->Sto85--;
		else this->Eto100--;

		//更新
		temp->score = newScore;
		temp->commentText = newCommentText;
		
		//更新统计
		if (newScore < 60)this->below60++;
		else if (newScore < 85)this->Sto85++;
		else this->Eto100++;

		return true; // 更新成功  
	}

	return false; // 未找到对应学号的评论，更新失败  
}
//通过姓名更新评论
bool Comments::updateCommentBySname(const string& sname, int newScore, const string& newCommentText) {
	comment* temp = this->head;
	while (temp != nullptr && temp->sName != sname) {
		temp = temp->next;
	}

	if (temp != nullptr) {
		//更新统计
		int scoreTemp = temp->score;
		if (scoreTemp < 60)this->below60--;
		else if (scoreTemp < 85)this->Sto85--;
		else this->Eto100--;

		temp->score = newScore;
		temp->commentText = newCommentText;
		return true; // 更新成功  

		//更新统计
		if (newScore < 60)this->below60++;
		else if (newScore < 85)this->Sto85++;
		else this->Eto100++;
	}

	return false; // 未找到对应姓名的评论，更新失败  
}


// 通过学号删除评价
bool Comments::deleteCommentBySid(const string& sid)
{
	if (size > 0) {
		// 确定对应评价位置
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

		// 删除目标评价
		comment* deleted = current;
		int deletedScore = current->score;
		pre->next = current->next;
		delete deleted;

		//更新统计
		if (deletedScore < 60)this->below60--;
		else if (deletedScore < 85)this->Sto85--;
		else this->Eto100--;

		// 删除成功
		size--;
		return true;
	}
	return false;
}

// 通过名字删除评价
bool Comments::deleteCommentBySname(const string& sname)
{
	if (size > 0) {
		// 确定对应评价位置
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

		// 删除目标评价
		comment* deleted = current;
		int deletedScore = current->score;
		pre->next = current->next;
		delete deleted;

		//更新统计
		if (deletedScore < 60)this->below60--;
		else if (deletedScore < 85)this->Sto85--;
		else this->Eto100--;

		// 删除成功
		size--;
		return true;
	}
	return false;
}

// 评论数量
int Comments::getCommentCount() {
	return this->size;
}

void Comments::getCommentCountByGroup()
{
	cout << endl << "“评分统计”" << endl
		<< "85及以上：\t" << this->Eto100 << "条" << endl
		<< "60至85：\t" << this->Sto85 << "条" << endl
		<< "低于60：\t" << this->below60 << "条" << endl;
}
