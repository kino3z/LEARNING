/*-----------------------------------------------------*//*
zjoi 2015:������ս����Ϸ
����Ұ3924
�����long long 
����O(n)תΪ�и���
O(n*n)�������LCA
O(n*n)��ʼ���໥���� 

ÿһ�ּ���һ����O(n)
n����O��n^2��
 
�ܹ�(n*n*n) 
/*-------------------------------------------------------*/
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,q;
struct edge{
	int from,to,cost;
	edge(int fr,int to_,int cost_){
		from=fr;to=to_;cost=cost_;
	}
};
vector<edge> e;int len;
struct tree_nodes{
	//int father;
	vector<int> to;
	int sol;//the number of solders
	int dis[110];//��������� 
}map[110];
long long mincost;

void work(int u){
	queue<int> x;
	x.push(u);
	while(!x.empty()){
		int v=x.front();x.pop();
		for(int i=0,lens=map[v].to.size();i<lens;i++){
			edge& ed=e[map[v].to[i]];
			if(ed.to==u) continue;
			if(map[u].dis[ed.to]==0){
				map[u].dis[ed.to]=map[u].dis[ed.from]+ed.cost;
				x.push(ed.to);
			}
		}
	}
}
void init(){
	scanf("%d%d",&n,&q);
	for(int f,t,c,i=1;i<=n-1;i++){
		scanf("%d%d%d",&f,&t,&c);
		e.push_back(edge(f,t,c));
		map[f].to.push_back(len++);
		e.push_back(edge(t,f,c));
		map[t].to.push_back(len++);
	}
	for(int i=1;i<=n;i++){
		work(i);
	}
}

void recount(){
	long long fy=0;
	mincost=1;
	mincost<<=60;
	for(int i=1;i<=n;i++){
		fy=0;
		for(int j=1;j<=n;j++){
			fy+=map[j].sol*map[i].dis[j];
		}
		if(fy<mincost) mincost=fy;
	}
}

int main(){
	init();
	for(int i=1;i<=q;i++){
		int pl,army;
		scanf("%d%d",&pl,&army);
		map[pl].sol+=army;
		recount();//���¼���������  װ��mincost 
		printf("%lld\n",mincost);
	}
	return 0;
}



/******************************************************************
��ʾ������
105��10^5
.........
�һ���ʲô����˵���أ�
**********************************************************************/
 
