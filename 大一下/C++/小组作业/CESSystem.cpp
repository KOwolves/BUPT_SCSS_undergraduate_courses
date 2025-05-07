#include "CESSystem.h"

CESSystem::CESSystem()
{
	this->studentsList = new Students();
	this->commentsList = new Comments();
	this->fTool = new functions();
}

CESSystem::~CESSystem()
{
	delete this->studentsList;
	delete this->commentsList;
	delete this->fTool;
}

//��ҳ��˵�
void CESSystem::showMenu()
{
	cout << "******************************************" << endl;
	cout << "************** ��������ϵͳ **************" << endl;
	cout << "**            1���ύ����               **" << endl;
	cout << "**            2����������               **" << endl;
	cout << "**            3����������               **" << endl;
	cout << "**            4��ɾ������               **" << endl;
	cout << "**            5��չʾ����               **" << endl;
	cout << "**            6���˳�ϵͳ               **" << endl;
	cout << "******************************************" << endl;
	cout << "******************************************" << endl;
	cout << "��ǰ��������Ϊ��" << commentsList->getCommentCount() << endl;
	cout << endl << "��������Ĳ���ѡ��" << endl;
}

//ѡ��
bool CESSystem::takeSelection(int select)
{

	switch (select)
	{
	case 1:
		fTool->INSERT(*this->studentsList, *this->commentsList);
		break;
	case 2:
		fTool->UPDATE(*this->studentsList, *this->commentsList);
		break;
	case 3:
		fTool->FIND(*this->studentsList, *this->commentsList);
		break;
	case 4:
		fTool->DELETE(*this->studentsList, *this->commentsList);
		break;
	case 5:
		fTool->SHOWCOMMENTS(*this->commentsList);
		break;
	case 6:
		cout << "�´μ���" << endl;
		return false;
		break;
	default:
		break;
	}

	return true;
}