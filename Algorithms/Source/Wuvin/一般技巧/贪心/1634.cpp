#include<cstdio>
#include<algorithm>
using namespace std;
/*
���ȼ���������һ������
Ȼ�󽻻�����һ��
����delta
�ó���ti/di��С��Ӧ����ǰ��
*/
int ans;
struct cows
{
	int t, d;
	double val;
	bool operator < (const cows& b)const
	{
		return val < b.val;
	}
} cow[100005];
int n;
int main()
{
	scanf("%d", &n);
	long long all = 0;

	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &cow[i].t, &cow[i].d);
		cow[i].val = cow[i].t / (double) cow[i].d;
		all += cow[i].d;
	}

	sort(cow + 1, cow + n + 1);
	long long ans = 0;

	for (int i = 1; i <= n; i++)
	{
		all -= cow[i].d;
		ans += cow[i].t * 2 * all;
	}

	printf("%lld", ans);
	return 0;
}
