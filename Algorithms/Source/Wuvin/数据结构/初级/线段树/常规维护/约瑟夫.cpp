#include<cstdio>
/*
���߶�����Լɪ�򣬺����~~
�߶���֧�֣�
���ҵ�k���ڵ��ֵ
ɾ����k���ڵ� 
*/
using namespace std;
int n,m;
struct xds{
	xds *left,*right;
	int st,xx;
	int mid,son1;
	xds(int start,int x){//��start��ʼ x�� 
		st=start;xx=x;
		if(x==1) return;
		son1=x/2;
		left=new xds(st,son1);
		right=new xds(st+son1,x-son1);
	}
	void del(int k){
		if(xx==1){printf("%d ",st);return;}
		if(k<=son1)	left->del(k),son1--;
		else right->del(k-son1);
	}
};
int main(){	
	scanf("%d%d",&n,&m);
	xds mytree(1,n);
	int nn=n;
	for(int p=0,i=1;i<=nn;i++){
		p+=m;p%=n;
		if(p==0) p=n;
		mytree.del(p);
		p--;n--;
	}
	return 0;
}
