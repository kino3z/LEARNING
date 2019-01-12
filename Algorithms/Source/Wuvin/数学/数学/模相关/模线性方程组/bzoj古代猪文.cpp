/*
��Ŀ���������� n,G
P=sum((if n%i==0) c(i,n))
��G^P mod  999911659
��� 
999911658=2 * 3 * 4679 * 35617
������ģG��P�η���Ȼ���û����
999911659�Ǹ�����
�� ŷ������ ��G��P�η�����һ������Ϊ 999911658��ѭ��
����ֻ�����Pģ 999911658��ֵ����
���� 999911658̫����
���Բ�Сһ�㣬�ֱ��� Lucas ���������һ��
Ȼ�� CRT���й�ʣ�ඨ�� �ϲ����� 
*/
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
#define LL long long 
int n,G;LL P;
const unsigned int mod=999911659;
int ans[5];
unsigned int mo[5]={0,2,3,4679,35617};
int ys[100005];int cnt=0;
int rv[5][35620];
int fact[5][35620]; 
inline int C(int m1,int n1,int k){
	if(m1>n1) return 0;//��Ҳ��֪��Ϊʲôreturn ����0
	//int up=1,down=1;
	//for(int i=n1;i>n1-m1;i--) up=up*i%mo[k];
	//for(int i=m1;i;i--) down=down*i%mo[k];
	//return (up*rv[k][down])%mo[k]; 
	return ((fact[k][n1]*rv[k][fact[k][m1]])%mo[k])*rv[k][fact[k][n1-m1]]%mo[k];
}

inline int lucas(int m1,int n1,int k){//c(m1,n1)%mo[k]
	if(k==1) return (m1&n1)==m1? 1:0; 
	int ret=1;
	while(m1!=0&&n1!=0&&ret!=0){
		ret=ret*C(m1%mo[k],n1%mo[k],k)%mo[k];
		m1/=mo[k];n1/=mo[k];
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&G);
	if(G%mod==0) {puts("0");return 0;}
	for(int i=sqrt(n);i;i--) {
		if(n%i==0){
			ys[++cnt]=i;
			if(i*i!=n) ys[++cnt]=n/i;
		}
	}
	for(int i=1;i<=4;i++){
		rv[i][1]=1;
		for(int j=2;j<mo[i];j++) 
			rv[i][j]=mo[i]-((mo[i]/j)*rv[i][mo[i]%j])%mo[i];
	}
	for(int i=1;i<=4;i++){
		fact[i][0]=1;
		for(int j=1;j<=mo[i];j++) fact[i][j]=fact[i][j-1]*j%mo[i];
	}
	for(int j=1;j<=cnt;j++) ans[1]+=(ys[j]&n)==ys[j]? 1:0;
	ans[1]&=1;
	for(int i=2;i<=4;i++) 
		for(int j=1;j<=cnt;j++)	
			ans[i]=(ans[i]+lucas(ys[j],n,i))%mo[i];
	unsigned int M=mod-1;//CRT
	for(int i=1;i<=4;i++){
		P=(P+(LL)((M/mo[i])*ans[i]%M)*rv[i][(M/mo[i])%mo[i]])%M;
	}
	LL out=1;
	for(int i=30;i>=0;i--)
		if((1<<i)&P) out=(LL)G*((out*out)%mod)%mod;
		else out=(out*out)%mod;
	cout<<out<<endl;
	return 0;
}
