/*
̫���ˣ�
˵����С������������
�����ڽƻ�������һ��������Ϣ������Ӽ�����
ת��ͼ��ά�����ɣ��޻�
�������ұ�����ſ���
n+1����n���߸պ�
����������prim�����ܽ�2s
������kruska����6s 
*/
#include<cstdio>
#include<algorithm>
#define N 2005
using namespace std;
struct edge{int fr,to,dis;}e[N*N];
inline bool cmp(const edge &a,const edge &b){return a.dis<b.dis;}
long long ans;
int n,buf;char cbuf;
inline int read(){
    cbuf=getchar(),buf=0;while(cbuf<'0'||cbuf>'9') cbuf=getchar();while(cbuf>='0'&&cbuf<='9') buf=buf*10+cbuf-'0',cbuf=getchar();return buf;
}
int bcj[N];
inline int ff(const int &x){return bcj[x]==x?x:bcj[x]=ff(bcj[x]);}
int main(){
    scanf("%d",&n);int fr,to,dis,ecnt;
    for(int i=0;i<=n;i++) bcj[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            dis=read(),e[++ecnt]=(edge){i-1,j,dis};
    sort(e+1,e+ecnt+1,cmp);
    for(int i=1,cnt=0;i<=ecnt&&cnt<n;i++){
        if(ff(e[i].fr)!=ff(e[i].to)) bcj[bcj[e[i].fr]]=bcj[e[i].to],ans+=e[i].dis,cnt++;
    }
    printf("%lld",ans);
    return 0;
}
