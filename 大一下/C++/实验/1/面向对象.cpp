#include<iostream>
using namespace std;
#define PI 3.14
#include"�������.h"


void FaceClass()
{
	double r, h;
	cout << "�ֱ�����Բ����İ뾶�͸ߣ�" << endl;
	cin >> r >> h;
	Cylinder c1(r, h);
	cout << "Բ��������Ϊ��" << c1.GetVolume() << endl;

}