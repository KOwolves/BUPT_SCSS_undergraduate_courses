#include"list_str.h"

int main()
{
	// 字符串链表
	str_list list;

	// 输入密钥
	string key;
	cout << "请输入密钥：" << endl;
	cin >> key;
	security se(key);

	string temp;	// 输入字符串
	cout << "请输入字符串，q代表退出：" << endl;
	while (cin >> temp) {
		if (temp == "q") break;	// 退出输入
		str_node n(temp);
		list.insert(n);
	}
	cout << "输入的链表字符串为：" << endl;
	list.printStr();
	cout << "加密的链表字符串为：" << endl;
	se.encry_str(list);	// 加密
	list.printCode();
	cout << "解密的链表字符串为：" << endl;
	se.decry_str(list);	// 解密
	list.printStr();

	return 0;
}
