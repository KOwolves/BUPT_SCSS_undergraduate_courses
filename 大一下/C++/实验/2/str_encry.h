#pragma once
#include<iostream>
using namespace std;

// 字符往后循环加2进行加密

// 有参宏加密字符串
#define StrEncryD(s)\
{\
	for(int i=0;s[i];i++)\
	{\
		s[i] = (s[i] + 2) % 128; \
	}\
	cout << "通过有参宏加密后的字符串s为：" << s << endl;\
}

// 函数加密字符串
void StrEncryF(string s)
{
	int i = 0;
	while (s[i])
	{
		s[i] = (s[i] + 2) % 128;
		i++;
	}
	cout << "通过函数加密后的字符串s为：" << s << endl;
}