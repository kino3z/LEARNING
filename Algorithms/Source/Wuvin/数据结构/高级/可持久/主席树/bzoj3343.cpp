#include<cstdio>
#include<iostream>
#define VAL 1005
#define N 1000005
#define ALL 10000505
using namespace std;
/*
������ϯ����+�߶�����lazy�������䣩
�е���д�����������bug
ò��Ӧ����ϯ��+��״����
�޸Ĳ�ѯ mlog^2nlogv
���� nlogn


hh,�ŷ��������ǣ�
�ֿ���Treap
����n
�޸�m*n^0.5

*/
//char tree
const int L=0,R=1;
int root[N],a[N];
int son[ALL][2],sum[ALL];//,fr[ALL],to[ALL];
int n,m,cnt,seg_cnt,sroot;//++cnt
//-------�����ָ���------- 
void add(int &k,int fr,int to,int x){//�ɳ־û��޸� 
	int f=++cnt;
	son[f][L]=son[k][L];son[f][R]=son[k][R];sum[f]=sum[k]+1;
    k=f;
	if(fr==to) return;
	int mid=(fr+to)>>1;
	if(x<=mid) add(son[f][L],fr,mid,x);
	else add(son[f][R],mid+1,to,x);
}
inline void build(){
	for(int i=1;i<=n;i++){
		root[i]=root[i-1];
		add(root[i],1,VAL,a[i]);
	}
}
int bigger(int kfr,int kto,int c,int fr,int to){//�������䡾kfr,kto�����ڵ���c�ĸ��� fr,to ȷ�����估����  ע��С��0�����
    if(fr==to){
        return sum[kto]-sum[kfr];
    }else{
        int mid=(fr+to)>>1;
        if(c<=mid){
            return sum[son[kto][R]]-sum[son[kfr][R]]+bigger(son[kfr][L],son[kto][L],c,fr,mid);
        }else return bigger(son[kfr][R],son[kto][R],c,mid+1,to);
    }
}
//--------�����ָ���----- 
//segment tree
int segson[2*N][2],segfr[2*N],segto[2*N],segadd[2*N];
void _build(int &k,int fr,int to){
    k=++seg_cnt;segfr[k]=fr;segto[k]=to;
    if(fr==to) return;
    _build(segson[k][L],fr,(fr+to)>>1);
    _build(segson[k][R],((fr+to)>>1)+1,to);
}
void adds(int k,int fr,int to,int c){
    if(fr==segfr[k]&&to==segto[k]){
        segadd[k]+=c;
    }else{
        int mid=(segfr[k]+segto[k])>>1;
        if(fr<=mid) adds(segson[k][L],fr,min(to,mid),c);
        if(to>mid) adds(segson[k][R],max(fr,mid+1),to,c);
    }
}
int query(int k,int fr,int to,int c){//>=c
    if(fr==segfr[k]&&to==segto[k]){
        if(c-segadd[k]<=1) return to-fr+1;
        if(c-segadd[k]>VAL) return 0;
        return bigger(root[fr],root[to],c-segadd[k],1,VAL);
    }else{
        int mid=(segfr[k]+segto[k])>>1;
        if(segadd[k]!=0){
            segadd[son[k][L]]+=segadd[k];segadd[son[k][R]]+=segadd[k];
            segadd[k]=0;
        }
        int ret=0;
        if(fr<=mid) ret+=query(son[k][L],fr,min(mid,to),c);
        if(to>mid) ret+=query(son[k][R],max(mid+1,fr),to,c);
        return ret;
    }
}
//-----------�����Ľ�β��---- 
int main(){
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build();_build(sroot,1,n);
    for(int i=1;i<=m;i++){
        char c=getchar();while(c!='A'&&c!='M') c=getchar();
        int f,t,cc;scanf("%d%d%d",&f,&t,&cc);
        if(c=='A'){
            printf("%d\n",query(sroot,f,t,cc));
        }else{
            adds(sroot,f,t,cc);
        }
    }
	return 0;
} 
