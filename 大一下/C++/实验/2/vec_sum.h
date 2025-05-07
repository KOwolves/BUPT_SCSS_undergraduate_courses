#pragma once
#include<iostream>
#include<vector>
using namespace std;

// 数组求和，递归
long VectorSum(const vector<int>& v, int index)
{
	// 终止
	if (index == v.size())
	{
		return 0;
	}

	// 递归求和
	return v[index] + VectorSum(v, index + 1);
}