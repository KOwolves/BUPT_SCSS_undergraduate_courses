#include"CESSystem.h"

int main()
{
	CESSystem tool = CESSystem();
	long long select;
	bool flag = 1;

	while (true)
	{
		//��ҳ��˵�
		tool.showMenu();
		flag = 1;
		cin >> select;
		//��֤��ȷ����
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�޶�Ӧ������" << endl;
			flag = 0;
		}

		//ѡ�����
		if (flag && !tool.takeSelection(select))break;

		system("pause");
		system("cls");
	}

	return 0;
}