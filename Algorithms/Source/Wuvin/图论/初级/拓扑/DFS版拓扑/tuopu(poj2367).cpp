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
/*-------------���˰�-----------*/
int vis[10005];
void DFS(int u){//��������ָ���Լ��ĵ㣬Ȼ�������ɾ�������ɾ�Լ���
	vis[u]=1;
	for(int i=0,len=node[u].size();i<len;i++){
		edge& ed=e[node[u][i]];
		if(vis[ed.to]==0) DFS(ed.to);
	}
	printf("%d ",u);
}
/*------------------------------*/
int n,m;
void init(){
	scanf("%d",&n);
	for(int i=1,c;i<=n;i++){
		do{
			scanf("%d",&c);
			if(c!=0){
				addedge(c,i,0);//���ż�ͷ������
			}else{
				break;
			}
		}while(1);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
			DFS(i);
	}
}

int ele[10005];//���Ϊ��ͨ����
int du[10005];
int all=0;
int main(){
	init();
	return 0;
}
