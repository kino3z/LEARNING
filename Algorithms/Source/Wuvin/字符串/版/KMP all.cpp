#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
int fp[200005];
int ppcd[200005];
int m,n,k;
char am[200005];
char bm[200005];
/*
***wkl ���취 
*/
void build_demo(char *demo,int *f){
	int p1,p2;
	int len=strlen(demo);
	p1=0;
	memset(f,0,sizeof(f));
	f[1]=f[0]=0;p1++;
	while(p1<=len){
		int x=0;
		int save=p1;
		p2=0;
		while(demo[p1]==demo[p2]&&demo[p1]){
			x++;p1++;p2++;
		}
		for(int i=x;i>=0;i--){
			f[p1-(x-i)]=i;
		}
		p1++;
	}
	return ;
}

/*
***lrj��̬���취 
*/
void build_demo1(char *demo,int *f){
	int len=strlen(demo);
	f[0]=f[1]=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<len;i++){
		int p=f[i];
		while(p&&demo[p]!=demo[i]) p=f[p];
		//f[i+1]=(p==0)? 0:p+1;  ����   aaa
		f[i+1]=(demo[p]==demo[i]) ? p+1:0; 
	}
}
/*
***���Խ�� ������ͬ 
*/





/*
***��T����p ʧ������Ϊf 
***���سɹ�ƥ��Ŀ�ͷ
***ʧ�ܷ���-1 
*/
int pipei(char *T,char *p,int *f){
	int lent=strlen(T);int lenp=strlen(p);
	build_demo1(p,f);
	int ypp=0;//��ƥ��ĸ��� 
	for(int i=0;i<lent;i++){//����ƥ��yppλ 
		while(ypp&&p[ypp]!=T[i]) ypp=f[ypp];//����ƥ��  �ٵ�û��ϵ �ص���Ҫƥ�� 
		if(p[ypp]==T[i]) ypp++;//�Ե� ƥ��ɹ� ƥ����һλ
		if(ypp==lenp) return i-lenp+1;//ָ��ͷ 
	}
	return -1; 
}


int main(){
	scanf("%d%d",&m,&n);
	return 0;
}
