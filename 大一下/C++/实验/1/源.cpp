#include<iostream>
using namespace std;
#include"��ͷ.h"

int main()
{
	int select;
	cout << "1���������" << endl << "2���������" << endl << "0���˳�" << endl;
	

	while (1)
	{
		cout << "����ѡ��" << endl;
		cin >> select;
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			// �������
			FaceClass();
			break;
		default:
			// �������
			FaceProcess();
			break;
		}
	
	}
	


	system("pause");
	return 0;
}