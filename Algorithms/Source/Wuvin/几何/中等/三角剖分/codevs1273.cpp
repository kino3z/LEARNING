#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define LL long long
#define db long long
#define eps 1e-8
#define N 105
using namespace std;
/*
����ؼ��������㹲�� 
��⣬�����������ʷ�
��������Լӵ㣬��������͹��
���𰸵�͹��һ������һ�����ʣ�
��һ���Ѿ�����뵽͹���У������
��һ���Ѿ���ɾ��������͹����������š�
���Ȳ����������ʷ�ʱ�临�Ӷ�Ϊ��O��n^4��ò�ƻ��
���������ʷ�Ԥ���� O��n^2logn+n^3�� ��ѹ���� 
*///��������ͳһ��0��ʼ��
const int L=0,R=1;
const int FR=1,EN=3;//friend eney
/////////////////���ο�////////////////////////
inline int read(){
	char c=getchar();int ret=0;
	while(c==' '||c=='\n') c=getchar();
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret;
}
struct point{db x,y;int kind;};
inline point operator -(point &a,point &b){
	return (point){a.x-b.x,a.y-b.y};
}
inline bool equ(db &a,db &b){
	return a==b;
}
inline db cross(point &a,point &b){
	return a.x*b.y-b.x*a.y;
}
//------------����---------------------------------
int n,pr,t;
point p[N];
/////////////////�����ʷ֣�����д��////////////////////////// 
//----------��������--------------------
int f[N][N];int cnt,root;
int son[N][2],pri[N];db key[N],val[N],sum[N];//key-����
//--------------Treap------------------------
inline void recount(int k){
	sum[k]=sum[son[k][L]]+sum[son[k][R]]+val[k];
}
inline void turn(int &k,int side){
	int t=son[k][side^1];
	son[k][side^1]=son[t][side];son[t][side]=k;recount(k);k=t;recount(k);
}
void build(int &k,double key_,db val_){
	if(k==0){
		k=++cnt;son[k][L]=son[k][R]=0;pri[k]=rand();key[k]=key_;sum[k]=val[k]=val_;
		return;
	}
	sum[k]+=val_;
	int si=key_<key[k]? 0:1;
	build(son[k][si] ,key_,val_);
	if(pri[son[k][si]]>pri[k] ) turn(k,si^1);
	return;
}
db getmin(int &k,double key_){//��ȡ���б�KEY_��С�Ľڵ��val��
	if(k==0) return 0;
	int si=key_<key[k]? 0:1;
	db ret=key_<key[k]? 0:val[k]+sum[son[k][L]];
	return ret+ getmin(son[k][si] ,key_);
}
void pre(){
	cnt=0;root=0;
}
//--------------------�����������ʷ֣������ʷֱ�ƽ���������ʷ���Ҫ�꣩-------------------------------
inline bool cmp(const point &a,const point &b){
	if(a.y==b.y) return a.x<b.x;
	return a.y>b.y; 
}
inline double getangle(point &a,point &b){
	return atan2(b.y-a.y,b.x-a.x);
}
void cut(){
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++){
		if(p[i].kind==EN) continue;
		pre();
		for(int j=i+1;j<n;j++){
			double ang=getangle(p[i],p[j]);
			build(root,ang,p[j].kind-2);
			if(p[j].kind==FR) f[i][j]=f[j][i]=getmin(root,ang+eps);//�����Լ�
		}
	}
}
/////////////////////////////////////////////////////////////
int main(){
	scanf("%d%d",&p,&t);
	n=pr+t;
	for(int i=0;i<pr;i++){
		p[i].x=read();p[i].y=read();p[i].kind=EN;
	}
	for(int i=pr;i<pr+t;i++){
		p[i].x=read();p[i].y=read();p[i].kind=FR;
	}
	cut();
	
	return 0;
} 
