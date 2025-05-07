#include<iostream>
using namespace std;
#define PI 3.14
#include"面向对象.h"


void FaceClass()
{
	double r, h;
	cout << "分别输入圆柱体的半径和高：" << endl;
	cin >> r >> h;
	Cylinder c1(r, h);
	cout << "圆柱体的体积为：" << c1.GetVolume() << endl;

}