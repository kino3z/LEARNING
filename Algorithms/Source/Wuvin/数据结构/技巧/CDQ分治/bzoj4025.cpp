/*
����+bcj
���ǹ��ף�����һ���߳��ֵ�ʱ���ֻ����������
���ֻ�ᱻ�ֳ�logn��ʱ�����䣬���Ը��Ӷ�logn
�����ʱ�����Ͻ���һ���߶�������֧�ּ���һ����
�����ѯ�Ƿ��Ƕ���ͼ�����߲�ѯ��ĳ��ʱ������Ƿ��Ƕ���ͼ 
���β���д�������߶�����д�����ǿռ��е����ˣ����Ҫ��ʼ��
bcj���飬��ô��ﵽn^2
���ڷ��β�����ȫ���й�����ֻ�����ŸĻ�ȥ
���߶�����������ô�죿
�߶����׿ɳ־û�bcj�����ǺǺ��ˣ����ӶȾͳ�����log�� 
����nlogn^2
�����ѯlogn
�޸ġ�������������Ҫ����һ�����ﵽ����logn
//-------------------------------------
����n^2
����logn
����logn
�޸ġ��������޸ľͱ����tag������tag��Ϣ������Լ򵥺ϲ���
������bcj
//---------------
���˻���ȥ����lct�������� 
//------------------------------
���뵽��
�߶����Ľڵ�ֻ����ߣ���ôÿ�β�ѯ��һ��bcj
˳�Ÿ���ȥ���������ڸĻ���
��ôʱ������Ϊ1-N����M��������Q����ѯ
����nlogn
����mlogn
����������Ļ�����ѯQlogn(loglogn)
���������� 
*/
#include<cstdio>
#include<iostream>
#define N 100005
using namespace std;
struct event{int *pl;int val;};
struct interval{int f,t,start,end;};
int ans[N];int tttbuf;
interval qj[N*2];
int buf[20][N*2],bufcnt[20];
//--------------------------------
#define swapwkl(x,y) tttbuf=x,x=y,y=tttbuf
event ev_stack[N*6];int evcnt;
int bcj[N],size[N],dis[N];
int ff(int x){while(bcj[x]!=x) x=bcj[x];return x;}
inline int getdis(int x){int ret=0;while(bcj[x]!=x) ret+=dis[x],x=bcj[x];return ret;}
bool connect(int f,int t){
	int vf=ff(f),vt=ff(t);
	if(vf==vt){
		if(!((getdis(f)+getdis(t))&1)) return false;
	}else{
		if(size[vf]>size[vt]) swapwkl(vf,vt);
		ev_stack[++evcnt]=(event){&bcj[vf],bcj[vf]};
		ev_stack[++evcnt]=(event){&size[vt],size[vt]};
		ev_stack[++evcnt]=(event){&dis[vf],dis[vf]};
		bcj[vf]=vt;size[vt]+=size[vf];dis[vf]=getdis(t)+getdis(f)+1;
	}
	return true;
}
inline void backto(int times){for(;evcnt>times;evcnt--)*ev_stack[evcnt].pl=ev_stack[evcnt].val;}
//--------------------------------
void cdq(int fr,int to,int deep){
		int newcnt=0;
		for(int i=1;i<=bufcnt[deep];i++){
			interval &it=qj[buf[deep][i]];
			if(it.start<=fr&&it.end>=to){
				if(!connect(it.f,it.t)){
					for(int j=fr;j<=to;j++) ans[j]=1;
					return;
				}
			}else buf[deep][++newcnt]=buf[deep][i];
		}
		if(fr==to||newcnt==0) return;
		int t1=evcnt,mid=(fr+to)>>1;bufcnt[deep+1]=0;
		for(int i=1;i<=newcnt;i++){
			if(qj[buf[deep][i]].start<=mid) buf[deep+1][++bufcnt[deep+1]]=buf[deep][i];
		}
		cdq(fr,mid,deep+1);
		backto(t1);bufcnt[deep+1]=0;
		for(int i=1;i<=newcnt;i++){
			if(qj[buf[deep][i]].end>mid) buf[deep+1][++bufcnt[deep+1]]=buf[deep][i];
		}
		cdq(mid+1,to,deep+1);
		backto(t1);
}
int n,m,T;
int main(){
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;i++) bcj[i]=i,size[i]=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&qj[i].f,&qj[i].t,&qj[i].start,&qj[i].end);buf[0][i]=i;qj[i].start++;
	}
	bufcnt[0]=m;cdq(1,T,0);
	for(int i=1;i<=T;i++){
		if(ans[i]==1) puts("No");else puts("Yes");
	}
	return 0;
}
