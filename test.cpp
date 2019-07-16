#include <iostream>
#include <algorithm>
using namespace std;
int getluckypacket(int a[], int n, int pos, int sum, int multi)
{
	//a[]:袋子中的所有球
	//n:球的总数
	//pos：当前搜索的位置
	//sum：到目前位置的累加和
	//multi：到目前位置的累积
	int count = 0;
	for (int i = pos; i < n; ++i)
	{
		sum += a[i];
		multi *= a[i];
		if (sum > multi)
		{
			count += 1 + getluckypacket(a, n, i + 1, sum, multi);
			//找到符合要求的组合，+1，继续累加后续的值，看是否有符合要求的集合
		}
		else if (a[i] == 1)
		{
			count += getluckypacket(a, n, i + 1, sum, multi);
			//若不符合要求，但当前元素值为1，则再判断一次
		}
		else
			break;//此时后面已没有符合要求的组合了
		//要搜索下一个位置之前，先恢复sum和mmulti
		sum -= a[i];
		multi /= a[i];
		while (i < n - 1 && a[i] == a[i + 1])//对于数字相同的球，算一个组合，直接跳过
			++i;
	}
	return count;
}
int main2()
{
	int n;
	while (cin >> n)
	{
		int *a = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		cout << getluckypacket(a, n, 0, 0, 1) << endl;
	}
	return 0;
}