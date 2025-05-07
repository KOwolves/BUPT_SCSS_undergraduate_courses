#include "StrEncryption.h"
#define MAX 1e6

//密钥
static string KEY = "HelloWorld";

//字符串数组加密
void strEncryption(string* strs, int n) {
	int** secret = new int* [n];
	//密钥长度
	int keyLen = KEY.length();

	//加密并输出
	cout << "加密后的字符串为：" << endl;
	for (int i = 0; i < n; i++) {
		int* temp = new int[MAX];
		for (int j = 0; j < strs[i].length(); j++) {
			temp[j] = strs[i][j] ^ KEY[j % keyLen];//防止密钥长度不足发生越界问题
			cout.fill(0);
			cout.width(2);
			cout << hex << temp[j];
		}
		secret[i] = temp;
		cout << endl;
	}

	//解密输出
	cout << "解密后的字符串为：" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strs[i].length(); j++) {
			cout << (char)(secret[i][j] ^ KEY[j % keyLen]);//防止密钥长度不足发生越界问题
		}
		cout << endl;
	}

	//释放内存
	for (int i = 0; i < n; i++) {
		delete[] secret[i];
	}
	delete[] secret;
}