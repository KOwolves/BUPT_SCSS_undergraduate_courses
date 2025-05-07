#include<iostream>
using namespace std;
#include"标头.h"

int main()
{
	int select;
	cout << "1：面向对象" << endl << "2：面向过程" << endl << "0：退出" << endl;
	

	while (1)
	{
		cout << "输入选择：" << endl;
		cin >> select;
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			// 面向对象
			FaceClass();
			break;
		default:
			// 面向过程
			FaceProcess();
			break;
		}
	
	}
	


	system("pause");
	return 0;
}