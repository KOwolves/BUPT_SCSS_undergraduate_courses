#pragma once
#include<iostream>
using namespace std;

// �ַ�����ѭ����2���м���

// �вκ�����ַ���
#define StrEncryD(s)\
{\
	for(int i=0;s[i];i++)\
	{\
		s[i] = (s[i] + 2) % 128; \
	}\
	cout << "ͨ���вκ���ܺ���ַ���sΪ��" << s << endl;\
}

// ���������ַ���
void StrEncryF(string s)
{
	int i = 0;
	while (s[i])
	{
		s[i] = (s[i] + 2) % 128;
		i++;
	}
	cout << "ͨ���������ܺ���ַ���sΪ��" << s << endl;
}