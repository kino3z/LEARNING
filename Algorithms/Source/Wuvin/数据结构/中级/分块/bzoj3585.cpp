#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 200001
#define N (200005*20*2)
using namespace std;
/*
�����Ѿ�����4�����ˣ����У�����ôҲҪˮ��һ���� 
��ϯ��ˮ�� 
���ջ������Ǿ䣬����һ��ֵͬ���ӣ����÷ֿ�+ST��nlogn-sqrt(n)--�ռ�nlogn��/��ϯ��(nlogn-logn--�ռ�nlogn(����))
r[i]��¼Ϊ��a[i]ֵ��ͬ�������ұߵ�һ�γ��ֵ�λ��
l[i]ͬ��
ÿ�β�ѯ��������������
e...MLE,��÷ֿ顣 

�ðɣ��������⣬Ӧ������+Ī��+�߶���ά��ת��

���˵���⣺
˫�������⡭�����������YY�˺ܾ�ҲûYY�����⡭��������YY�����˰ɣ�YY������YYYY�� 
���ȴ�1��i��mex����ɣ��Ǿ����������Ԥ����һ��ÿ��������һ������λ���Ƕ���
�㷢�����Ѿ��ܻش�l==1��ѯ���� = = ��,��ô����������i�Ƶ�i+1�أ�
��i��i+1�ı仯����ȡ����a[i]��Ӱ�죬Ҳ����˵[i,next[i]-1]��mex=min(mex,a[i])���ǵ�mex�ǵ����ģ����Ÿ��¾ͺ���
�������ֿ��Իش���l==i+1��β��ѯ���ˡ��������������ͺ��ˡ��������������
*/
const int L=0,R=1;
int n,m,t,cnt;//tΪȫ��û�г��ֵ���С��Ȼ�� include 0 
int a[INF];
int sor[INF];
//��ϯ�� 
int son[N][2],minn[N],root[INF],rvroot[INF];
void add(int &k,int fr,int to,int &fi,int &c){
	int f=++cnt;
	son[f][L]=son[k][L];son[f][R]=son[k][R];minn[f]=min(minn[k],c);
	k=f;
	if(fr==to) return;
	int mid=(fr+to)>>1;
	if(fi<=mid) add(son[k][L],fr,mid,fi,c);
	else add(son[k][R],mid+1,to,fi,c);
}
/*
int query(int pf,int pt,int fr,int to){
	if(fr==to) return fr;
	int side=-1;int mid=(fr+to)>>1;
	if(sum[son[pt][L]]-sum[son[pf][L]]<mid-fr+1)//���ԣ��ⲻ�ܶ�����Ӧ�ö��ԣ����ԾͲ�֧���������
	//���ˣ����ֹ��ˡ�����TTTTTTTATTTTTTT 
    /*�Һ�������ֿ��� (��'v'��)*//*
}*/

int queryfr(int k,int c,int fr,int to){//>=c
    if(fr>=c){//ȫ����
        return minn[k];
    }
    int mid=(fr+to)>>1;
    if(c>mid) return queryfr(son[k][R],c,mid+1,to);
    else return min(queryfr(son[k][R],c,mid+1,to),queryfr(son[k][L],c,fr,mid));
}
int querybk(int k,int c,int fr,int to){//<=c
    if(to<=c){
        return minn[k];
    }
    int mid=(fr+to)>>1;
    if(c<=mid) return querybk(son[k][L],c,fr,mid);
    else return min(querybk(son[k][L],c,fr,mid),querybk(son[k][R],c,mid+1,to));
}
int biao[INF];
int r[INF];
int l[INF];
bool cmp(const int &a1,const int &a2){
	return a[a1]<a[a2];
}
int main(){
    minn[0]=INF;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sor[i]=i;
	}
	sort(sor+1,sor+n+1,cmp);
	bool fl=false;
	a[0]=-1;
	for(int i=1;i<=n;i++){//��ɢ��+ɨ�� 
		if(!fl){
			if(a[sor[i]]>a[sor[i-1]]+1)
				t=a[sor[i-1]]+1,fl=true;
		}else a[sor[i]]=t+2;//�������Źҵ��� 
	}
	if(t==0) t=a[sor[n]]+1; 
    for(int i=1;i<=n;i++){
        l[i]=biao[a[i]];biao[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        r[l[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(r[i]==0) r[i]=n+1;
    }
	for(int i=1;i<=n;i++){
		root[i]=root[i-1];
		add(root[i],0,n+1,r[i],a[i]);
	}
    for(int i=n;i>=1;i--){
        rvroot[i]=rvroot[i+1];
        add(rvroot[i],0,n+1,l[i],a[i]);
    }
	for(int i=1;i<=m;i++){
		int f,t2;
		scanf("%d%d",&f,&t2);
        int ans=min(t,queryfr(root[f-1],t2+1,0,n+1));
        ans=min(ans,querybk(rvroot[t2+1],f-1,0,n+1));
		printf("%d\n",ans);
	}
	return 0;
}
