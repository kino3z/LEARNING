/*
������A����ǰ����ⶼ��������������
������Ԫ������С��64����0����
k=1 ֱ�Ӽ��㹱��
k=2 ��һ��ʽ�ӣ���һ������
k=3 ������
k=4 ������
k=5 ������
ֻ���е㵣�ľ������� 
*/
#define N 100005 
#include<iostream>
#include<bitset>
#include<cstdio>
#define LL unsigned long long 
using namespace std;
int biao[6][7]={{1,},
				{1,1,},
				{1,2,1,},
				{1,3,3,1,},
				{1,4,6,4,1,},
				{1,5,10,10,5,1,}};
long double val[6][70];
int n,k;
LL a[N];
int xxj[70];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			if((a[i]^a[j])<a[i]) a[i]^=a[j];
			if(a[i]>a[j]) a[j]^=a[i],a[i]^=a[j],a[j]^=a[i];
		}
		if(a[i]) a[++cnt]=a[i];
	}
	/*
	bitset<8> bt;
	for(int i=1;i<=cnt;i++){
		bt=a[i];
		cout<<bt<<endl;
	}*/
	//����ֵ��������Щ0�ĸ����޹�
	//��ĸΪ2^cnt
	for(int j=cnt;j;j--){
		val[1][j]=val[1][j+1]+a[j]/2.0;
	}
	for(int i=2;i<=k;i++){
		for(int j=cnt;j;j--){
			
		}
	}
	cout<<val[k][1]<<endl;
	return 0;
}
