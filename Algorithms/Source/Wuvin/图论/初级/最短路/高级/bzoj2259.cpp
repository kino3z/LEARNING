/*
����ҵ�������ô�������һ�����дһдO��nlogn����DP��
����hzwer�������ǶԵģ�����ı߲�Ӱ��𰸡�
DP�Ļ�f[i]��ʾ��i����Сֵ������ֵҪ�����ŷ��������
���̰�ı���һ�����Ҳ�ά���������йؼ��ֱַ�Ϊ�����ĵ㣨Ϊ�±꣩���ã�ֵ ��������
���ڵ������еĲ��벻�ǵ����ģ������е��鷳
�����Ҳ���д��
*/
#include<cstdio>
#include<iostream>
#define N 1000005
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[N];
struct dddl{
    int x,val;
}right[N];
dddl left;
int head,tail;
int main(){
    head=tail=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]++;
    left.x=-INF;left.val=0;dp[1]=0;right[++head]=(dddl){1+a[1],0};
    for(int i=2;i<=n;i++){
        dp[i]=min(left.val+i-left.x,right[tail+1].val+right[tail+1].x-i);
        while(head>tail&&right[head].val>=)
    }
    return 0;
}