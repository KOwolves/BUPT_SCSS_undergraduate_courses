#pragma once
using namespace std;
#ifndef _HOMEWORK_0321
#define _HOMEWORK_0321

#include<iostream>
// 最小值（宏函数）
#define GetMin(a,b,c)\
{\
	if((a)<=(b)&&(a)<=(c))cout<<"最低分为："<<a<<endl;\
	else if((b)<=(a)&&(b)<=(c))cout<<"最低分为："<<b<<endl;\
	else if((c)<=(a)&&(c)<=(b))cout<<"最低分为："<<c<<endl;\
}\

// 平均分
int GetAverage(int a, int b, int c);
// 最大值
int GetMax(int a, int b, int c);

#endif
