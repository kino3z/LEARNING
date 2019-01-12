#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<queue>
#define LL long long
#define db long double
#define eps 1e-8
#define N 500005
using namespace std;
const double KK=1;
inline int read(){
	char c=getchar();int ret=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret;
}
struct point{db x,y;};
struct line{
	point a,b;//p1->p2
	db angle;
	bool operator <(const line &b)const{
		return angle<b.angle;
	}
	void cal(){
		angle=(b.y-a.y)/(b.x-a.x);
	}
};
inline point operator -(const point &a,const point &b){
	return (point){a.x-b.x,a.y-b.y};
}
inline point operator +(const point &a,const point &b){
	return (point){a.x+b.x,a.y+b.y};
}
inline point operator *(const point &a,const db b){
	return (point){a.x*b,a.y*b};
}
bool operator<(const point &a,const point &b){
	return a.x<b.x;
}
inline double getdis(point &a,point &b){
	point c=a-b;
	return sqrt(c.x*c.x+c.y*c.y);
}
inline bool equ(db a,db b){
	return fabs(a-b)<eps;
}
inline db cross(point a,point b){
	return a.x*b.y-b.x*a.y;
}
inline bool onleft(const point &o,const point &a,const point &b){
	return cross(a-o,b-o)>-eps;
}
inline point get_inter(const line &a,const line &b){//&
	db p1=cross(a.b-a.a,b.b-a.a);
	db p2=cross(a.b-a.a,b.a-a.a);
	return (b.b-b.a)*(p2/(p2-p1))+b.a;
}
///////////////////////////////////////////��
//--------------��̬ά����ƽ�潻-------------
/*
����ά����ƽ�潻��ô�죬���ݳ�͹����
̫��Խ�� ���� 
Ҫ֧�ֶ�̬��ƽ��+��logn��ѯ 
ò�Ʒ��ݳ�͹��������
����ô���ݣ�
����ȡһ���ϵ��ӽǾͳ���ƽ��ɼ�ֱ����
����ж�һ���������
����Ҫ�ҵ������͹�������߽���
�������͹������������һ��ֱ�߶����͹���ཻ
���Ը���б�ʽ��ж��֡�����
���ԣ��һ���ȥ������
�����˻��������ֱ�Ӱ�������Բ���ݳ��˵�
����˰�ƽ�档��������
orzzzzzzzzzzzzzzzzzzzzz
���˲�������ô�죬�͵���ϰcdq�ɣ���������logn+����������
*/
//----------------cdq--------------------------- 
struct things{
    int kind;
    line p;//�����ѯ�ʾͷ���p1
    bool ans;
}problem[N];
//------------------
point tub[N];int tbcnt;//�������ʹ��ɣ�����������
line buf[N];
line bpm[N];
line left=(line){(point){-1e12-eps*100,10},(point){-1e12,9},0};
line right=(line){(point){1e12+eps*100,10},(point){1e12,9},0};
line bottom=(line){(point){-1e12,-1e12},(point){1e12,-1e12},0};
void build(int fr,int to){//������ƽ����ת��͹��
    int bpmcnt=0;int cnt=0;left.cal();right.cal();bottom.cal();tbcnt=0;
	for(int i=fr;i<=to;i++){
		if(problem[i].kind==0) buf[++cnt]=problem[i].p;
	}
	buf[++cnt]=bottom;
	sort(buf+1,buf+cnt+1);
	for(int i=1;i<=cnt;i++){
		while(bpmcnt>1&&onleft(bpm[bpmcnt].a,bpm[bpmcnt].b,get_inter(bpm[bpmcnt-1],buf[i]))) bpmcnt--;
		bpm[++bpmcnt]=buf[i];
	}
	tub[++tbcnt]=get_inter(bpm[1],left);
	for(int i=1;i<bpmcnt;i++){
		tub[++tbcnt]=get_inter(bpm[i],bpm[i+1]);
	}
	tub[++tbcnt]=get_inter(bpm[bpmcnt],right);
}
void query(int fr,int to){//���㵥������
    for(int i=fr;i<=to;i++){
    	if(problem[i].ans==0&&problem[i].kind==1){
    		point* t=lower_bound(tub+1,tub+tbcnt+1,problem[i].p.a);
    		if(t==tub+tbcnt+1){
    			problem[i].ans=1;continue;
			}else if(t==tub+1){
				if(problem[i].p.a.y<tub[1].y-eps){
					problem[i].ans=1;continue;
				}
				//TLE
				
			}else{
				point* fr=t-1;
				if(!onleft((*fr),*t,problem[i].p.a)){
					problem[i].ans=1;continue;
				}
			}
		}
	}
}
//-------------------
void solve(int fr,int to){//CDQ���κ���ܺ���⣬��������
    if(fr+10>=to){//����
        for(int i=fr;i<=to;i++) if(problem[i].kind==1&&problem[i].ans==0)
            for(int j=fr;j<=i;j++) if(problem[j].kind==0)
                if(!onleft(problem[j].p.a,problem[j].p.b,problem[i].p.a)){
                    problem[i].ans=1;break;
                }
    }else{
        int mid=(fr+to)>>1;
        solve(fr,mid);solve(mid+1,to);
        build(fr,mid);query(mid+1,to);
    }
}
//-----------------------------------------------
int n;
int main(){
	n=read();
	int fl=0;
	for(int i=1;i<=n;i++){
		int ins=read();
		point p;
		scanf("%llf%llf",&p.x,&p.y);
        problem[i].kind=ins;
        if(ins==0){
            db dis=sqrt(p.x*p.x+p.y*p.y);
            db dis2=KK/dis;
            p=p*(dis2*(1/dis)*0.5);
            problem[i].p.a=p;
            problem[i].p.b=(point){p.x+(p.y/p.x*10),p.y-10};
            if(problem[i].p.b.x<problem[i].p.a.x) swap(problem[i].p.a,problem[i].p.b);
            problem[i].p.cal();
			fl=1; 
        }else{
        	if((p.y<eps&&p.x<eps&&p.y>-eps&&p.x>-eps)||(fl==0)){
        		if(fl){problem[i].kind=3;problem[i].ans=0;continue;}
        		problem[i].kind=3;problem[i].ans=1;continue;
			}
            db dis=sqrt(p.x*p.x+p.y*p.y);
            db dis2=KK/dis;
            p=p*(dis2*(1/dis));
            problem[i].p.a=p;
        }
	}
    solve(1,n);
    for(int i=1;i<=n;i++){
        if(problem[i].kind==1||problem[i].kind==3){
            if(problem[i].ans==0){
                puts("Yes");
            }else{
                puts("No");
            }
        }
    }
	return 0;
} 
