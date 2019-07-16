#include <iostream>
#include <algorithm>
using namespace std;
int getluckypacket(int a[], int n, int pos, int sum, int multi)
{
	//a[]:�����е�������
	//n:�������
	//pos����ǰ������λ��
	//sum����Ŀǰλ�õ��ۼӺ�
	//multi����Ŀǰλ�õ��ۻ�
	int count = 0;
	for (int i = pos; i < n; ++i)
	{
		sum += a[i];
		multi *= a[i];
		if (sum > multi)
		{
			count += 1 + getluckypacket(a, n, i + 1, sum, multi);
			//�ҵ�����Ҫ�����ϣ�+1�������ۼӺ�����ֵ�����Ƿ��з���Ҫ��ļ���
		}
		else if (a[i] == 1)
		{
			count += getluckypacket(a, n, i + 1, sum, multi);
			//��������Ҫ�󣬵���ǰԪ��ֵΪ1�������ж�һ��
		}
		else
			break;//��ʱ������û�з���Ҫ��������
		//Ҫ������һ��λ��֮ǰ���Ȼָ�sum��mmulti
		sum -= a[i];
		multi /= a[i];
		while (i < n - 1 && a[i] == a[i + 1])//����������ͬ������һ����ϣ�ֱ������
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