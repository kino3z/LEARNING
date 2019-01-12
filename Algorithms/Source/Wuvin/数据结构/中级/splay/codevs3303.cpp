/*
Ϊʲôֻ��splay�ܽ������䷭ת������
��Ϊ���䷴ת����Ҫ���ǣ����ұ��ֻ�ܴ���һ�����ϡ�
�߶�����bit��Treap�����һ��������logn���������Բ�ֹһ���㡣
��ô�ܷ�����splay����ѡ������һ�����������һ�������������
�ռ�O(n)������k���أ����У�splay����ά�����䣬����val���̶�Ϊ���±� 
*/ 
#include<cstdio>
#include<iostream>
#define N 100005
using namespace std;
int n,m,root;
//---splay----------
int fa[N],son[N][2],val[N],tag[N],size[N];
const int L=0,R=1;
inline void update(int &k){
	if(k==0) return; 
	size[k]=size[son[k][L]]+size[son[k][R]]+1;
}
inline void pushdown(int &k){//ò����ת��ǲ������û�->�ȼ��ڽ�������Ϊ���� 
	if(k==0||tag[k]==0) return;
	tag[son[k][L]]^=1;tag[son[k][R]]^=1;swap(son[k][L],son[k][R]);tag[k]=0;
}
inline void rotate(int x,int &k){//������ѡ
	int y=fa[x],z=fa[y];
	int s=son[y][L]==x? L:R;
	fa[x]=fa[y];fa[y]=x;son[y][s]=son[x][s^1];
	fa[son[y][s]]=y;son[x][s^1]=y;
	if(y==k){k=x;}
	else{int s2=son[z][L]==y? L:R;son[z][s2]=x;}
	update(y);update(x);update(z);
}
void splay(int x,int &k){
	int y,z;
	while(x!=k){
		y=fa[x];z=fa[y];pushdown(fa[z]);pushdown(z);pushdown(y);pushdown(x);
		if(y!=k){
			if((son[y][L]==x)^(son[z][L]==y)) rotate(x,k);//zig 
			else rotate(y,k);//zag fa[y]==k?
		}
		rotate(x,k);//zig fa[x]==k?
	}
}
int findkth(int k,int x){
	pushdown(k);int t=size[son[k][L]];
	if(t+1==x)	return k;
	else if(t<x)return findkth(son[k][R],x-t-1);
	else return findkth(son[k][L],x);
}
void turn(int l,int r){
	l=findkth(root,l);r=findkth(root,r+2);
	splay(l,root);
	splay(r,son[root][R]);
	tag[son[son[root][R]][L]]^=1;
}
void DFS(int k){
	if(k==0) return;
	pushdown(k);
	DFS(son[k][L]);
	if((val[k]!=0)&&(val[k]!=n+1)) printf("%d ",val[k]);
	DFS(son[k][R]);
}
//----splay---------
int main(){
	scanf("%d%d",&n,&m);int v=0;
	for(int i=1;i<=n+2;i++){
		son[i][L]=i-1;son[i][R]=0;fa[i]=i+1;val[i]=i-1;size[i]=i;
	}fa[n+2]=0;root=n+2;//���˹��첢�첻�˶��� 
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		turn(l,r);
	}
	DFS(root);
	return 0;
} 
