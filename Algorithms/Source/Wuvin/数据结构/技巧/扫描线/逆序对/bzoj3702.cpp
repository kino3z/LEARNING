/*
���������������Ի���˳����÷���+����
��õ�nlogn^2,(ĳ�ˣ����ǿ��Թ鲢�� ans:�鲢n^2)
��ѯ�� 
���ֵ��Σ�mlogn
�鲢����:n+m
���Զ���+�鲢->����nlogn/(logn-1)
���������������ò�Ʊ���鲢������
���ǿ������ĺϲ���Treap����ʽ�ϲ���
�����һ�Ź�Сֱ�Ӳ��롣
��������ѹ������ڹ鲢������Treap�ĸ��ڵ㣿 
�Զ����󣬲�������try �����ܸ��Ӷ�nlogn 

������⣬����ʾ����������ƫ���ϲ��߶���
���hjt���ġ���ȷʵ�ܿ죬�����˾�̯logn�ϲ� 
�������ò�Ƹ���д��9494�� 

e..�����е���֣�����Ҫ��4000005
3600005��RE(��Ӧ���Ǹպ�nlogn��) 
*/
#include<cstdio>
#include<algorithm>
#define N 4000005
#define LL long long 
using namespace std;
int n,cnt;LL ans;
const int L=0,R=1;
//----------xds--------------
int size[N],son[N][2],fr[N],to[N];
inline void build(int &k,int fr_,int to_,int x){//���� 
	k=++cnt;size[k]=1;son[k][L]=son[k][R]=0;fr[k]=fr_;to[k]=to_;
	if(fr_==to_){
		return;
	}else{
		int mid=(fr_+to_)>>1;
		if(x<=mid) build(son[k][L],fr_,mid,x);
		else build(son[k][R],mid+1,to_,x);
	}
}
LL nxd1,nxd2;//�������� 2-Ҫ���� 
int merge(int x,int y){//���ؽڵ� ����Ը���װ�� nxd x��y�����  �ϲ���x 
	if(x==0) return y;
	if(y==0) return x;
	nxd1+=(LL)size[son[x][R]]*size[son[y][L]];
	nxd2+=(LL)size[son[x][L]]*size[son[y][R]];
	son[x][L]=merge(son[x][L],son[y][L]);
	son[x][R]=merge(son[x][R],son[y][R]);
	size[x]+=size[y];
	return x;
}
//----------xds--------------
int DFS(){//����root 
	int x;scanf("%d",&x);
	if(x==0){
		int x1=DFS();
		int x2=DFS();
		nxd1=nxd2=0;
		int a=merge(x1,x2);
		ans+=min(nxd1,nxd2);
		return a;
	}else{
		int t=0;
		build(t,1,n,x);
		return t;
	} 
}
int main(){
	scanf("%d",&n);
	DFS();
	printf("%lld",ans);
	return 0;
} 
