#include"��ͷ.h"

// ƽ��ֵʵ��
int GetAverage(int a, int b, int c)
{
	int ans = (a + b + c) / 3;
	return ans;
}
// ���ֵʵ��
int GetMax(int a, int b, int c)
{
	if (a >= b && a >= c)return a;
	else if (b >= a && b >= c)return b;
	else if (c >= a && c >= b)return c;
}
