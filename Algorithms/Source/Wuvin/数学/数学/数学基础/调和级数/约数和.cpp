#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ret;char ch;
inline int read(){
	ret=0;ch=getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	while(ch>='0' && ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
/*
һ��ʼ����10^6����ȥ�����ò�����
��������x������ģ���ô���Ӷ���nsqrt(n)->nlogn
Ԥ������ 

������û����������ɾ�ˣ�woc 
*/
long long c[1000005];
/*int prime[1000005];int pcnt;
int isp[1000005];*/
int jj[1000005];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);/*
    for(int i=2;i<=n;i++){//������ 
        if(isp[i]==0) {
            prime[++pcnt]=i;
            for(int j=1;j<=pcnt&&i*prime[j]<=n;j++) isp[i*prime[j]]=1;
        }else{
            for(int j=1;j<=pcnt&&i*prime[j]<=n;j++){
            	isp[i*prime[j]]=1;
            	if(i%prime[j]==0) break;
			}
        }
    }*/
    //for(int i=1;i<=pcnt;i++) printf("%d ",prime[i]);
    for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i){
			jj[j]+=1;
		} 
    for(int i=1,ins,x,y;i<=q;i++){
    	ins=read();
    	if(ins==1){
    		x=read();y=read();
    		for(int i=n/x;i;i--) 
				c[i*x]+=jj[i]*y;
		}else{
			x=read();
			printf("%lld\n",c[x]);
		}
	}
    return 0;
}
