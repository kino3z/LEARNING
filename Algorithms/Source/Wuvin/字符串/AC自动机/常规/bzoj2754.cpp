/*
�������ϵĵ���
�Ǵ����ƺ����������
ʹ��map�����ַ�����
����ʧ��ʱҪ��������ʧ�����
����ֱ��ʧ������������ 

���˲�ԭ���õ������Ľ�
failͼ��ac�Զ������Ż��棩 
��Ҫ��while�Ĳ���ac�Զ��� 

����д
ֱ�ӱ������漣
WA �� 
*/ 
#include<cstdio>
#include<map>
#include<iostream>
#include<queue>
#define N 1000005
using namespace std;
int miaobuf,miao_word[N];
int dianbuf,dian_word[N];
struct name_miao{
	int st1,en1;
	int st2,en2;
	int ans;
}name[20005];
int n,m,root,cnt;
//-------------------------
//-------------------------
struct node{
	int p,times,f,fa;//times-����Ϊ�Ӵ���β�Ĵ���(name�Ľ�β) f-fail �Ż�����
	vector<int> name; 
	int checks;//���㵽�Ĵ��� 
	map<int,int> mp;
}a[N];
//-------------------------
//-------------------------
int ans_a[50005];//���㵽�Ĵ��� 
void insert(int &k,int st,int en,const int &na){
	if(k==0) k=++cnt,a[k].p=st;
	if(st==en) a[k].times++,a[k].name.push_back(na);
	else{
		map<int,int>::iterator itr=a[k].mp.find(dian_word[st+1]);
		if(itr==a[k].mp.end()){
			int p=0;insert(p,st+1,en,na);a[k].mp[dian_word[st+1]]=p;
		}else{
			int p=itr->second;insert(p,st+1,en,na);
		}
	}
}
inline int get(int k,int p){
	map<int,int>::iterator itr=a[k].mp.find(p);
	if(itr==a[k].mp.end()) return 1;
	return itr->second;
}
int ifdian[N];//����һֻèһ�ε����ж�� 
int add(int k,int vi){//���� 
	ifdian[k]=vi;int ret=a[k].times;
	int p=a[k].f;
	while(p!=0&&ifdian[p]!=vi) p=a[p].f;
	if(p!=0){
		a[p].checks--;ret-=a[p].times;
	}
	int q=a[k].f;
	while(q!=p) {ifdian[q]=vi,q=a[q].f;}
	return ret;
}
int check(int st,int en,int vision){//miao_word
	int p=root,ret=0;
	for(int i=st;i<=en;i++){
		while(p!=0&&get(p,miao_word[i])==1) p=a[p].f;
		if(p==0) p=root;
		else p=get(p,miao_word[i]);
		if(ifdian[p]!=vision&&a[p].times!=0){
			ret+=add(p,vision); a[p].checks++;
		}
	}
	return ret;
}
int BFSx[N],bcnt;
void getfail(){
	queue<int> p;
	a[root].f=0;
	for(map<int,int>::iterator itr=a[root].mp.begin();itr!=a[root].mp.end();itr++){
		a[itr->second].f=root;p.push(itr->second);a[itr->second].fa=root;
	}
	while(!p.empty()){
		int u=p.front();p.pop();
		BFSx[++bcnt]=u;
		int j=a[u].fa;
		if(j!=root){//���и��ڵ���ΧһȦ 
			j=a[j].f;
			int tt=get(j,dian_word[a[u].p]);
			while(tt==1&&j!=1){
				j=a[j].f;tt=get(j,dian_word[a[u].p]);
			}
			a[u].f=tt;
		}
		if(a[a[u].f].times!=0) a[u].times+=a[a[u].f].times;
		for(map<int,int>::iterator itr=a[u].mp.begin();itr!=a[u].mp.end();itr++){//BFS
			a[itr->second].fa=u;p.push(itr->second);
		}
	}
}
void getall(){
	for(int i=bcnt;i>=1;i--){
		int p=BFSx[i]; 
		for(int i=0,len=a[p].name.size();i<len;i++){
			ans_a[a[p].name[i]]=a[p].checks;
		}
		a[a[p].f].checks+=a[p].checks;
	}
}
//-------------------------
int init(){
	scanf("%d%d",&n,&m);
	int p=0;
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);
		for(int j=p;j<p+t;j++){
			scanf("%d",&miao_word[j]);
		}
		name[i].st1=p;name[i].en1=p+t-1;p+=t;
		scanf("%d",&t);
		for(int j=p;j<p+t;j++){
			scanf("%d",&miao_word[j]);
		}
		name[i].st2=p;name[i].en2=p+t-1;p+=t;
	}
	p=0;
	for(int i=1,t;i<=m;i++){
		scanf("%d",&t);
		for(int j=p;j<p+t;j++){
			scanf("%d",&dian_word[j]);
		}
		insert(root,p-1,p+t-1,i);
		p=p+t;
	}
	getfail();
	for(int i=1;i<=n;i++){
		name[i].ans=check(name[i].st1,name[i].en1,i);
		name[i].ans+=check(name[i].st2,name[i].en2,i);
	}
	getall();
	for(int i=1;i<=m;i++){
		printf("%d\n",ans_a[i]);
	}
	for(int i=1;i<n;i++){
		printf("%d ",name[i].ans);
	}
	printf("%d",name[n].ans);
}
//-------��mapʵ��--------- 
int main(){
	root=1,cnt=1;
	init();
	return 0;
} 
