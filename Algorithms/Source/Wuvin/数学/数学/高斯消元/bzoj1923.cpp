/*
����ѹ��λ������
��˹��Ԫ���Բμ�popoqqq����ͳ��˹��Ԫ
Ҳ���Կ�hzwer�ĸ���д����ȫ��˹��Ԫ
����ֻ��Խ��ߣ������ض���Ҫ�ˡ�
*/
#include<cstdio>
#include<iostream>
#include<bitset> 
#define N 1005
using namespace std;
bitset<N> x[N*2];
int n,m,ans;
void gauss(){
    ans=0;int now=1;
    for(int i=1;i<=n;i++){
        int j=now;
        while(!x[j][i]&&j<=m) j++;
        ans=max(ans,j);if(ans==m+1){ans=-1;return;}
        if(j!=now) swap(x[j],x[now]);
        for(int k=1;k<=m;k++){
            if(x[k][i]&&k!=now) x[k]^=x[now];
        }
        now++;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    if(n>m) {puts("Cannot Determine");return 0;}
    for(int i=1;i<=m;i++){
        char c=getchar();
        while(c!='0'&&c!='1') c=getchar();
        for(int j=1;j<=n;j++) x[i][j]=c-'0',c=getchar();
        while(c!='0'&&c!='1') c=getchar();
        x[i][n+1]=c-'0';
    }
    gauss();
    if(ans==-1){puts("Cannot Determine");return 0;}
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(x[i][n+1]) puts("?y7M#");
        else puts("Earth");
    }
    return 0;
}
