#pragma once
#include<iostream>
#include<vector>
using namespace std;

// ������ͣ��ݹ�
long VectorSum(const vector<int>& v, int index)
{
	// ��ֹ
	if (index == v.size())
	{
		return 0;
	}

	// �ݹ����
	return v[index] + VectorSum(v, index + 1);
}