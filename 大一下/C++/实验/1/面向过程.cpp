#include<iostream>
using namespace std;
#define PI 3.14

void FaceProcess()
{
	// �뾶���ߣ����
	double r, h, v;
	cout << "�ֱ�����Բ����İ뾶�͸ߣ�" << endl;
	cin >> r >> h;
	
	v = PI * r * r * h;
	cout << "Բ��������Ϊ��" << v << endl;

	return;
}