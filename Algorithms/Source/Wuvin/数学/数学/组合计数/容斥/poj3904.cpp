/*���Ⱑ
��ͨ��Ī����˹������ƫ���ϵ��ݳ�
���⼴��Ī����˹���ֿ��ݳ�
���Ӷ��������ݳ�ҪСһ�㣬�����ݳ�ݹ鳣���϶���
ֱ��ö��GCD��ֵ��Ȼ���ݳ���߷���
*/
#include<cstdio>
#include<cmath>
#include<cstring> 
using namespace std;
int n;
int val[10005];
int time[10005];
int miu[10005];
int prime[10005];int cnt;
#define INF 0x3f3f3f3f
int main(){
    int m=10000;
    memset(miu,0x3f,sizeof(miu));miu[1]=1;
    for(int i=2;i<=m;i++){//miu��С��ɸ���� 
        if(miu[i]==INF) miu[i]=-1,prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=m;j++){
            if(i==prime[j]) miu[i*i]=0;
            else if(i%prime[j]==0) {miu[i*prime[j]]=0;break;}
            else miu[i*prime[j]]=-miu[i];
        }
    }
    /*
    �ĵã�
    �ⲿ���Ҿ����˺ܾã������룬����Ҫ�Ħ̺����볣����D�Ͼ����ֻ��1��ϵ��Ϊ1������ϵ����Ϊ0
    ����2��ϵ����ҪΪ-1��
    ��Ȼ����˼�������ϵ��ʹ�ã�������1����������ϵ��Ϊ1����1Ϊ0�����������ȫ��Ϊ1.
    */
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++) scanf("%d",&val[i]);
        for(int i=1;i<=n;i++){
            for(int j=sqrt(val[i]);j;j--){
                if(val[i]%j==0){
                    time[j]++;
                    if(val[i]!=j*j) time[val[i]/j]++;
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=10000;i++){
            if(time[i]>=4){
                ans+=(long long)time[i]*(time[i]-1)*(time[i]-2)*(time[i]-3)*miu[i]/24;
            }
        }
        printf("%lld\n",ans);
        memset(time,0,sizeof(time));
    }
    return 0;
}
