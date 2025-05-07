#include "functions.h"

bool functions::inputComment(int& score, string& comment, const bool status) {
	//更新
	if (status) {
		cout << "请输入新的评分（0~100）：" << endl;
		cin >> score;
		if (score < 0 || score>100) {
			cout << "请输入0到100的评分！" << endl;
			return false;
		}
		cout << "请输入新的评价：" << endl;
		cin >> comment;
	}
	//非更新
	else {
		cout << "请输入本课程的评分（0~100）：" << endl;
		cin >> score;
		if (score < 0 || score>100) {
			cout << "请输入0到100的评分！" << endl;
			return false;
		}
		cout << "请输入对本课程的评价：" << endl;
		cin >> comment;
	}
	return true;
}

//功能实现
bool functions::INSERT(Students& studentsList, Comments& commentsList)
{
	//信息输入
	string sid, sname, gid;
	cout << "请输入学号：" << endl;
	cin >> sid;
	if (sid.length() != 10 || (!(stoll(sid) < 2023213000 && stoll(sid) > 2023211000)
		&& !(stoll(sid) < 2022212000 && stoll(sid) > 2022211000))) {
		cout << "学号内容输入有误！" << endl;
		return false;
	}
	cout << "请输入姓名：" << endl;
	cin >> sname;
	cout << "请输入小组编号：" << endl;
	cin >> gid;
	if (gid <= "0" || gid > "9") {
		cout << "小组编号内容输入有误！" << endl;
		return false;
	}

	//插入学生列表
	if (!studentsList.insertStudent(sname, gid, sid)) {
		cout << "您已提交过评价！" << endl;
		return false;
	}

	//输入评价信息
	int score;
	string commentText;
	if (!inputComment(score, commentText, false))return false;

	//录入评价信息
	bool flag = commentsList.insertComment(sid, sname, score, commentText);

	//添加结果
	if (flag) cout << "提交成功！" << endl;
	else cout << "提交失败！" << endl;

	return true;
}

bool functions::UPDATE(Students& studentsList, Comments& commentsList)
{
	if (commentsList.getCommentCount() > 0) {
		//信息输入
		string sid, sname, newText;
		int newScore;
		cout << "请输入学号：" << endl;
		cin >> sid;
		cout << "请输入姓名：" << endl;
		cin >> sname;
		if (!commentsList.getCommentBySid(sid) && !commentsList.getCommentBySname(sname)) {
			cout << "您还未输入评价！" << endl;
			return false;
		}
		if (!inputComment(newScore, newText, true))return false;


		//更新
		bool flag1 = commentsList.updateCommentBySid(sid, newScore, newText), flag2 = false;
		if (!flag1)flag2 = commentsList.updateCommentBySname(sname, newScore, newText);

		//更新结果
		if (flag1 || flag2)cout << "更新成功！" << endl;
		else cout << "更新失败！" << endl;

		return (flag1 || flag2);
	}
	else {
		cout << "目前无评价！" << endl;
		return false;
	}

}

bool functions::DELETE(Students& studentsList, Comments& commentsList)
{
	if (commentsList.getCommentCount() > 0) {
		//信息输入
		string sid, sname;
		cout << "请输入学号：" << endl;
		cin >> sid;
		cout << "请输入姓名：" << endl;
		cin >> sname;

		//先使用学号进行删除操作，若失败则使用姓名进行删除操作
		bool flag1 = commentsList.deleteCommentBySid(sid), flag2 = false;
		if (!flag1)flag2 = commentsList.deleteCommentBySname(sname);

		//删除结果
		if (flag1 || flag2)cout << "删除成功！" << endl;
		else cout << "删除失败！" << endl;

		return (flag1 || flag2);
	}
	cout << "无评论，无法删除！" << endl;
	return false;
}

bool functions::FIND(Students& studentsList, Comments& commentsList)
{
	if (commentsList.getCommentCount() > 0) {
		//信息输入
		string sid, sname;
		cout << "请输入学号：" << endl;
		cin >> sid;
		cout << "请输入姓名：" << endl;
		cin >> sname;

		//先使用学号进行查找操作，若失败则使用姓名进行查找操作
		bool flag1 = commentsList.getCommentBySid(sid), flag2 = false;
		if (!flag1)flag2 = commentsList.getCommentBySname(sname);

		//结果
		if (!flag1 && !flag2) cout << "该同学还未提交评价！" << endl;

		return (flag1 || flag2);
	}
	else {
		cout << "目前无评价！" << endl;
		return false;
	}
}

//展示所有评论
void functions::SHOWCOMMENTS(Comments& commentsList) {
	commentsList.getCommentCountByGroup();//统计信息
	commentsList.showComments();//详细信息
}
