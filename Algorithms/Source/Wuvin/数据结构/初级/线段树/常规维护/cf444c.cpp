/*
����������������һ�°ɡ�
һ����Ϊn������a,a[i]=i;ÿ��λ��ȨΪ0;
ÿ�β�����1 l r x�����Խ�iλ�õ�Ȩֵ����|a[i]-x|,Ȼ��a[i]=x;
��ѯ"2 l r"��ѯ����[l,r]��Ȩ�͡�
��⣺
����һ�������ʱ�临�Ӷȷ����⡣
����1����¼ÿ�������Ƿ�Ϊͬһ��ֵ�����Ǿͱ����´�������
����֤��ʱ�临�Ӷ��ǣ�n+m��logn�ġ�
��ǰ�����Ȩֵ��Ϊ��ͬ��ֵ�ĸ�����
��ʼȨֵΪn��ÿ�β���Ȩֵ����r-l;
��Ϊÿ�ζ���1��Ȩֵ������һ��logn���Ĳ�����
��(n+m)logn
��������һ�ı��ذ棬��¼max��min��sum��
���x��С��min�����max������ȥ��
�ȵȷ�������
11111111
dye(2,4,2);
������������
ע��longlong 
�������ɫ��ǲ��ܼ��´� 
*/
#include<cstdio>
#define LL long long
#define N 200005
using namespace std;
const int L=0,R=1;
int n,m,root,cnt;
inline int abs(int x){return x<0? -x:x;}
//-------------------
int son[N][2],v[N],fr[N],to[N],c[N];
LL sum[N],stag[N];//v��ͳһ��ɫ��ʼΪ- c[N]-tag ���Դ�tag��ǰ������ɫͳһ
void build(int &k,int fr_,int to_){
    k=++cnt;sum[k]=0;v[k]=-k;fr[k]=fr_;to[k]=to_;son[k][L]=son[k][R]=0;
    if(fr_==to_) v[k]=fr_;
    else {int mid=(fr_+to_)>>1;build(son[k][L],fr_,mid);build(son[k][R],mid+1,to_);}
}
inline void update(int k){
    if(son[k][L]==0) return;
    sum[k]=sum[son[k][L]]+sum[son[k][R]];
    if(v[son[k][L]]==v[son[k][R]]) v[k]=v[son[k][L]];
    else v[k]=-k;
}
inline void dye(int k,int color){
	stag[k]+=abs(color-v[k]);
    sum[k]+=(LL)(to[k]-fr[k]+1)*(LL)abs(color-v[k]);v[k]=color;c[k]=color;
}
inline void pushdown(int k){
    if(c[k]==0||k==0) return;
    if(son[k][L]){
    	sum[son[k][L]]+=stag[k]*(to[son[k][L]]-fr[son[k][L]]+1);
    	sum[son[k][R]]+=stag[k]*(to[son[k][R]]-fr[son[k][R]]+1);
    	stag[son[k][L]]+=stag[k];stag[son[k][R]]+=stag[k];
    	v[son[k][L]]=v[son[k][R]]=c[k];c[son[k][L]]=c[son[k][R]]=c[k];
    	c[k]=0;stag[k]=0;
	} 
}
void change(int k,int color,int start,int end){
    int mid=(fr[k]+to[k])>>1;pushdown(k); 
    if(start==fr[k]&&end==to[k]&&v[k]>0)  {dye(k,color);return;}
    else if(mid<start) change(son[k][R],color,start,end);
    else if(mid>=end) change(son[k][L],color,start,end);
    else change(son[k][L],color,start,mid),change(son[k][R],color,mid+1,end);
    update(k);
}
LL query(int k,int start,int end){
    int mid=(fr[k]+to[k])>>1;pushdown(k);
    if(start==fr[k]&&end==to[k])  return sum[k];
    else if(mid<start)  return query(son[k][R],start,end);
    else if(mid>=end)  return query(son[k][L],start,end);
    else return query(son[k][L],start,mid)+query(son[k][R],mid+1,end);
}
int main(){
    scanf("%d%d",&n,&m);
    build(root,1,n);
    for(int i=1,ins,l,r,x;i<=m;i++){
        scanf("%d",&ins);
        if(ins==1){
            scanf("%d%d%d",&l,&r,&x);
            change(root,x,l,r);
        }else{
            scanf("%d%d",&l,&r);
            printf("%I64d\n",query(root,l,r));
        }
    }
    return 0;
}
