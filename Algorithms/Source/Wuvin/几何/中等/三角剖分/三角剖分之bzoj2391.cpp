#include<cstdio>
#include<cmath>
#define eps 1e-8
#define db long double
#include<algorithm>
#define N 2005
/*
���� 
*/
using namespace std;
const long double Pi=acos(-1); 
const int Wood=1;const int Frog=2;
const int L=0;const int R=1;
/*
�����ʷֿ��Թ�������һ�����
�������ʷ�
Ҳ���Թ���Y�������һ��ֱ�߽��������ʷ֣��Ƽ��� 
*/
/////////////////////////////���㼸�� 
struct point{db x,y,val;int kind,name;};
struct seg{point a,b;};
point dec(point a,point b){
	point ret;ret.x=a.x-b.x;ret.y=a.y-b.y;return ret;
}
inline db cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}
inline bool equ(db a,db b){
	if(abs(a-b)<eps) return true;
	return false; 
}
inline long double dis(point a,point b){
	point c=dec(a,b);
	return sqrt(abs(c.x*c.x+c.y*c.y));
}
///////////////////////////////Treap �������
int son[N][2],si[N];//,pri[N];ֱ��д��ƽ���� 
db key[N],value[N],sk[N];//sum of val
int root,size;
inline void update(int k){
	si[k]=si[son[k][L]]+si[son[k][R]]+1;
	sk[k]=sk[son[k][L]]+sk[son[k][R]]+value[k];
}
inline void turn(int &k,int side){//��side�Ǳ�ת  side=R
	int so=son[k][side^1];
	son[k][side^1]=son[so][side];son[so][side]=k;update(k);k=so;update(k);
}
void insert_(int &k,db key_,db val_){//k��ʾ����ǰ����ָ�� 
	if(k==0){//��ǰ���Ϊ��-�½� 
		k=++size;//!!!
		si[k]=1;key[k]=key_;sk[k]=val_;value[k]=val_;son[k][L]=son[k][R]=0;
		return;
	}
	si[k]++;sk[k]+=val_; 
	if(key[k]<key_){
		insert_(son[k][R],key_,val_);
		if(si[son[k][R]]>(si[son[k][L]]<<1)) turn(k,L);
	}else{
		insert_(son[k][L],key_,val_);
		if(si[son[k][L]]>(si[son[k][R]]<<1)) turn(k,R);
	}
}
db query_(int k,db key_){
	if(k==0){//��ǰ���Ϊ��
		return 0;
	}else if(key[k]<key_+eps){
		return query_(son[k][R],key_)+value[k]+sk[son[k][L]];
	}else{
		return query_(son[k][L],key_);
	}
}
///////////////////////////////��װ 
inline void build_tree(){
	root=0;size=0;
}
inline void insert(db key_,db val_){
	insert_(root,key_,val_);
}
inline db query(db key_){
	return query_(root,key_);
}
////////////////////////////////
/*
�����ʷֿ�ʼ
������ѡ��ʼ��Ϊ����
���Տ�(ji)��(jiao)����
Ȼ�����β���һ�ýڵ�i��BST������oi�ļн�Ϊ�ؼ��֣�
j����ʱ�����ξ���oij��Χ�ĵ�ĸ���+1
������������� 
*/ 
int val[1005][1005];//oij i<j
int n,m,q;
point p[N];//1~n wood(ľͷ׮��) n+1~n+m frog  
point o;
long double get_angle(point &l1,point &l2,point &b){
	point p1=dec(b,l2);point p2=dec(l1,l2);
	long double an1=atan2(p1.y,p1.x);long double an2=atan2(p2.y,p2.x);
	an2-=an1;
	if(an2<-eps) an2+=Pi+Pi;
	return an2;
	//������sin return asin(abs(cross(dec(b,l2),dec(l1,l2)))/dis(b,l2)/dis(l1,l2));
}
int buf[N];
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		p[i].x=xx;p[i].y=yy;
		p[i].kind=Wood;p[i].name=i;
	}
	for(int i=n+1;i<=n+m;i++){
		int xx,yy,zz;
		scanf("%d%d%d",&xx,&yy,&zz);
		p[i].x=xx;p[i].y=yy;p[i].val=zz;
		p[i].kind=Frog;p[i].name=i;
	}
}//
bool cmpo(const int &a1,const int &b1){
	point &a=p[a1];point &b=p[b1];
	return cross(dec(a,o),dec(b,o))>-eps;
}
int sor[1005];
int main(){
	init();o.x=-12345;o.y=-15432;
	//p���鲻�ܶ� 
	for(int i=1;i<=2001;i++) sor[i]=i;
	sort(sor+1,sor+n+m+1,cmpo);//��oΪ���㼫������ 
	for(int i=1;i<=n+m;i++){
		if(p[sor[i]].kind==Frog) continue;
		build_tree();//������p[i]Ϊ�����BST 
		for(int j=i+1;j<=n+m;j++){//���ϵĵ㲻�� 
			if(p[sor[j]].kind==Frog) insert(get_angle(o,p[sor[i]],p[sor[j]]),p[sor[j]].val);//����һ����(key,val)
			else if(p[sor[j]].kind==Wood) val[sor[j]][sor[i]]=val[sor[i]][sor[j]]=0.1+query(get_angle(o,p[sor[i]],p[sor[j]]));//����С��x�ļ�ֵ�ܺ� 
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int ans=0;
		int cn=0;scanf("%d",&cn);
		for(int i=0;i<cn;i++){
			scanf("%d",&buf[i]);
		}
		buf[cn]=buf[0];
		for(int i=1;i<=cn;i++){
			if(cross(dec(p[buf[i]],p[buf[i-1]]),dec(o,p[buf[i-1]]))>eps){
				ans+=val[buf[i]][buf[i-1]];
			}else{
				ans-=val[buf[i]][buf[i-1]];
			}
		}
		printf("%d\n",fabs(ans)); 
	}
	return 0;
}  
