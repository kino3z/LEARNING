#include<cstdio>
#include<iostream>
#include<cstring>
#define LL long long
/*
***���1198 
***��״���鶯̬���� 
***ST�㷨���RMQ
***֧��A x�ڶ�β����һ����x
***Q L��ѯĩβL�����е����ֵ 
*/
using namespace std;
LL last;//��һ�εĴ�
LL lis[200005][18];
LL nums[200005];//start from 1
LL D,n;
int len;


LL ask(LL from,LL to){//RMQ��ѯ���ֵ 
	if(from>to) return -1;
	int L=to-from+1;
	int buf=0;
	while((1<<(buf+1))<=L){
		buf++;
	}//2^buf
	return max(lis[from][buf],lis[to-(1<<buf)+1][buf]);
}

LL modd(LL x){
	if(x>=0) return x%D;
	return (D-(-x)%D);
}

void add(int x){
	len++;
	nums[len]=modd(x+last);
	int b=0;
	while(len-(1<<b)+1>0){//���� [len-(1<<b)+1,b] 
		LL le=len-(1<<b)+1;
		//if(lis[le][b]==-1){
		lis[le][b]=max(nums[len],ask(le,len-1));
		b++;
	}
	return;
}


int main(){
	memset(lis,-1,sizeof(lis));
	scanf("%d%d",&n,&D);
	for(int kk=1;kk<=n;kk++){
		char ins;LL x;
		cin>>ins;
		scanf("%lld",&x);
		if(ins=='A'){
			add(x);
		}else{
			last=ask(len-x+1,len);
			cout<<last<<endl;
		}
	}
	return 0;
}
