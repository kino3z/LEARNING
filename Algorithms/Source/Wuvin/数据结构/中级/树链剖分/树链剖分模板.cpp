/////////////-////////////////////////////
///ZJOI2008
///
//////////////////////////////////////////////
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#define N 100005
#define LL int
using namespace std;
//----------------------------------------------------
//�����ʷ�ά���� 
//��Ҫ��ά���� ���x��ֵΪ��father[x],x��,���ڵ�ֵΪ������ 
//----------------------------------------------------
struct edge{
	int from,to;
	edge(int from_,int to_){from=from_;to=to_;}
};
vector<edge> e;//������ 
int e_len=0;

int dbh[N];//��ı�� 
int xds[N];//�߶����������������   ��1��ʼװ�� 
struct node{
	int deep;//���  ���ڵ����Ϊ0 
	int father;//���ڵ���								* 
	//int tofa;//��father��·  ��ָ��b 			*
	int ance;//����������
	int h_s;//�ض��ӵı� 						*
	vector<int> sons;//����� ��ָ��b 			*�ض�����sons[0] 
	int size;//�ж����ӽڵ�  �����Լ� 			*
	LL wi;//Ȩֵ 
}tree[N];
//------------------------------------------------���ݽṹ------------------------
void addedge(int f,int t){
	e.push_back(edge(f,t));
	tree[f].sons.push_back(e_len++);
} 
//----------------------------�����ʷ�--------------------------------------- 
int DFS1(int u,int fa,int deep){//��һ�γ�ʼ��  u-�� from-���ı� 
	tree[u].father=fa;
	tree[u].deep=deep;
	int allson=1;
	int hvs=0;int maxwei=0;
	for(int i=0,a1=0,len=tree[u].sons.size();i<len;i++){
		if(e[tree[u].sons[i]].to!=tree[u].father){
			a1=DFS1(e[tree[u].sons[i]].to,u,deep+1);
			if(a1>maxwei){//��¼�ض��� 
				maxwei=a1;
				hvs=tree[u].sons[i];
				swap(tree[u].sons[i],tree[u].sons[0]); 
			}
			allson+=a1;
		}else{//delete
			swap(tree[u].sons[i],tree[u].sons[len-1]);
			tree[u].sons.pop_back();
			len--;i--;
		}
	}
	tree[u].size=allson;
	return allson;
}

int sl_len=1;//���ڵ��� 
void DFS2(int u,int zhong){//��ʼ���±��   zhong-�ǲ����ر߹�����  0-�� 
	if(!zhong){
		tree[u].ance=tree[tree[u].father].ance;
	}else{
		tree[u].ance=u;
	}
	dbh[u]=sl_len++;
	if(tree[u].size==1){
		return;
	}else{
		for(int i=0,len=tree[u].sons.size();i<len;i++){
			//bbh[tree[u].sons[i]]=sl_len++;
			DFS2(e[tree[u].sons[i]].to,i);
		}
	}
}


//--------------------------------�߶�������-------------------------------------------
//�߶�����δ��˺�д 
int xds_len=0;
struct xds_node{
	xds_node *left,*right;
	int begin,end,mid;
	LL he,amax;
	xds_node(int from,int to){//,int *a){//������xds������ 
		begin=from;end=to;he=0;
		if(begin==end){
			left=right=NULL;
			return;
		}else{
			mid=(begin+end)/2;
			left=new xds_node(from,mid);
			right=new xds_node(mid+1,to);
		}
	}
	
	int dian_change(int u,int zhi){//����� ���Ÿĵ�max����С/��� 
		if(begin==end&&end==u){
			int ret=zhi-he;
			tree[xds[begin]].wi=zhi;
			he+=ret;
			amax=zhi;
			return ret;
		}else{
			int ret=8888888;
			if(u<=mid){
				ret=left->dian_change(u,zhi);
			}else{
				ret=right->dian_change(u,zhi);
			}
			he+=ret;
			amax=max(left->amax,right->amax);
			return ret;
		}
	}
	
