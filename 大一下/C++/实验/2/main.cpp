#include"str_encry.h"
#include"vec_sum.h"

int main()
{
	// 数组求和测试
	cout << "数组求和：" << endl;
	vector<int> v(5);//待求和数组

	// 数据输入
	cout << "请输入5个需要求和的数：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> v[i];
	}
	
	// 输出结果
	long sum = VectorSum(v, 0);
	cout << "求和结果为" << sum << endl;

	// 分隔
	cout << endl << "——————————————————————————————————————————————————" << endl << endl;

	// 字符加密测试
	cout << "字符加密：" << endl;
	string s = "I am fine";// 明文定义
	cout << "明文字符s为 " << s << endl;

	StrEncryF(s);// 函数加密字符串
	StrEncryD(s);// 有参宏加密字符串
	

	
	return 0;
}
