#include<iostream>
#include"标头.h"
using namespace std;

void hw_04_11(int (*matrix)[50]);

int main()
{
	//第三次作业
	int a = 0, b = 0, c = 0;
	cout << "请依次输入三门课的成绩：" << endl;
	cin >> a >> b >> c;
	cout << "平均分为：" << GetAverage(a, b, c) << endl;
	cout << "最高分为：" << GetMax(a, b, c) << endl;
	GetMin(a, b, c);
	

	//第四次作业：
	//作为参数值
	int matrix[50][50];
	hw_04_11(matrix);

	
	system("pause");
	return 0;
}

void hw_04_11(int (*matrix)[50])
{
	cout << "请输入一个50×50的矩阵：" << endl;
	//输入矩阵
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			cin >> matrix[i][j];
		}
	}

	//输出矩阵
	cout << "输入的矩阵为：" << endl;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;//换行，增加可读性
	}
}