	LL sum(){
		if(begin==end){
			he=tree[xds[begin]].wi;
		}else{
			he=left->sum()+right->sum();
		}
		return he;
	}
	
	LL gomax(){
		if(begin==end){
			amax=tree[xds[begin]].wi;
		}else{
			amax=max(left->gomax(),right->gomax());
		}
		return amax;
	}
	
	LL get_sum(int start,int to){//������� 
		if(begin==start&&end==to){
			return he;
		}else if(to<=mid){
			return left->get_sum(start,to);
		}else if(start>mid){
			return right->get_sum(start,to);
		}else{
			return left->get_sum(start,mid)+right->get_sum(mid+1,to);
		}
	}
	
	LL get_max(int start,int to){//������� 
		if(begin==start&&end==to){
			return amax;
		}else if(to<=mid){
			return left->get_max(start,to);
		}else if(start>mid){
			return right->get_max(start,to);
		}else{
			return max(left->get_max(start,mid),right->get_max(mid+1,to));
		}
	}
};
//---------------------------------֧�ֵĲ���----------------------------------------------
LL Qsum(xds_node &xd,int u,int v){
	int f1=tree[u].ance;int f2=tree[v].ance;
	LL ret=0;
	while(f1!=f2){
		int d1=tree[f1].deep;int d2=tree[f2].deep;
		if(d1<=d2){//̧��f2-v 
			ret+=xd.get_sum(dbh[f2],dbh[v]);
			v=tree[f2].father;
			f2=tree[v].ance;
		}else{//̧��f1-u 
			ret+=xd.get_sum(dbh[f1],dbh[u]);
			u=tree[f1].father;
			f1=tree[u].ance;
		}
	}
	ret+=xd.get_sum(min(dbh[u],dbh[v]),max(dbh[u],dbh[v]));
	return ret;
}

LL Qmax(xds_node &xd,int u,int v){
	int f1=tree[u].ance;int f2=tree[v].ance;
	LL ret=1<<31;
	while(f1!=f2){
		int d1=tree[f1].deep;int d2=tree[f2].deep;
		if(d1<=d2){//̧��d2 
			ret=max(ret,xd.get_max(dbh[f2],dbh[v]));
			v=tree[f2].father;
			f2=tree[v].ance;
		}else{
			ret=max(ret,xd.get_max(dbh[f1],dbh[u]));
			u=tree[f1].father;
			f1=tree[u].ance;
		}
	}
	//ret=max(ret,xd.get_max(min(dbh[u],dbh[v]),max(dbh[u],dbh[v])));
	ret=max(ret,xd.get_max(min(dbh[u],dbh[v]),max(dbh[u],dbh[v])));
	return ret;
}

void Qchange(xds_node &xd,int u,LL zhi){
	xd.dian_change(dbh[u],zhi);
}

//---------------------------------------------------------------------------------------
int n;
void trans(){
	for(int i=1;i<=n;i++){
		xds[dbh[i]]=i;//���ڵ��ϵ��߶��� 
	}
}
int main(){
	scanf("%d",&n);
	for(int f,t,i=1;i<n;i++){
		scanf("%d%d",&f,&t);
		addedge(f,t);
		addedge(t,f);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&tree[i].wi);
	}
	//----------��ʼ��---------- 
	DFS1(1,1,0);
	DFS2(1,1);
	trans();
	xds_node mxds(1,n);
	mxds.sum();
	mxds.gomax();
	//-----------let's work :-)----------
	int q;
	scanf("%d",&q);
	for(int k=1;k<=q;k++){
		char ins[8]={};
		scanf("%s",ins);
		int u,v;
		LL zhi;
		if(ins[1]=='M'){
			scanf("%d%d",&u,&v);
			printf("%d\n",Qmax(mxds,u,v));
		}else if(ins[1]=='S'){
			scanf("%d%d",&u,&v);
			printf("%d\n",Qsum(mxds,u,v));
		}else if(ins[1]=='H'){
			scanf("%d%d",&u,&zhi);
			Qchange(mxds,u,zhi);
		}
	}
}
