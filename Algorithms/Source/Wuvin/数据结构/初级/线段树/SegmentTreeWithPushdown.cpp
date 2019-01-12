#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int L=0,R=1;

struct SegmentTree{
	int l,r;//��ǰ�������� [l,r] 
	//long long sum;//��ǰ�����
	long long add;//��ǰ����ÿ�������˶��� 
	//��¼���Ҷ��� 
	//SegmentTree* son[2];
	//SegmentTree* lson,rson;
	int son[2];//�����Ϊ son[0] �Ҷ���Ϊ son[1]
	//int lson,rson;
	
}node[N*2];
int root,ini[N],cnt;//cnt ��ǰ�Ѿ����˶��ٸ��ڵ� 
//���������ʼʱΪini 

void pushdown(int k){//�ѽڵ�K�ϵ���ֵ�´� 
	if(node[k].add==0 || node[k].l==node[k].r ) return;//û����Ҫ�´��� ���� û�ж��� 
}

void buildTree(int &k,int l,int r){//��ʼ��һ������[l,r]�Ľڵ� �� �±�Ϊk 
	k=++cnt;//k = cnt+1; cnt++;
	node[k].l=l;node[k].r=r;//��ʼ��[l,r] 
	if(l==r){//û�ж����� 
		//do nothing
	}else{//���ǰְ� 
		int mid=( node[k].l+node[k].r )/2;//���ӵ����ҷֽ� 
		buildTree(node[k].son[L],l,mid);//������� ���Ҷ����±�Ϳ��Ա����� 
		buildTree(node[k].son[R],mid+1,r); 
		//node[k].sum=node[ node[k].son[L] ].sum + node[ node[k].son[R] ].sum;//���㵱ǰ�ڵ�ĺ� 
	}
}

void modify(int k,int ql,int qr,int val){//[ql,qr] += val
	pushdown(k);
	if( node[k].l==ql && node[k].r==qr ){
		node[k].add+=val;//���� 
	}else{
		//pushdown
		int mid=( node[k].l+node[k].r )/2;//���ӵ����ҷֽ� 
		if(qr<=mid) modify(node[k].son[L],ql,qr,val);
		else if( mid<ql ) modify(node[k].son[R],ql,qr,val);
		else modify(node[k].son[L],ql,mid,val) , modify(node[k].son[R],mid+1,qr,val);
	}
}

long long query(int k,int pos,int val){
	pushdown(k);
	if( node[k].l==node[k].r ){// l==r==pos
		return node[k].add+ini[pos];
	}else{
		int mid=( node[k].l+node[k].r )/2;//���ӵ����ҷֽ� 
		if( pos<=mid ) return query(node[k].son[L],pos,val);
		else return query(node[k].son[R],pos,val);
	}
} 

int n,m;
int main(){
	
	return 0;
}
