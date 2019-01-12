#include<cstdio>
#include<vector>
using namespace std;
const int INF=999999;
/*-------����ͼģ��-------*/
struct edge{
	int from,to,dis;edge(int fr,int t,int di):from(fr),to(t),dis(di){}
};
vector<edge> e;int e_len;
vector<int> node[10005];
void addedge(int from,int to,int len){//����
	e.push_back(edge(from,to,len));node[from].push_back(e_len++);
}
/*-------------���˰壨δ���ã���bug��-----------*/
int tp[10005];int len_tp=1;

int vis[10005];
void DFS1(int u){//��������ָ���Լ��ĵ㣬Ȼ�������ɾ�������ɾ�Լ���
	vis[u]=1;
	for(int i=0,len=node[u].size();i<len;i++){
		edge& ed=e[node[u][i]];
		if(vis[ed.to]==0) DFS1(ed.to);
	}
	tp[len_tp++]=u;
}
/*-------------�������ж���ͨ��-----------------*/
int lt[10005];int cnt_lt=1;
void DFS2(int u,int num){
	lt[u]=num;
	for(int i=0,len=node[u].size();i<len;i++){
		edge& ed=e[node[u][i]];
		if(lt[ed.to]==0) DFS2(ed.to,num);
	}
}
//--------------------------------------------------
int n,m;
void init(){
	scanf("%d%d",&n,&m);
	for(int f,t,i=1;i<=m;i++){
		scanf("%d%d",&f,&t);
		addedge(f,t,0);//���ż�ͷ�����ߺ��ֻ��ٴη���ʵ�ã����Ըɴ෴������
	}
	
}

int ele[10005];//���Ϊ��ͨ����
int du[10005];
int all=0;
int main(){
	init();
	for(int i=1;i<=n;i++){//���ɷ���������
		if(vis[i]==0)
			DFS1(i);
	}
	for(int i=1;i<=n;i++){
		if(lt[tp[i]]==0){
			DFS2(tp[i],cnt_lt++);
		}
	}
	
	for(int i=1;i<=n;i++){
		printf("%d ",lt[i]);
	} 
	return 0;
}
