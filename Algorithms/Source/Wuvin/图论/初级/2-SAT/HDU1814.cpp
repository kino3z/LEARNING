#include<bits/stdc++.h>
using namespace std;
//////////////WARNING WARNING WARNING THERE ARE PLENTY GROUPS OF DATAS 
/*-------����ͼģ��-------*/
const int INF=999999;
struct edge{
	int from,to,dis;edge(int fr,int t,int di):from(fr),to(t),dis(di){}
};
vector<edge> e;int e_len;
vector<int> node[16005];
void addedge(int from,int to,int len){//���� �з���ͼ 
	e.push_back(edge(from,to,len));node[from].push_back(e_len++);
}
/*---------------------*/
int n,m;
int online[16005];//0-null 1-red 2-bule 
int buf[16005];int cnt=0; 
///////////////////////2-SAT
bool DFS(int u){
	online[u]=1;online[u^1]=2;buf[cnt++]=u;buf[cnt++]=u^1; 
	for(int i=0,len=node[u].size();i<len;i++){
		edge& ed=e[node[u][i]];
		if(online[ed.to]==0){
			if(!DFS(ed.to)) return false;
		}else if(online[ed.to]==2){
			return false;
		}
	}
	return true; 
}
/*///////////////////////
�����ƿڴ���һ��HDU
����������㲻˵
�������ֵ����ֶԴ��˾Ÿ�Сʱ����
�������������� 
//////////////////////*/
int main(){
	while(scanf("%d%d",&n,&m)==2){//Ϊ�˷���ȫ����ż�һ
		memset(online,0,sizeof(online));
		e.clear();
		e_len=0;for(int i=0;i<=16000;i++) node[i].clear();
		for(int f,t,i=1;i<=m;i++){
			scanf("%d%d",&f,&t);f--;t--;
			if(f==t){
				online[f]=2;online[f^1]=1;continue;
			}
			addedge(f,t^1,0);//���빲��
			addedge(t,f^1,0);//����
		}
		bool fl=true;
		for(int i=0;i<2*n;i++){
			if(online[i]==0){
				cnt=0;
				if(DFS(i)==false){
					while(cnt--){
						online[buf[cnt]]=0;
					}
					if(false==DFS(i^1)){
						printf("NIE\n"),fl=false;break;
					}
				}
			}
		}
		if(!fl) continue;
		for(int i=0;i<2*n;i++){
			if(online[i]==1){
				printf("%d\n",i+1);	
			}
		}
	}
	return 0;
}
