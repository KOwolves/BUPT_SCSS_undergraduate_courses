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

//主页面菜单
void CESSystem::showMenu()
{
	cout << "******************************************" << endl;
	cout << "************** 课堂评价系统 **************" << endl;
	cout << "**            1、提交评价               **" << endl;
	cout << "**            2、更新评价               **" << endl;
	cout << "**            3、查找评价               **" << endl;
	cout << "**            4、删除评价               **" << endl;
	cout << "**            5、展示评价               **" << endl;
	cout << "**            6、退出系统               **" << endl;
	cout << "******************************************" << endl;
	cout << "******************************************" << endl;
	cout << "当前评价数量为：" << commentsList->getCommentCount() << endl;
	cout << endl << "请输入你的操作选择：" << endl;
}

//选择
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
		cout << "下次见！" << endl;
		return false;
		break;
	default:
		break;
	}

	return true;
}