#include"CESSystem.h"

int main()
{
	CESSystem tool = CESSystem();
	long long select;
	bool flag = 1;

	while (true)
	{
		//主页面菜单
		tool.showMenu();
		flag = 1;
		cin >> select;
		//保证正确输入
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "无对应操作！" << endl;
			flag = 0;
		}

		//选择操作
		if (flag && !tool.takeSelection(select))break;

		system("pause");
		system("cls");
	}

	return 0;
}