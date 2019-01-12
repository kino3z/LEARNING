/*
�����Զ���ѧϰ�ʼ�
paper:http://pan.baidu.com/s/1hqzRlvm
code :http://pan.baidu.com/s/1pJHnT0Z
�����Զ���ÿ���ڵ㱣�����һ�����Ĵ�
������Ĵ���fail��ָ��������Ĵ����Ҳ࿪ʼ�ĵڶ���������Լ��� ��
���Ĵ���Ȼ���������켴�ɡ����Ӷ�O(n)֤����������AC�Զ���
���ڲ�ͬ���Ĵ�ֻ��n����֤���������manacher֤�������������uoj��ȥ��
����ֻ��һ��ԭ������û�б�����Ĵ��ı�Ҫ��ֻ��Ҫ�������Ⱥ��е�
���ڲ���û�б��ϣ�ֻ�÷ǵݹ� 

���Կ�����manacherһ�������ֻ�����������Ĵ� 
*/
//bzoj 3676
#include<cstdio>
#include<iostream>
#include<cstring>
#define N 300008
using namespace std;
char s[N];
int n,cnt; 
struct node{
	int len;//ֻ��¼���ȣ�������ʲôȡ���ڵ�����·�� 
	int times;
	int fst;//ѹλ  ����DFS 
	int ne[28];
	int fail;
}node[N];
void build(){
	int p=2;//pointer
	cnt=2;for(int i=1;i<=n;i++) s[i]-='a'-1;
	node[1].fail=1;node[1].len=-1;node[2].fail=1;node[2].len=0;
	for(int i=1;i<=n;i++){
		while(s[i]!=s[i-node[p].len-1]) p=node[p].fail;
		if(node[p].ne[s[i]]!=0) {node[node[p].ne[s[i]]].times++;p=node[p].ne[s[i]];continue;}//�ýڵ��Ѵ��� 
		int k=node[p].ne[s[i]]=++cnt;
		node[k].len=node[p].len+2;node[k].times=1;
		if(p==1){node[k].fail=2;p=k;continue;}
		p=node[p].fail;while(p!=1&&s[i]!=s[i-node[p].len-1]) p=node[p].fail;
		node[k].fail=node[p].ne[s[i]];p=k;
	}
}
void count(){
	long long ans=0;
	for(int i=cnt;i>2;i--){
		ans=max(ans,node[i].len*(long long)node[i].times);
		node[node[i].fail].times+=node[i].times;
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	build();
	count();
	return 0;
}
