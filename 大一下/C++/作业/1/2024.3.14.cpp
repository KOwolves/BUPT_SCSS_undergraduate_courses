#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

class Solution03_14
{
public:
	//��ȡ���
	void GetMultiResult()
	{
		//���������
		srand(time(0));

		//���õݹ麯��
		long long ans = GetRandomsProduct(rand() % 10 + 1);

		//��ӡ���
		cout << ans << endl;
	}

	//�ݹ麯��������Ϊ���Ӹ���
	long long GetRandomsProduct(int times)
	{
		//��ֹ�ݹ�
		if (times == 0)
		{
			return 1;
		}
		//�������
		long long ans = rand();
		//��ӡ���̣���֤��ȡ��ȷ��
		if (times != 1)
		{
			cout << ans << " * ";
		}
		else
		{
			cout << ans << " = ";
		}
		//�ݹ���ã���ǰ����������ӳ˻�
		ans *= GetRandomsProduct(times - 1);
		//���ش�
		return ans;
		
	}
};

void test_03_14()
{
	//��������ֱ�ӵ���
	Solution03_14().GetMultiResult();


}