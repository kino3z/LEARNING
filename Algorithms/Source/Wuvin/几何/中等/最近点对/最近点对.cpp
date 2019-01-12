#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define LL long long
#define db long long
#define eps 1e-8
#define N 100005
using namespace std;
//ZOJ 2107 
inline int read(){
	char c=getchar();int ret=0;
	while(c==' '||c=='\n') c=getchar();
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret;
}
struct point{db x,y;int color;};
struct seg{point a,b;};
inline point operator -(point &a,point &b){
	point ret;ret.x=a.x-b.x;ret.y=a.y-b.y;return ret;
}
inline db getdis(point &a,point &b){
	point c=a-b;
	return c.x*c.x+c.y*c.y;
}
inline bool equ(db a,db b){
	if(fabs(a-b)<eps) return true;
	return false;
}
inline db cross(point &a,point &b){
	return a.x*b.y-b.x*a.y;
}
///////////////////////////////////////////�� 
/*
����㷨�㲻����û�а취��ֻ��дһд�����㷨��
���Σ��õ�������̼��k
������ߵ�һ���㣬����֤�������ұ�k*2k�ķ�Χ�ڣ����ֻ��6������֮��Ӧ   
*/
point p[2*N];
int n;
long long ans;
int T;
bool cmp(const point &a,const point &b){
	if(a.x==b.x) return a.y>b.y;
	return a.x<b.x;
}
long long 
int main(){
	scanf("%d",&T);
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			p[i].x=read();p[i].y=read();p[i].color=1;
		}
		for(int i=n+1;i<=n+n;i++){
			p[i].x=read();p[i].y=read();p[i].color=2;
		}
		ans=getdis(p[1],p[n+1]);
		sort(p+1,p+n+n+1,cmp);
		ans=solve(1,n+n);
		//��������� 
	}
	return 0;
} 
