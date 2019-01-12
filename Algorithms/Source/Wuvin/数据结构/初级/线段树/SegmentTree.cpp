#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int L=0,R=1;

struct SegmentTree{
	int l,r;//��ǰ�������� [l,r] 
	long long sum;//��ǰ�����
	
	//��¼���Ҷ��� 
	//SegmentTree* son[2];
	//SegmentTree* lson,rson;
	int son[2];//�����Ϊ son[0] �Ҷ���Ϊ son[1]
	//int lson,rson;
	
}node[N*2];
int root,ini[N],cnt;//cnt ��ǰ�Ѿ����˶��ٸ��ڵ� 
//���������ʼʱΪini 

void buildTree(int &k,int l,int r){//��ʼ��һ������[l,r]�Ľڵ� �� �±�Ϊk 
	k=++cnt;//k = cnt+1; cnt++;
	node[k].l=l;node[k].r=r;//��ʼ��[l,r] 
	if(l==r){//û�ж����� 
		node[k].sum=ini[r];
	}else{//���ǰְ� 
		int mid=( node[k].l+node[k].r )/2;//���ӵ����ҷֽ� 
		buildTree(node[k].son[L],l,mid);//������� ���Ҷ����±�Ϳ��Ա����� 
		buildTree(node[k].son[R],mid+1,r); 
		node[k].sum=node[ node[k].son[L] ].sum + node[ node[k].son[R] ].sum;//���㵱ǰ�ڵ�ĺ� 
	}
}

void modify(int k,int pos,int val){//�޸�  ��ini[pos]�޸�Ϊval 
	if(node[k].l==node[k].r){//���ӣ�  l==r l==pos
		node[k].sum+=val;
		ini[pos]+=val;
	}else{
		int mid=( node[k].l+node[k].r )/2;//���ӵ����ҷֽ� 
		if( pos<=mid ) modify(node[k].son[L],pos,val);//������������ 
		else modify(node[k].son[R],pos,val);
		
		node[k].sum=node[ node[k].son[L] ].sum + node[ node[k].son[R] ].sum;//���㵱ǰ�ڵ�ĺ� 
	}
}

long long query(int k,int ql,int qr){//��ѯ[ql,qr]
	if(node[k].l==ql && node[k].r==qr){
		return node[k].sum;
	}else{
		int mid=( node[k].l+node[k].r )/2;//���ӵ����ҷֽ� 
		if(qr<=mid) return query(node[k].son[L],ql,qr);//ȫ������� 
		else if(ql>=mid+1) return query(node[k].son[R],ql,qr);//ȫ���Ҷ���
		else return query(node[k].son[L],ql,mid) + query(node[k].son[R],mid+1,qr);//�ֿ��� 
	}
}

int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&ini[i]);
	
	buildTree(root,1,n); 
	
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1) modify(root,l,r);
		else printf("%lld\n",query(root,l,r));
	}
	
	return 0;
}
