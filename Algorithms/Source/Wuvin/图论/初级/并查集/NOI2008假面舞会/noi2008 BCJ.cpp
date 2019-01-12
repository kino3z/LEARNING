#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
/******************************
noi2008 �������
���鼯������
*******************************/ 
using namespace std;
int P=9999999;
int abs(int c){
	if(c<0) return -c;
	return c;
}

int bcj[100005];
int dis[100005];//���� 
int findfather(int u){
	if(bcj[u]==u) return u;
	int buf=findfather(bcj[u]);
	dis[u]+=dis[bcj[u]];
	//dis[u]%=p;
	bcj[u]=buf;
	return buf;
}
void connect(int u,int v){//u->v   means u can see v ,that's biaohao[u]+1=biaohao[v]
	int p=findfather(u);
	bcj[findfather(u)]=bcj[findfather(v)];
	dis[p]=dis[v]+1-dis[u];
}
bool inone(int u,int v){
	return findfather(u)==findfather(v);
}

int ans=-1;
void wrong(){
	printf("-1 -1");
	exit(0);
}
int gcd(int big,int sm){
	int t=big%sm;
	if(t==0) return sm;
	return gcd(sm,t);
}
void addans(int t){
	if(ans==-1){
		ans=t;
	}else{
		if(t>ans)
			ans=gcd(t,ans);
		else
			ans=gcd(ans,t);
		if(ans<3){
			wrong();
		}
	}
}


int n,m;
int maxanss[100005];
int minanss[100005];
int main(){
	scanf("%d%d",&n,&m);
	if(n<3){
		wrong();
	}
	for(int i=1;i<=n;i++){
		bcj[i]=i;
	}
	for(int a,b,i=1;i<=m;i++){
		scanf("%d%d",&a,&b);//a see b;
		if(inone(a,b)){
			int f1=max(dis[a]-1,dis[b]);
			int f2=min(dis[a]-1,dis[b]);
			//��ʱf2��f1�����������ͬ
			if(f1-f2<3&&f1-f2!=0){
				wrong();
			}else if(f1==f2){
				continue;
			}else{
				addans(f1-f2);
			}
		}else{
			connect(a,b);
		}
	}
	int minans=ans;
	if(ans==-1){//���ܻ᲻��ͨ 
		int maxans=0;
		for(int i=1;i<=n;i++){
			findfather(i);
			maxanss[bcj[i]]=max(maxanss[bcj[i]],dis[i]+1);//�п�����ͨ������СdisΪ��
			minanss[bcj[i]]=min(minanss[bcj[i]],dis[i]);
			/************
			������
			11 5
			1 10
			9 4
			2 1
			2 6
			8 2
			*//////////// 
		}
		for(int i=1;i<=n;i++){
			maxans+=maxanss[i];
			maxans-=minanss[i];
		}
		if(maxans<3)
			wrong();
		else{
			printf("%d 3\n",maxans);
		}
	}else{
		int p=ans;
		for(int i=3;i<=p;i++){
			if(ans%i==0){
				minans=i;
				break;
			}
		}
		printf("%d %d",ans,minans);
	}
	
	return 0;
}
