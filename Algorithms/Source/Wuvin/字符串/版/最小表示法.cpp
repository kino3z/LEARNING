#include<cstdio>
#include<cstring>
using namespace std;
/*��С��ʾ��*/
/*----------------------
��С��ʾ�������ڶ�һ���ַ����Ӳ�ͬλ�ÿ�ʼ�Ĵ��Ƚϴ�С
һֱ������С��
�ܿ�ͬ��ƥ��
ȷ��һ����ǰһ���ں� 
-----------------------*/
int getM(char *s){//������С��ʾ����ʼ���±꣨start from 0�� 
	int len=strlen(s);
	int p=0;int q=1;
	int k=0;int p1=0,q1=1;
	while(k<=len){
		if(p==q) q++;
		p1=p+k;q1=q+k;
		if(p1>=len) p1-=len;
		if(q1>=len) q1-=len;
		if(s[p1]>s[q1]){
			p+=k+1;//����ϸ��ĥ 
			k=0;
			if(p>len) break;//��������ƥ���� 
		} else if(s[p1]<s[q1]){
			q+=k+1;
			k=0;
			if(q>len) break;
		}else{
			k++;
		}
	}
	return p;//p==q
}
int main(){
	char c[]="cbba";
	printf("%d",getM(c));
	return 0;
}
