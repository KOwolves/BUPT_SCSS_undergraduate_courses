#include"StrEncryption.h"

int main()
{
	int n;//字符串数
	cout << "请输入字符串数量：";
	cin >> n;

	//开辟字符串数组
	string* strs = new string[n];

	//输入
	cout << "请输入" << n << "个字符串：" << endl;
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
	}

	//输出加密、解密后字符串
	strEncryption(strs, n);

	//排序输出
	sort(strs, strs + n);
	cout << "排序后的字符串为：" << endl;
	for (int i = 0; i < n; i++)cout << strs[i] << endl;

	//手动释放内存
	delete[] strs;

	return 0;
}
