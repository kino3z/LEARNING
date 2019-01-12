/*-----------------------------------------------------
�������һ�����϶��ֵķ���
���Խ���ͨͳ����n^2�Ż���n log n 
------------------------------------------------------*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct edge{
	int f,to,dis;edge(int fr,int t,int di):f(fr),to(t),dis(di){}
};
vector<edge> e;int e_len;
struct tr{
	int x[3];//����ͳ��  ע�����ǵ� 
	vector<int> sons;
	int father;
	int leaf;//Ҷ�ڵ� 
}tree[20005];
void addedge(int from,int to,int len){
	e.push_back(edge(from,to,len));tree[from].sons.push_back(e_len++);
	e.push_back(edge(to,from,len));tree[to].sons.push_back(e_len++);
}
int n;
void DFS1(int u,int fa){
	tree[u].father=fa;tree[u].leaf=1;
	for(int i=0,len=tree[u].sons.size();i<len;i++){
		edge& ed=e[tree[u].sons[i]];
		if(ed.to==fa) continue;
		DFS1(ed.to,u);tree[u].leaf=0;
	}
}
int ansall;//��Ϊ������� 
void DFS2(int u){//������Ԫ��
	if(tree[u].leaf==1){
		tree[u].x[0]=1;return;
	}
	for(int i=0,len=tree[u].sons.size();i<len;i++){
		edge& ed=e[tree[u].sons[i]];
		if(ed.to==tree[u].father) continue;
		DFS2(ed.to); 
	}
	int sum[3]={0,0,0};int ans2=0;
	for(int i=0,len=tree[u].sons.size();i<len;i++){
		edge& ed=e[tree[u].sons[i]];
		if(ed.to==tree[u].father) continue;
		for(int j=0;j<3;j++){
			sum[(j+ed.dis)%3]+=tree[ed.to].x[j];
		}
	}
	for(int i=0,len=tree[u].sons.size();i<len;i++){
		edge& ed=e[tree[u].sons[i]];
		if(ed.to==tree[u].father) continue;
		int ax[3];
		for(int j=0;j<3;j++){
			ax[(j+ed.dis)%3]=tree[ed.to].x[j];
		}
		for(int j=0;j<3;j++){
			/*
			int ys=tree[ed.to].x[j];//���ӽڵ�������Ϊj�ĸ���
			int qt=sum[(3-j)%3]-tree[ed.to].x[(-j-ed.dis+3000)%3];//�����ӽڵ���֮��Ը��� 
			ans2+=ys*qt;*/
			ans2+=ax[j]*(sum[(3-j)%3]-ax[(3-j)%3]);
		}
	}
	for(int j=0;j<3;j++){
		tree[u].x[j]=sum[j];
	}
	//ans2/=2;
	ans2+=sum[0]*2;tree[u].x[0]++;
	ansall+=ans2;
}
int gcd(int a,int b){//a<b
	if(b%a==0) return a;
	return gcd(b%a,a);
}

int main(){
	scanf("%d",&n);
	for(int f,t,d,i=1;i<n;i++){
		scanf("%d%d%d",&f,&t,&d);
		addedge(f,t,d);
	}
	DFS1(n,n);
	DFS2(n);
	int ans1=ansall+n;
	if(ans1==0){
		printf("0");return 0;
	}
	int ans2=n*n;
	int c=gcd(ans1,ans2);
	ans1/=c;ans2/=c;
	printf("%d/%d",ans1,ans2);
	return 0;
}
