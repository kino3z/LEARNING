/*
����ʵ�ʣ����޸�����kth
hzwer�ֿ�ɹ�����ò�Ʋ�֪Ϊ�Σ�����ֿ����Խ���п���ѯ��̫���У�
�ֿ�һ���޸�sqrt(n)logn,�ҵķ���һ��lognlogINF��+������ 
����һ�£�����m̫С���ֿ���ѹ������
������һ��bit+��ϯ����������˵bit+��������(��)��
�ұȽ�����������ɢ�����Ǿͱ���10^9��ֵ���(ò�Ƴ���Ҫx2)
�ȵ���Ŀ��ʾai,bi<=n 
�ȵȣ�ò��ֻ����ϯ��Ϳ���ά������Ը����ˡ�
lognˮ�� 
���ԣ����淽���Ǵ�ġ�
����Ҫbit+��ϯ��
���淽��ֻ��Ӧ��һ�β�ѯ 
����hi<1e9 


eeeWA�˰��죬N����ʮ����A�� 
��������ϸ��һ�¿ռ䡣
�����С2*10^4
ÿ���ڵ���һ��xds
e..�����߶����ĸ߶Ȳ����ϸ�logn��
����һ��1~15���߶�����������㡣
Ӧ�ð�2n��log 
��ô����NҪΪ
4588000 
��ô��״����Ĳ�����
�ϸ�logn +1�� 
*/ 
#include<cstdio>
#include<iostream>
#define low(x) (x&(-x))
#define N   4588005
#define INF 1000000005
using namespace std;
const int L=0,R=1;
int n,m,cnt,root[20005],total;
int a[20005];
//--------hjt-------
int son[N][2],size[N];
inline int build(int &k,int fr_,int to_,int &x,int f2){//˳�����ر�x��ĸ���
    int f=++cnt;son[f][L]=son[k][L];son[f][R]=son[k][R];
    size[f]=size[k]+f2;k=f;
    if(fr_==to_) return 0;
    int mid=(fr_+to_)>>1;
    if(mid>=x)  {return size[son[k][R]]+build(son[k][L],fr_,mid,x,f2);}
    else  return build(son[k][R],mid+1,to_,x,f2);
}
void pre(){
    total=0;
    for(int i=1;i<=n;i++){
        root[i]=root[i-1];
        total+=build(root[i],1,INF,a[i],1);
    }
}

int cxd(int jia1,int jia2,int jian,int fr_,int to_,int &f){
    if(fr_>f){
        return size[jia1]+size[jia2]-size[jian];
    }else if(to_<=f){
        return 0;
    }else{
        int mid=(fr_+to_)>>1;
        return cxd(son[jia1][L],son[jia2][L],son[jian][L],fr_,mid,f)+
        cxd(son[jia1][R],son[jia2][R],son[jian][R],mid+1,to_,f);
    }
}
int cxx(int jia1,int jia2,int jian,int fr_,int to_,int &f){
    if(fr_>=f){
        return 0;
    }else if(to_<f){
        return size[jia1]+size[jia2]-size[jian];
    }else{
        int mid=(fr_+to_)>>1;
        return cxx(son[jia1][L],son[jia2][L],son[jian][L],fr_,mid,f)+
        cxx(son[jia1][R],son[jia2][R],son[jian][R],mid+1,to_,f);
    }
}
//--------bit-----------
int bit[20005];
inline void change(int x,int y){//��a[x]���y
    for(int i=x;i<=n;i+=low(i)){
        build(bit[i],1,INF,a[x],-1);
        build(bit[i],1,INF,y,1);
    }
    a[x]=y;
}
inline int querybigger(int x,int k){//��ѯ����1-x��k��ĸ���
    int ret=0;
    for(int i=x;i>=1;i-=low(i)){
        ret+=cxd(root[i],bit[i],root[i-low(i)],1,INF,k);
    }
    return ret;
}
inline int querysmaller(int x,int k){//��ѯ����1-x��kС�ĸ���
    int ret=0;
    for(int i=x;i>=1;i-=low(i)){
        ret+=cxx(root[i],bit[i],root[i-low(i)],1,INF,k);
    }
    return ret;
} 
//------------------
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    pre();
    printf("%d\n",total);
    scanf("%d",&m);
    for(int i=1,l,r;i<=m;i++){
        scanf("%d%d",&l,&r); 
        int ans=querysmaller(r,a[l])-querysmaller(l,a[l])+querybigger(r,a[r])-querybigger(l,a[r]);
        total-=ans;int t=a[l];
        change(l,a[r]);
		change(r,t);
        ans=querysmaller(r,a[l])-querysmaller(l,a[l])+querybigger(r,a[r])-querybigger(l,a[r]);
        total+=ans; 
        printf("%d\n",total);
    }
    return  0;
}
