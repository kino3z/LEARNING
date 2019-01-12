#include<cstdio>
#include<algorithm>
#define N 100005 
#define M 1000005
#define low(x) (x&(-x))
#define LL long long
/*
������Treap��Ҳ������ɢ���߶���1e6Ӳ������
��Ȼ����������״���飨ò�Ƹ����ã��Ҿ�������ˣ� 
*/
using namespace std;
int he[N],n,k,cnt,root,lim;
const int L=0,R=1;
//--------bits---------
int size[M];
LL sum[M];
void add(int x,int f){//x*f f=1/-1
    for(int i=x;i<M;i+=low(i)){
        size[i]+=f;sum[i]+=x*f;
    }
}
int getsum(int kth,LL &ss){//���С�ڵ���kth�ĺͣ��Լ����ص�kth��ʲô
    ss=0;int at=0;
    for(int i=19;i>=0;i--){
        at^=1<<i;
        if(at>M||size[at]>=kth) at^=1<<i;
        else ss+=sum[at],kth-=size[at];
    }
    ss+=(at+1)*kth;
    return at+1;
}
LL ans=0;
int main(){
    scanf("%d%d",&n,&k);ans=1;ans<<=60;
    for(int i=1;i<=n;i++){
        scanf("%d",&he[i]);he[i]++;
    }he[n+1]=1;
    LL t=0;int s=(k&1)? 0xffffffff:0;
    int hl=(k+1)>>1;
    for(int i=1;i<=k;i++){
        add(he[i],1);t+=he[i];
    }
    for(int i=k;i<=n;i++){
        int b;LL c;b=getsum(hl,c);
        ans=min(ans,t-c-c+(b&s));
        add(he[i-k+1],-1);add(he[i+1],1);
        t-=he[i-k+1];t+=he[i+1];
    }
    printf("%lld",ans);
    return 0;
} 
