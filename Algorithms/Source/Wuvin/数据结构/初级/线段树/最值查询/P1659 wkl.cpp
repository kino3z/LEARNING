/*
�������ºڿƼ�
ò����չ��״������Ժ����ش����ǣ������������´�
����������������������Կռ��ϸ�2n+1
����֧��̫�࣬���Կ��Ե���zkw�߶�����
����ÿһ���ֶ�����������״���飬�������԰�������һ��ǰ׺��һ����׺֮�ͣ�ǰ��׺�Զ����
�����Դ��������ɱ�����һ�ν��dosth update 
*/
#include<cstdio>
#include<iostream>
#define N 200005
#define low(x) (x&(-x))
#define left(x) (x-(low(x)<<1))
#define bro(x) (x^(low(x)<<1))
#define up(x) ((x+bro(x))>>1)
#define down(x) ((x-1)|x)
#define lson(x) (x-(low(x)>>1))
#define rson(x) (x+(low(x)>>1))
#define whe(x) (x&(low(x)<<1))
#define dup(x) (x^((x^(x+1))>>2))
using namespace std;
inline int read(){
	int ret=0,f=1;char c=getchar();
	while(c<'0'||c>'9' ) {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret*f;
}
int n,m,n2,h;//h==buf
int maxn[N],a[N];
int st[N],cnt;
/*
ò������һ�ִ������ҵ�ɨ�跽��
���²��� 
*/
void add(int &l,int &r,int &c){
	cnt=0;l=((l-1)<<1)|1;r=((r-1)<<1)|1;
	h=down(r);int t=dup(h);
	while(down(t)>=l){		
		if((t-low(t)+1)>=l){
			//�޸ĸõ� 
			maxn[t]+=c;a[t]+=c;
			//�޸����
			t=left(t);
			if(whe(t)) h=down(t),t=dup(h);//ԭ��Ϊ�����
		}else{
			st[++cnt]=t;t=rson(t);
		}
	}
	t=r;
	while(up(t)<n2) t=up(t),st[++cnt]=t;
	while(cnt>0){
		//update
		maxn[st[cnt]]=max(maxn[lson(st[cnt])],maxn[rson(st[cnt])])+a[st[cnt]];
		//finished
		cnt--;
	}
}
inline int query(int &l,int &r){
	
}
int main(){
	n=read();n2=(n<<1)|1;
	for(int i=0;i<n;i++){
		maxn[(i<<1)|1]=read();
	}
	for(int i=1;(1<<i)<n2;i++)
		for(int j=1<<i;j<n2;j+=1<<(i+1))
			maxn[j]=max(maxn[lson(j)],maxn[rson(j)]);
	m=read();
	for(int f=1;f<=m;f++){
		int k,l,r,c;
		k=read();l=read();r=read();
		if(k==1){
			c=read();
			add(l,r,c);
		}else{
			printf("%d",query(l,r));
		}
	}
	return 0;
}
