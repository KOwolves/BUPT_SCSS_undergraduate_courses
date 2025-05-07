#include<iostream>
using namespace std;
#include"point3D.h"
#include"Cars.h"

void hw_05();
void hw_06();

int main()
{
	hw_05();
	hw_06();
	
	system("pause");
	return 0;
}

void hw_05()
{
    Point3D p1(1, 2, 3), p2(4, 5, 6), p3;
    p3 = p1 + p2;  // 加法运算符测试  
    std::cout << "p1 + p2 = (" << p3.x << ", " << p3.y << ", " << p3.z << ")" << endl;
    p3 = p1 - p2;  // 减法运算符测试  
    cout << "p1 - p2 = (" << p3.x << ", " << p3.y << ", " << p3.z << ")" << endl;
    p1++;  // 自增运算符测试（前缀）  
    cout << "++p1 = (" << p1.x << ", " << p1.y << ", " << p1.z << ")" << endl;
    p1--;  // 自减运算符测试（前缀）  
    cout << "--p1 = (" << p1.x << ", " << p1.y << ", " << p1.z << ")" << endl;
    cout << "p1[0] = " << p1[0] << ", p1[1] = " << p1[1] << ", p1[2] = " << p1[2] << endl;  // 下标运算符测试  
}

void hw_06()
{
    PickupTruck myPickup("Ford", "F-150", 2.0, 5);
    myPickup.PrintInfo();
    myPickup.SpecialFeature();
}