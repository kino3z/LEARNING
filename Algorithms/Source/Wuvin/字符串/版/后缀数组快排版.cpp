#include<bits/stdc++.h>
using namespace std;
/*------------------------------------------
nlogn*logn 
------------------------------------------*/
char s[105];
int len;
int sa[105];//���յĺ�׺���� 
int f1[105],f2[105];int n1;//�ϴ�������f1 ��������װ��f2
bool cmp(int a,int b){//ָ���a��ָ���b˭��   ��n1����������Ԫ�ؾ������2^��n-1) 
	if(f1[a]!=f1[b]) return f1[a]<f1[b];
	int dd=1<<(n1-1);//����Ӽ�����λ���� 
	if(b+dd>len) return false;
	if(a+dd>len) return true;
	return f1[a+dd]<f1[b+dd];
}
int tj[105];//ͳ��  105ΪԪ������ 
void build(){
	for(int i=0;i<len;i++){
		tj[s[i]-'a']=1;
	}
	for(int i=1;i<105;i++){
		tj[i]+=tj[i-1];
	}
	for(int i=0;i<len;i++){
		f1[i]=tj[s[i]-'a'];
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
int main(){
	char sr[]="aabaaaab";
	for(int i=0,len1=strlen(sr);i<len1;i++){
		s[i]=sr[i];
	}
	len=strlen(s);
	build();
	for(int i=0;i<len;i++){
		printf("%d",sa[i]);
	}
	return 0;
}
