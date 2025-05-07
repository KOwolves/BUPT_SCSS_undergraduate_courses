#include "StrEncryption.h"
#define MAX 1e6

//��Կ
static string KEY = "HelloWorld";

//�ַ����������
void strEncryption(string* strs, int n) {
	int** secret = new int* [n];
	//��Կ����
	int keyLen = KEY.length();

	//���ܲ����
	cout << "���ܺ���ַ���Ϊ��" << endl;
	for (int i = 0; i < n; i++) {
		int* temp = new int[MAX];
		for (int j = 0; j < strs[i].length(); j++) {
			temp[j] = strs[i][j] ^ KEY[j % keyLen];//��ֹ��Կ���Ȳ��㷢��Խ������
			cout.fill(0);
			cout.width(2);
			cout << hex << temp[j];
		}
		secret[i] = temp;
		cout << endl;
	}

	//�������
	cout << "���ܺ���ַ���Ϊ��" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strs[i].length(); j++) {
			cout << (char)(secret[i][j] ^ KEY[j % keyLen]);//��ֹ��Կ���Ȳ��㷢��Խ������
		}
		cout << endl;
	}

	//�ͷ��ڴ�
	for (int i = 0; i < n; i++) {
		delete[] secret[i];
	}
	delete[] secret;
}