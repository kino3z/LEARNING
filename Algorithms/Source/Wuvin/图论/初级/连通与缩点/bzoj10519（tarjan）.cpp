#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
/*-------����ͼģ��-------*/
const int INF=999999;
struct edge{
	int from,to,dis;edge(int fr,int t,int di):from(fr),to(t),dis(di){}
};
vector<edge> e;int e_len;
vector<int> node[10005];
void addedge(int from,int to,int len){//����
	e.push_back(edge(from,to,len));node[from].push_back(e_len++);
}
/*-------------�������ж���ͨ��-----------------*/
int lt[10005],vis[10005];//���������ͨ�����ı��,��һ�η��ʵ�ʱ��� 
int lt_cnt,clk_cnt;//ʱ�� 0
int round[10005],mint[10005];//mint-���Ե������͵�ʱ��� 
stack<int> x;
int DFS(int u){//���㣬���ؿ��Ե����ʱ����С��
	mint[u]=vis[u]=clk_cnt++;
	int ret=vis[u];
	x.push(u);
	for(int i=0,len=node[u].size();i<len;i++){
		edge &ed=e[node[u][i]];
		if(lt[ed.to]!=0) continue;//������Ҫ ���õ�δ��ɼ��� 
		if(vis[ed.to]!=0){
			ret=min(ret,mint[ed.to]);//ע����mint[ed.to] 
		}else{
			int t=DFS(ed.to);
			ret=min(ret,t);
		}
	}
	if(ret==vis[u]){
		int p=0;lt_cnt++;
		do{
			p=x.top();x.pop();
			lt[p]=lt_cnt;
		}while(p!=u);
	}
	mint[u]=ret;
	return ret;
}
/*------------------------------*/
int n,m;
void init(){
	clk_cnt=lt_cnt=0;
	scanf("%d%d",&n,&m);
	for(int f,t,i=1;i<=m;i++){
		scanf("%d%d",&f,&t);
		addedge(f,t,0);
	}
}

int ele[10005];//���Ϊ��ͨ����
int du[10005];
int all=0;
int main(){
	init();
	for(int i=1;i<=n;i++){//���ɷ���������
		if(lt[i]==0)
			DFS(i);
	}
	
	all=lt_cnt;int ans=0;int num=0;
//���Ǽ��߿���
	for(int i=0,len=e.size();i<len;i++){
		edge &ed=e[i];
		if(lt[ed.to]!=lt[ed.from]){
			du[lt[ed.from]]++;
		}
	}
	for(int i=1;i<=n;i++) ele[lt[i]]++;
	int ans2=0;
	for(int i=1;i<=all;i++){
		if(du[i]==0){
			num++;ans=i;
		}
	}
	if(num==1){
		printf("%d",ele[ans]);
	}else{
		printf("0");
	}
	
	return 0;
}
