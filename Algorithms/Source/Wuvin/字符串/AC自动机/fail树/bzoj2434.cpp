/*
����ʲô�Ŀ�������ô��ѽ������
���ˣ�������һ�������㷨�����ҵ���y��������trie���ϵ�·��
Ȼ������ÿһ�����failָ���ߣ�����ҵ�x�ͼ�1������failָ�뽨���Ĺ��̣���
�ɴ˿�����������˼ά����xΪ������������failָ�뵹�������ҵ����ٸ�y·���ϵĵ�
��˵��x��y�ϳ��ֹ����Ρ�ÿ�ζ�dfs��һ�飬�������Եõ�70�֡�
������ǰdfs������fail����ÿ���ڵ����ȵ����ʱ�����󵽴�ʱ�䣬
��Ϊ��dfs���Կ�ʼʱ�䡪������ʱ���ڶ�����ͬһ�������ϣ���������״����ȥά����AC��
����һЩϸ�ڣ��ڽ�ͼʱһ�߶���һ��ͽ���tire��AC�Զ�����������P�ͱ�ǣ�����B�ͻ���һ��
������ǰ�ڵ�ĸ��׽ڵ㣩������Сд��ĸ�ͽ���tire����ͬʱ����һ�������㷨��
��ѯ������һ���߱�Ϳ���һ�δ�����������ʱ����P����x��ʼʱ�䡪��x����ʱ�������ж��ٸ��㣬
����B���˻ظ��ײ��ڵ�ǰ�ڵ�Ŀ�ʼʱ�䴦��ʼɾ��1������Сд��ĸ���ڵ�ǰ�ڵ㿪ʼʱ�䴦��1��
��Ϊ���ÿ��û��B���Ǳ�x�Ȳ���ĵ�һ�����ᵽx�������У�len������Ĵ�����=len��ǰ�棩��
�������B�����б�x��ǰ�ĵ�Ҳ��ͨ��ɾ��ɾ���ˣ�����x��ʼʱ�䡪��x����ʱ����;��Ǵ𰸡�

��ʵ��ֻ�����������С�xΪ������������failָ�뵹�������ҵ����ٸ�y·���ϵĵ㡱��һ����
fail���ϵ�DFS����Ҳ���ԣ������ǲ�ѯy·���ϵĵ��м�����DFS����start[x]-end[x]����
���⿴������������ϯ����
��trie�Ͻ�����ϯ��զ��
�����ǲ�ѯ·�����м������start[x]<=start[i]<=end[x]
��ϯ������
*/
#include<cstdio>
#include<queue>
#include<iostream>
#define N 100005
using namespace std;
int n,m,ac_root;
//------------------
struct AC{
    int fail,fa;
    int ne[27];
    int intime,outtime;
    int root;
}ac[N];
int ac_cnt;
int name2ac[N];
void getfail(){
    queue<int> q;
    ac[ac_root].fail=0;
    for(int i=1;i<=26;i++){
        if(ac[ac_root].ne[i]!=0) ac[ac[ac_root].ne[i]].fail=ac_root,q.push(ac[ac_root].ne[i]);
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=1;i<=26;i++){
            if(ac[u].ne[i]!=0){
                int p=ac[u].fail;
                while(p!=0&&ac[p].ne[i]==0) p=ac[p].fail;
                if(p==0) ac[ac[u].ne[i]].fail=ac_root;
                else ac[ac[u].ne[i]].fail=ac[p].ne[i];
                q.push(ac[u].ne[i]);
            }
        }
    }
}
//------------------
vector<int> fail_tree[N];
int mtimer;
void buildfail(){
    for(int i=1;i<=ac_cnt;i++){
        fail_tree[ac[i].fail].push_back(i);
    }
}
void DFS(int u){
    ac[u].intime=++mtimer;
    for(int i=0,len=fail_tree[u].size();i<len;i++){
        DFS(fail_tree[u][i]);
    }
    ac[u].outtime=++mtimer;
}
//------------------
struct xds{
    int son[2],size;
}chair[N*20];
int xds_cnt;
const int L=0,R=1;
void insert(int &k,int l,int r,int v){
    int t=++xds_cnt;chair[t].son[L]=chair[k].son[L];chair[t].son[R]=chair[k].son[R];chair[t].size=chair[k].size+1;k=t;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(mid<v) insert(chair[t].son[R],mid+1,r,v);
    else insert(chair[t].son[L],l,mid,v);
}
int query(int k,int l,int r,int low,int hi){//[low,hi]
    if(l==low&&r==hi){
        return chair[k].size;
    }
    int mid=(l+r)>>1;
    if(mid<low) return query(chair[k].son[R],mid+1,r,low,hi);
    else if(hi<=mid) return query(chair[k].son[L],l,mid,low,hi);
    else return query(chair[k].son[L],l,mid,low,mid)+query(chair[k].son[R],mid+1,r,mid+1,hi);
}
void buildchartree(int u,int ch_root){
    ac[u].root=ch_root;
    insert(ac[u].root,1,N<<1,ac[u].intime);
    for(int i=1;i<=26;i++){
        if(ac[u].ne[i]!=0) buildchartree(ac[u].ne[i],ac[u].root);
    }
}
//----------------------
void init(){
    char c;bool fl=true;int p=1;ac_cnt=ac_root=1;
    ac[p].fa=p;int namecnt=0;
    while(fl){
        c=getchar();
        if(c<='z'&&c>='a'){
            ac[p].ne[c-'a'+1]=++ac_cnt;
            ac[ac_cnt].fa=p;p=ac_cnt;
        }else if(c=='P'){
            name2ac[++namecnt]=p;
        }else if(c=='B'){
            p=ac[p].fa;
        }else{
            fl=false;
        }
    }
}
//--------------------
void asks(){
    int x,y;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        x=name2ac[x];y=name2ac[y];
        int ret=query(ac[y].root,1,N<<1,ac[x].intime,ac[x].outtime);
        printf("%d\n",ret);
    }
}
//------------------
int main(){
    init();
    getfail();
    buildfail();
    DFS(ac_root);
    buildchartree(ac_root,0);
    asks();
    return 0;
}
