/*
CLJ��һ��
�ַ�������С��ʾ
��ĿZOJ1729 
����дд�� 
*/ 
#include<cstdio>
#include<iostream>
using namespace std;
char s[200005];int n;
struct SAM{
	int par,len;//par�ǣ�S������ĺ�׺���ϵģ����� final-�Ƿ�����̬ 
	int ne[30];
}sam[400005];
int cnt,root,last;
void build(){
	root=++cnt;last=root;sam[root]=sam[0];
	for(int i=1;i<=n;i++){
		//���һ���ַ���
		//��wk����pq,��Ȼ˭�ֵ���p,q,nq,np,woc
		int w=last;int nw=++cnt;sam[nw]=sam[0];sam[nw].len=sam[w].len+1;int ch=s[i]-'a';//�½��ڵ� 
		while(w&&sam[w].ne[ch]==0) sam[w].ne[ch]=nw,w=sam[w].par; //���� 
		if(w==0){//��ʼ��nw�Ҹ��� 
			sam[nw].par=root;//ֻ������û��ѡ 
		}else{
			int k=sam[w].ne[ch];
			if(sam[k].len==sam[w].len+1){//situation 1 
				sam[nw].par=k;
			}else{
				int lca=++cnt;//�½���������lca
				sam[lca]=sam[k];sam[lca].len=sam[w].len+1;
				sam[k].par=sam[nw].par=lca;
				while(w&&sam[w].ne[ch]==k) sam[w].ne[ch]=lca,w=sam[w].par;//Ϊʲô 
			}
		}
		last=nw;//���ˣ� 
	}
}
void work(){
	//ÿ������С���ߣ��ſ�������ѹλ
	int si=0,p=root;
	for(int i=1,go;i<=n/2;i++){
		for(int j=0;j<26;j++){
			if(sam[p].ne[j]){go=j;break;}
		}
		p=sam[p].ne[go];
	}
	printf("%d\n",sam[p].len-n/2);
	cnt=0;
}
void outit(){//�����׺�Զ��������� ��par��//graph��������ֶ����� 
	for(int i=1;i<=cnt;i++){
		for(int j=0;j<=25;j++){
			if(sam[i].ne[j]!=0){
				printf("%d %d %c\n",i,sam[i].ne[j],j+'a'); 
			} 
		}
	} 
	printf("par\n")
	for(int i=1;i<=cnt;i++){
		printf("%d %d\n",i,sam[i].par);
	} 
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) s[n+i]=s[i];
		n+=n;
		build();
		work();
		//outit();
	}
	return 0;
} 
