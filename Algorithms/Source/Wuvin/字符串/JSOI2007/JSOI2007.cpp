#include<bits/stdc++.h>
#define N 100005
#define M 256
using namespace std;
/*------------------------------------------
nlogn*logn 
------------------------------------------*/
char s[N];
int len;
int sa[N];//���յĺ�׺���� 
int f1[N],f2[N];int n1;//�ϴ�������f1 ��������װ��f2
bool cmp(int a,int b){//����ר��cmp 
	if(f1[a]!=f1[b]) return f1[a]<f1[b];
	int a1=(a+(1<<(n1-1)))%len;
	int b1=(b+(1<<(n1-1)))%len;
	return f1[a1]<f1[b1];
}
int tj[N];//ͳ��  MΪԪ������ 
void build(){
	for(int i=0;i<len;i++){
		tj[s[i]]=1;
	}
	for(int i=1;i<M;i++){
		tj[i]+=tj[i-1];
	}
	for(int i=0;i<len;i++){
		f1[i]=tj[s[i]];
	}
	//----��ʼ�����-------
	for(int i=0;i<len;i++){
		f2[i]=i;
	}
	n1=1;
	for(int k=1;k<len;k<<=1,n1++){
		sort(f2,f2+len,cmp);
		int cnt=1;tj[0]=1;bool fl=true;
		for(int i=1;i<len;i++){
			if(cmp(f2[i-1],f2[i])){
				cnt++;
			}else{
				fl=false;
			}
			tj[i]=cnt;
		}
		for(int i=0;i<len;i++){
			f1[f2[i]]=tj[i];
		}
		if(fl) break;
	}
	//----�������----------
	for(int i=0;i<len;i++){
		sa[i]=f1[i];
	}
}
char ans[N];
int a[N];
int main(){
	memset(ans,0,sizeof(ans));
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	memset(sa,0,sizeof(sa));
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	scanf("%s",s);
	len=strlen(s);
	build();
	
	//����������� abab 
	for(int i=0;i<len;i++){
		a[sa[i]]++;
	}
	for(int i=1;i<=len;i++){
		a[i]+=a[i-1];
	}
	for(int i=len-1;i>=0;i--){
		sa[i]=a[sa[i]]--;
	}
	/*
	for(int i=0;i<len;i++){
		printf("%d",sa[i]);
	}*/
	
	
	ans[sa[0]-1]=s[len-1];
	for(int i=1;i<len;i++){
		ans[sa[i]-1]=s[i-1];
	}
	for(int i=0;i<len;i++){
		printf("%c",ans[i]);
	} 
	//printf("%s",ans);
	return 0;
}
