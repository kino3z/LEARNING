#include<cstdio>
#include<iostream>
#include<cstdlib>
#define N 200005
using namespace std;
const int L=0,R=1;
int n,m,cnt,root;
int name[N],size[N],son[N][2],pri[N];//ֻҪ�ɹ����� key��û�б�Ҫ��
inline void update(int k){
    size[k]=size[son[k][L]]+size[son[k][R]]+1;
}
inline void turn(int &k,int from_side){
    int t=son[k][from_side];
    son[k][from_side]=son[t][from_side^1];son[t][from_side^1]=k;update(k);k=t;
}
void insert(int &k,int _name,int place){//place �ڵ�ǰ������Ϊplace����placeΪ0��������
    if(k==0){
        k=++cnt;name[k]=_name;pri[k]=rand();size[k]=1;son[k][L]=son[k][R]=0;return;
    }
    int m=size[son[k][L]]+1;
    int side=place<m? L:R;
    place-=m*side;
    insert(son[k][side],_name,place);
    size[k]++;
    if(pri[son[k][side]]>pri[k]) turn(k,side);//��side����̧����
    else update(son[k][side]);
}
void DFS(int u){
    if(son[u][L]!=0) DFS(son[u][L]);
    printf("%d ",name[u]);
    if(son[u][R]!=0) DFS(son[u][R]);
}
int main(){
	while(scanf("%d",&n)==1){
        cnt=0;root=0;
        for(int pl,na,i=1;i<=n;i++){
            scanf("%d%d",&pl,&na);
            insert(root,na,pl);
        }
        DFS(root);
        puts("");
    }
	return 0;
} 
