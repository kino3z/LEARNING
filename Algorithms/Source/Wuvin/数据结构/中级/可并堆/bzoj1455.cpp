#include<cstdio>
#include<iostream>
#include<cstdlib>
/*
ʵ�������Ѿ����˶Ѹ���ôд��
��Ȼ��ֻ������һ��д�ˡ�
���ڲ��룬Ϊ�˷�ֹ�����������Ӹ�����Ͷ��ˡ�����ʵ���Կ�ѧһ��ͳ��size��
����ɾ�����ƣ�Ϊ�˷��գ�ÿ���ѳ�ʼ��ʱ��һ��INF
���ںϲ�����˵�еݹ�ϲ��ķ��������ҵ���û��ϸ����
ֻ���Բ�һ�£�ȥ����������С��Ԫ�ر�����С����Ϊ����
�������ߵĶѣ���һ����ֻ��ֱ�Ӳ����ˡ�
��һ���Գ����10^6��INF��ֹ�ҵ�����ʵ֤��û���ã���T��
ɾ����A��
ò������Բ��ı���ƫ��һ��

��Ȼ��˿϶������Ż���del��������һ��Ҫ��ʵ���¸�10�������� 
��ʵ֤��������logn�����ͱȽ�С���Ҳ��ʮ�������Բ�û��ʲô�� 

��������inline������100ms����Χ���� 
*/
#define INF 99999999
#define DEEP 3
#define N 2000005 //10^6  �Ҹо���logn�Ķ�Ҫ�ң��Ѳ������ѣ��Ҳ��ᡣ��
using namespace std;
const int L=0,R=1;//С����
int n,m,cnt;
int root[N],son[N][2],deleted[N];
struct person{
    int mark,name;
    inline bool operator <(const person &b){
    	if(name==0||b.name==0) return name>b.name;
        return mark<b.mark;
    }
}val[N];
bool died[N];
inline void insert(int &k,person &val_){
    if(k==0){
        k=++cnt;son[k][L]=son[k][R]=0;val[k]=val_;
    }else{
        if(val_<val[k]) swap(val_,val[k]);
        insert(son[k][(rand()&(1<<2))>>2],val_);
    }
}
inline void del(const int &k,int deep){
    if(val[k].name==0) return;
    if(deep<=0&&deleted[k]==false){
    	deleted[k]=true;return;
	}
	int s=val[son[k][L]]<val[son[k][R]]? L:R;
	if(deleted[son[k][s]]) deleted[son[k][s]]=false,del(son[k][s],DEEP);
	s=val[son[k][L]]<val[son[k][R]]? L:R;
    val[k]=val[son[k][s]];
	del(son[k][s],deep-1);
}
//ò�ƻ���Ҫһ��bcj
int bcj[N];
inline int ff(int k){
	return bcj[k]=(bcj[k]==k)? k:ff(bcj[k]);
}
inline void connect(int a,int b){//a->b
    bcj[ff(a)]=ff(b);
}
inline void merge(int a,int b){//�ϲ���abΪ����bcj
    a=ff(a);b=ff(b);
    if(!(val[root[a]]<val[root[b]])) swap(a,b); //_aΪ��
    person t=val[root[a]];del(root[a],DEEP);
    int k=++cnt;son[k][L]=root[a];son[k][R]=root[b];val[k]=t;root[a]=k;
    connect(b,a);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        bcj[i]=i;//insert(root[i],(person){INF,0});ò�Ʋ��÷�ֹ���ʿսڵ㣬��Ȼ�൱����������һ������T 
    }
    for(int i=1;i<=n;i++){
        int t;scanf("%d",&t);
        person buf=(person){t,i};
        insert(root[i],buf);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        char c=getchar();while(c==' '||c=='\n'||c=='\r') c=getchar();
        if(c=='M'){
            int a,b;scanf("%d%d",&a,&b);
            if(died[a]==false&&died[b]==false){
                merge(a,b);
            }
        }else{
            int a;scanf("%d",&a);
            if(died[a]==false){
                a=ff(a);
                printf("%d\n",val[root[a]].mark);
                died[val[root[a]].name]=true;
                del(root[a],DEEP);
            }else{
                puts("0");
            }
        }
    }
    return 0;
}
