#include<cstdio>
#include<cmath>
#define N 100005
#define LL long long
/*
�����е���������ķֿ��ˡ�
ǰ�������̫�����ˡ�
����ÿ���飬ά���ܺͣ����ǰ׺�� 
�������в����ˣ���ô�죬����һ����˵
�ðɽⷨ�������ֹ��� 
*/
using namespace std;
int fr[1005],to[1005];//��
int maxn[1005];
LL sum[1005];
LL add[1005];//lazy��� 
int a[N];
int n,m,f,p;//p��ĸ��� 
void build(int k){//������k�� 
	maxn[k]=sum[k]=0;
	for(int i=fr[k];i<=to[k];i++){
		sum[k]+=a[i];if(a[i]>maxn) maxn=a[i];
	}
	maxn[k]+=add[k];
	sum[k]+=(to[k]-fr[k]+1)*add[k];
}
inline void interval_add(int from,int to_,int c){
	for(int i=1;i<=p;i++){
		if(fr[i]>=from&&to[i]<=to_){
			sum[i]+=(to[i]-fr[i]+1)*c;
			add[i]+=c;
			maxn[i]+=c; 
		}else if(fr[i]>to_){
			break;
		}else if(to[i]<from){
			continue;
		}else{//���� 
			for(int j=max(from,fr[i]);j<=min(to[i],to_)){
				a[i]+=c;
			}
			build(i);
		}
	}
}
LL query(int from,int to_){
	int ret=0;
	for(int i=1;i<=p;i++)
}

int main(){
	scanf("%d",&n);f=sqrt(n)+0.001;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1,p=1;i<=n;i+=f,p++){
		fr[x]=i;en[x]=min(n,i+f-1);
	}
	for(int i=1;i<=p;i++){
		build(i);
	}
	scanf("%d",&m);
	for(int i=1,ins;i<=m;i++){
		scanf("%d",&ins);
		if(ins==0){
			int f,t,c;
			scanf("%d%d%d",&f,&t,&c);
			interval_add(f,t,c);
		}else{
			int f,t;
			scanf("%d%d",&f,&t);
			printf("%lld\n",query(f,t));
		}
	}
	return 0;
} 
