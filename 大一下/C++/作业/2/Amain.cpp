#include<iostream>
#include"��ͷ.h"
using namespace std;

void hw_04_11(int (*matrix)[50]);

int main()
{
	//��������ҵ
	int a = 0, b = 0, c = 0;
	cout << "�������������ſεĳɼ���" << endl;
	cin >> a >> b >> c;
	cout << "ƽ����Ϊ��" << GetAverage(a, b, c) << endl;
	cout << "��߷�Ϊ��" << GetMax(a, b, c) << endl;
	GetMin(a, b, c);
	

	//���Ĵ���ҵ��
	//��Ϊ����ֵ
	int matrix[50][50];
	hw_04_11(matrix);

	
	system("pause");
	return 0;
}

void hw_04_11(int (*matrix)[50])
{
	cout << "������һ��50��50�ľ���" << endl;
	//�������
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			cin >> matrix[i][j];
		}
	}

	//�������
	cout << "����ľ���Ϊ��" << endl;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;//���У����ӿɶ���
	}
}