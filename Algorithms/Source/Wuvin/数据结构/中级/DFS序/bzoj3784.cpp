//�����������Ǹ�����Ķ���
//���ϵ�·�����Ⱦͱ�ͶӰ����������
//�����·�ͳ�������Ӷκ�
//����ͳ��˳������� 
//�����ʱ�Ȩ��û�й�ϵ�����������Ͽ������� 
//�����������벻��д
//�ɴ��ÿ�����ٽ�һ����
//�ȵ�DFS���ܼ��á�������bug����
//�����Լ�����һ�¾�֪��������
//���xor���ǿ��Եġ����ֻ�ܽ����root��ʼ��·��
//�����������lca����ô���ܼ���RMQ������Ҫ��������
/*
������⣺
����Ϊ�ȵ�֣�Ȼ��ÿһ����ά��dfs��������ľ��룬
����Ԫ��[x,l,r,lev]��ʾ��lev��·����˵�Ϊx��
�Ҷ˵�Ϊ��ǰ��dfs����l��r������һ�������ֵ��
ÿ����ȡ��ֵ��������ֳ�������ͨ���߶���ά���������ֵ��λ�á�
ʱ�临�Ӷ�O(nlog^2n)���ռ临�Ӷ�O(nlog^2n)����ž��������ɡ����� 
�ؼ�����DFS��������� ����

�����Ĳ���д���������� 
*/ 
#include<cstdio>
#include<vector>
#include<queue>
#define N 50005
using namespace std;
const int INF=0x3f3f3f3f;
int n,m; 
int dis[20*N];
inline int cal(int x,int maxn){
	return dis[x]+dis[maxn];
}
struct anss{
	int x,fr,to;
	int maxn;//��¼���ֵλ�� 
	inline bool operator <(const anss &b)const{
		return cal(x,maxn)<cal(b.x,b.maxn);
	}
}buf[N*20];
int bufcnt;
struct edge{
	int f,t,dis;
};
struct nodes{
	int size,st,en;
	vector<edge> x;
}node[N];
//-----------------------------------------
int st[20][20*N];int log2[N];
void build_st(int fr,int to){
	for(int i=fr;i<=to;i++){
		st[0][i]=i;
	}
	for(int i=1;(1<<i)<=n;i++){ 
		for(int j=fr;j<=to-(1<<i)+1;j++){
			int ta=st[i-1][j];int tb=st[i-1][j+(1<<(i-1))];
			st[i][j]=dis[ta]>dis[tb]? ta:tb;
		}
	}
}
int getmax(int fr,int to){
	if(fr>to) return 0;
	int t=log2[to-fr+1];
	int ta=st[t][fr];int tb=st[t][to-(1<<t)+1];
	return dis[ta]>dis[tb]? ta:tb;
}
//--------------------------------------------
//����ο�ʼ
//��ΪҪ���������Ϣ
//Ϊ���ٶȺͷ���
//ȫ��ѹ��һά 
int vis[N],root,hf;
int get_root(int u,int fr){
	int t=1;
	for(int i=0,len=node[u].x.size();i<len;i++){
		edge &d=node[u].x[i];
		if(d.t==fr||vis[d.t]==1) continue;
		t+=get_root(d.t,u);
	}
	if(t>=hf&&root==-1) root=u;
	return t;
}
int cnt;
int DFS(int u,int fr,int diss){
	node[u].st=++cnt;
	dis[cnt]=diss;node[u].size=1;
	for(int i=0,len=node[u].x.size();i<len;i++){
		edge &d=node[u].x[i];
		if(d.t==fr||vis[d.t]==1) continue;
		node[u].size+=DFS(d.t,u,diss+d.dis);
	}
	node[u].en=cnt;
	return node[u].size;
}
void solve(int u){//u������ Ҫ����dis��st 
	if(hf==0) return;
	//-----------�ȴ���--------
	vis[u]=1;
	DFS(u,0,0);
	//-------------------------
	buf[++bufcnt]=(anss){node[u].st,node[u].st+1,cnt,0};
	//work
	for(int i=0,len=node[u].x.size();i<len-1;i++){
		edge &d=node[u].x[i];
		if(vis[d.t]==1) continue;
		for(int j=node[d.t].st;j<=node[d.t].en;j++){
			buf[++bufcnt]=(anss){j,node[d.t].en+1,cnt,0};
		}
	}
	//-------------------------
	for(int i=0,len=node[u].x.size();i<len;i++){
		edge &d=node[u].x[i];
		if(vis[d.t]==1) continue;
		root=-1;hf=node[d.t].size/2;
		get_root(d.t,u);
		solve(root);
	}
	//-------------------------
}
//------------------
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int f,t,d;
		scanf("%d%d%d",&f,&t,&d);
		node[f].x.push_back((edge){f,t,d});
		node[t].x.push_back((edge){t,f,d}); 
	} 
}
//--------------------
int main(){
	init();log2[1]=0;
	for(int i=2;i<N-2;i++){
		log2[i]=log2[i>>1]+1;
	}
	root=-1;hf=n/2;
	get_root(1,0);
	solve(root);
	build_st(1,cnt);
	for(int i=1;i<=bufcnt;i++) buf[i].maxn=getmax(buf[i].fr,buf[i].to);
	priority_queue<anss> pq(buf+1,buf+bufcnt+1);
	for(int i=1;i<=m;i++){
		anss t=pq.top();
		printf("%d\n",cal(t.x,t.maxn));
		pq.pop();
		if(t.maxn-1>=t.fr){
			int tt=getmax(t.fr,t.maxn-1);
			pq.push((anss){t.x,t.fr,t.maxn-1,tt});
		}
		if(t.maxn+1<=t.to){
			int tt=getmax(t.maxn+1,t.to);
			pq.push((anss){t.x,t.maxn+1,t.to,tt});
		}
	}
	return 0;
}
