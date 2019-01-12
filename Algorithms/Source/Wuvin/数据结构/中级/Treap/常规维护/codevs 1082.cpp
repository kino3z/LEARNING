/*
������Treap
������˳����ΪTreap�Ľṹ˳��
����ֱ��������Ҳ�ɡ�
Treap���xds����ά�����롣
����֧�֣�ĳ��λ�ò���һ������
        ������͡�����Ӽ���
����ʵ��������²������ƽ��������ѧ��
��Ϊ��mid[k]������ȸĶ������������±���ʸ�Ϊ
��ֵk����ʣ�������3~5==>>mid��ֵ3��5����ʣ�
������Ӧ����splay��
*/
#include<cstdio>
#include<cstdlib>
#include<iostream>
#define N 200005
#define LL long long
using namespace std;
int n,m;
//---=-=--=-=--==-==-=-=-=-=-=-=--=--=--
int size[N],son[N][2],fr[N],to[N],key[N],pri[N];
LL sum[N],tag[N],val[N];
//size������С����k��sum������val�͡�
//tag--lazy���
//val-������װ��ֵ pri---���
//fr��to�����mid�ķ�Χ
//mid�����±꣬������չΪlongdouble������ò�����ױ����ȿ�����
//��ʵ��ò���mid���������
int cnt,root;
const int L=0,R=1;
inline void newmark(int &k,LL &mark){
    if(k==0) return;sum[k]+=mark*size[k];tag[k]+=mark;
}
inline void pushdown(int &k){
    if(k==0||tag[k]==0) return;val[k]+=tag[k];
    newmark(son[k][L],tag[k]);newmark(son[k][R],tag[k]);
    tag[k]=0;
}
inline void update(int &k){
    size[k]=1+size[son[k][L]]+size[son[k][R]];
    sum[k]=sum[son[k][L]]+sum[son[k][R]]+val[k];
    fr[k]=to[k]=key[k];
    if(son[k][L]!=0) fr[k]=fr[son[k][L]];
    if(son[k][R]!=0) to[k]=to[son[k][R]];
}
inline void rotate(int &k,int s){
    int t=son[k][s];//pushdown(k);pushdown(t);
    son[k][s]=son[t][s^1];son[t][s^1]=k;update(k);k=t;
}
void insert(int &k,LL &x,int &key_){
    if(k==0){
        k=++cnt;size[k]=1;val[k]=sum[k]=x;son[k][L]=son[k][R]=0;
		fr[N]=to[N]=key[k]=key_;pri[k]=rand();
    }else{
    	pushdown(k); 
        sum[k]+=x;size[k]++;fr[k]=min(fr[k],key_);to[k]=max(to[k],key_);
        int s=key_<key[k]? L:R;
        insert(son[k][s],x,key_);
        if(pri[son[k][s]]>pri[k]) rotate(k,s);
        else update(son[k][s]);
    }
}
void add(int k,int &start,int &end,LL &c){
	if(start>end) return;
    if(k==0) printf("BUG\n");
    if(fr[k]==start&&to[k]==end){
        newmark(k,c);
    }else{
        sum[k]+=(end-start+1)*c;
        if(start<=key[k]&&end>=key[k]){
        	val[k]+=c;
        	if(son[k][L]!=0) add(son[k][L],start,to[son[k][L]],c);
            if(son[k][R]!=0) add(son[k][R],fr[son[k][R]],end,c);
		}else if(start>key[k]) add(son[k][R],start,end,c);
        else if(end<key[k]) add(son[k][L],start,end,c);
    }
}
LL query(int k,int &start,int &end){
	if(start>end) return 0;
    if(k==0) return 0;
    if(fr[k]==start&&to[k]==end){
        return sum[k];
    }else{
        pushdown(k);
        LL me=(start<=key[k]&&end>=key[k])? val[k]:0;
        if(start>key[k]) return query(son[k][R],start,end);
        else if(end<key[k]) return query(son[k][L],start,end);
        else return query(son[k][L],start,to[son[k][L]])+me+
              query(son[k][R],fr[son[k][R]],end);//�����ʵ�0 
    }
}
//��������+����++��������+������դ��������+����+����+����+����+����+����+����=
//====+===++===+=+==+����դ��+=+==++==++==+==+=+=
void init(){
    scanf("%d",&n);
    LL d,t;
    for(int i=1;i<=n;i++){
        scanf("%lld",&t);
        insert(root,t,i);
        update(root);
    }
    scanf("%d",&m);
    for(int i=1,a,b,c;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(a==1){
            scanf("%lld",&d);
            add(root,b,c,d);
        }else{
            printf("%lld\n",query(root,b,c));
        }
    }
}
int main(){
    init(); 
    return 0;
}
