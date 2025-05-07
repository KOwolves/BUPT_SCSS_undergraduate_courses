#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

class Solution03_14
{
public:
	//获取结果
	void GetMultiResult()
	{
		//随机数种子
		srand(time(0));

		//调用递归函数
		long long ans = GetRandomsProduct(rand() % 10 + 1);

		//打印结果
		cout << ans << endl;
	}

	//递归函数，参数为因子个数
	long long GetRandomsProduct(int times)
	{
		//终止递归
		if (times == 0)
		{
			return 1;
		}
		//随机因子
		long long ans = rand();
		//打印过程，验证争取正确性
		if (times != 1)
		{
			cout << ans << " * ";
		}
		else
		{
			cout << ans << " = ";
		}
		//递归调用，乘前面的所有因子乘积
		ans *= GetRandomsProduct(times - 1);
		//返回答案
		return ans;
		
	}
};

void test_03_14()
{
	//匿名对象，直接调用
	Solution03_14().GetMultiResult();


}