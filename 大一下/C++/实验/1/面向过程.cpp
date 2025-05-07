#include<iostream>
using namespace std;
#define PI 3.14

void FaceProcess()
{
	// 半径，高，体积
	double r, h, v;
	cout << "分别输入圆柱体的半径和高：" << endl;
	cin >> r >> h;
	
	v = PI * r * r * h;
	cout << "圆柱体的体积为：" << v << endl;

	return;
}