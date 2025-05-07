#include"标头.h"

// 平均值实现
int GetAverage(int a, int b, int c)
{
	int ans = (a + b + c) / 3;
	return ans;
}
// 最大值实现
int GetMax(int a, int b, int c)
{
	if (a >= b && a >= c)return a;
	else if (b >= a && b >= c)return b;
	else if (c >= a && c >= b)return c;
}
