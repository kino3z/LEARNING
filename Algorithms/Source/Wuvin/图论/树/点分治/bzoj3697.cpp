/*
ͻȻ����ԭ���ҵĵ����һֱ�����
û�а������Ļ��֡����Ա�����
����ʱ����̫�� 
�о������һ�㶼����д 
*/ 
#include<cstdio>
#include<vector>
#define N 100005
using namespace std;
int n,m,ans;
//-----------------
struct nodes{
	int color,size;
	vector<int> x;
}node[N];
//-----------------
int vis[N],root,hf;//�������Ļ��� 
int DFS(int u,int fr){//������ 
	node[u].size=0;
	for(int i=0,len=node[u].x.size();i<len;i++){
		if(node[u].x[i]!=fr&&vis[node[u].x[i]]!=1){
			node[i].size+=DFS(node[u].x[i],u);
		}
	}
	if(node[u].size>=hf&&u==-1) root=u;
	return node[u].size;
}
//-----------------
struct msg{
	int anc,dis,reset;//��������������ֵ�͡��Ƿ�����Ϣ�� 
}source[N];
int gxy[N*2];//N==0 -N~0~N��ʵ�����Ͽ�һ��N�͹��ˣ���Ϊ������ 
inline void make_mark(int fr,int to,int f){
	for(int i=fr;i<=to;i++){
		gxy[source[i].dis]+=f;
	}
}
int calc(int fr,int to){
	make_mark(fr,to,1);
	for(int i=fr;i<=to;i++){
		
	}
}
int DFS2(int u,int anc,int fr){//˳�����������С����  �����Ϣ�����е��Ѵ�����Ͷ�� 
	
}
void solve(int u){
	//--------------�ȴ��� 
	int buf=1;
	for(int i=0,len=node[u].x.size();i<len;i++){
		if(vis[node[u].x[i]]!=1){//�ռ���Ϣ���� 
			DFS2(node[u].x[i],node[u].x[i],u);//Ԥ��������size��Ϣ
			int t=node[node[u].x[i]].size; 
			ans-=calc(buf,buf+t-1);//��ȥ�������ظ� 
			buf+=t;//�������� 
		}
	}
	source[buf].dis=0;source[buf].reset=0;
	ans+=calc(1,buf);//ȫ���䴦�� 
	//--------------�ٴ������� 
	vis[u]=1;
	for(int i=0,len=node[u].x.size();i<len;i++){
		if(vis[node[u].x[i]]!=1){
			root=-1;hf=node[node[u].x[i]].size/2;
			DFS(node[u].x[i],u);
			solve(root);
		}
	}
	//--------------
}
//-----------------
void init(){
	
} 
//-----------------
int main(){
	init();
	root=-1;hf=n/2;
	DFS(1,0);
	solve(root);
	printf("%d\n",ans); 
	return 0;
}
