#include "functions.h"

bool functions::inputComment(int& score, string& comment, const bool status) {
	//����
	if (status) {
		cout << "�������µ����֣�0~100����" << endl;
		cin >> score;
		if (score < 0 || score>100) {
			cout << "������0��100�����֣�" << endl;
			return false;
		}
		cout << "�������µ����ۣ�" << endl;
		cin >> comment;
	}
	//�Ǹ���
	else {
		cout << "�����뱾�γ̵����֣�0~100����" << endl;
		cin >> score;
		if (score < 0 || score>100) {
			cout << "������0��100�����֣�" << endl;
			return false;
		}
		cout << "������Ա��γ̵����ۣ�" << endl;
		cin >> comment;
	}
	return true;
}

//����ʵ��
bool functions::INSERT(Students& studentsList, Comments& commentsList)
{
	//��Ϣ����
	string sid, sname, gid;
	cout << "������ѧ�ţ�" << endl;
	cin >> sid;
	if (sid.length() != 10 || (!(stoll(sid) < 2023213000 && stoll(sid) > 2023211000)
		&& !(stoll(sid) < 2022212000 && stoll(sid) > 2022211000))) {
		cout << "ѧ��������������" << endl;
		return false;
	}
	cout << "������������" << endl;
	cin >> sname;
	cout << "������С���ţ�" << endl;
	cin >> gid;
	if (gid <= "0" || gid > "9") {
		cout << "С����������������" << endl;
		return false;
	}

	//����ѧ���б�
	if (!studentsList.insertStudent(sname, gid, sid)) {
		cout << "�����ύ�����ۣ�" << endl;
		return false;
	}

	//����������Ϣ
	int score;
	string commentText;
	if (!inputComment(score, commentText, false))return false;

	//¼��������Ϣ
	bool flag = commentsList.insertComment(sid, sname, score, commentText);

	//��ӽ��
	if (flag) cout << "�ύ�ɹ���" << endl;
	else cout << "�ύʧ�ܣ�" << endl;

	return true;
}

bool functions::UPDATE(Students& studentsList, Comments& commentsList)
{
	if (commentsList.getCommentCount() > 0) {
		//��Ϣ����
		string sid, sname, newText;
		int newScore;
		cout << "������ѧ�ţ�" << endl;
		cin >> sid;
		cout << "������������" << endl;
		cin >> sname;
		if (!commentsList.getCommentBySid(sid) && !commentsList.getCommentBySname(sname)) {
			cout << "����δ�������ۣ�" << endl;
			return false;
		}
		if (!inputComment(newScore, newText, true))return false;


		//����
		bool flag1 = commentsList.updateCommentBySid(sid, newScore, newText), flag2 = false;
		if (!flag1)flag2 = commentsList.updateCommentBySname(sname, newScore, newText);

		//���½��
		if (flag1 || flag2)cout << "���³ɹ���" << endl;
		else cout << "����ʧ�ܣ�" << endl;

		return (flag1 || flag2);
	}
	else {
		cout << "Ŀǰ�����ۣ�" << endl;
		return false;
	}

}

bool functions::DELETE(Students& studentsList, Comments& commentsList)
{
	if (commentsList.getCommentCount() > 0) {
		//��Ϣ����
		string sid, sname;
		cout << "������ѧ�ţ�" << endl;
		cin >> sid;
		cout << "������������" << endl;
		cin >> sname;

		//��ʹ��ѧ�Ž���ɾ����������ʧ����ʹ����������ɾ������
		bool flag1 = commentsList.deleteCommentBySid(sid), flag2 = false;
		if (!flag1)flag2 = commentsList.deleteCommentBySname(sname);

		//ɾ�����
		if (flag1 || flag2)cout << "ɾ���ɹ���" << endl;
		else cout << "ɾ��ʧ�ܣ�" << endl;

		return (flag1 || flag2);
	}
	cout << "�����ۣ��޷�ɾ����" << endl;
	return false;
}

bool functions::FIND(Students& studentsList, Comments& commentsList)
{
	if (commentsList.getCommentCount() > 0) {
		//��Ϣ����
		string sid, sname;
		cout << "������ѧ�ţ�" << endl;
		cin >> sid;
		cout << "������������" << endl;
		cin >> sname;

		//��ʹ��ѧ�Ž��в��Ҳ�������ʧ����ʹ���������в��Ҳ���
		bool flag1 = commentsList.getCommentBySid(sid), flag2 = false;
		if (!flag1)flag2 = commentsList.getCommentBySname(sname);

		//���
		if (!flag1 && !flag2) cout << "��ͬѧ��δ�ύ���ۣ�" << endl;

		return (flag1 || flag2);
	}
	else {
		cout << "Ŀǰ�����ۣ�" << endl;
		return false;
	}
}

//չʾ��������
void functions::SHOWCOMMENTS(Comments& commentsList) {
	commentsList.getCommentCountByGroup();//ͳ����Ϣ
	commentsList.showComments();//��ϸ��Ϣ
}
