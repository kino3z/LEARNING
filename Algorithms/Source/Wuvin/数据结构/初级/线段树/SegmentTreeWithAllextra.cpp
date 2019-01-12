#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int L=0,R=1;

struct Message{//�ڵ�ά������Ϣ 
	long long sum,len,add,mul;//����� ���䳤�� ����lazy�ļӷ�  ����lazy�ĳ˷�
	/*
	ans = ans*mul + add
	*/ 
	Message(){//��ʼ������ 
		sum=0;add=0;len=0;mul=1;
	}
	Message(long long xsum,long long xlen,long long xadd,long long xmul){//��ʼ������ 
		sum=xsum;len=xlen;add=xadd;mul=xmul;
	}
	Message operator +(const Message &b){//���� a+b 
		Message p(sum+b.sum,len+b.len,0,1);
		return p;
	}
	/*
	(ans * mul + add) * famul + faadd 
	*/
	void modify(Message fa){//���׵���ϢΪfa �� ����pushdown�´� 
		mul=mul*fa.mul;
		add=add*fa.mul+fa.add;
		sum=sum*fa.mul+fa.add;
	}
};

struct SegmentTree{
	int l,r;//��ǰ�������� [l,r] 
	int son[2];//�����Ϊ son[0] �Ҷ���Ϊ son[1]
	Message x;
}node[N*2];

void pushdown(int k){//�´���� 
	if( node[k].x.add!=0 ){
		node[ node[k].son[L] ].x.modify( node[k].x );
		node[ node[k].son[R] ].x.modify( node[k].x );
		node[k].x.add=0;
	}
}

void update(int k){//���½ڵ�k 
	node[k].x=node[node[k].son[L]].x + node[node[k].son[R]].x;
}


int root,ini[N],cnt;//cnt ��ǰ�Ѿ����˶��ٸ��ڵ� 
//���������ʼʱΪini 

void buildTree(int &k,int l,int r){//��ʼ��һ������[l,r]�Ľڵ� �� �±�Ϊk 
	k=++cnt;node[k].l=l;node[k].r=r;node[k].x.len=(r-l+1); //��ʼ��[l,r] //k = cnt+1; cnt++;
	if(l==r){//û�ж����� 
		node[k].x.sum=ini[l];
	}else{//���ǰְ� 
		int mid=( node[k].l+node[k].r )/2;//���ӵ����ҷֽ� 
		buildTree(node[k].son[L],l,mid);//������� ���Ҷ����±�Ϳ��Ա����� 
		buildTree(node[k].son[R],mid+1,r); 
		update(k);
	}
}

Message work(int k,int ql,int qr,Message y){//�޸� [ql,qr] ˳����ѯ[ql,qr] 
	if( ql<=node[k].l && node[k].r<=qr ){
		node[k].x.modify(y);
		return node[k].x;
	}else if(ql>node[k].r || qr<node[k].l ) return ��;
	else{
		Message p;
		pushdown(k);
		p=work(node[k].son[L],ql,mid,y) + work(node[k].son[R],mid+1,qr,y);
		update(k);
		return p;
	}
}
/*
Message work(int k,int ql,int qr,Message y){//�޸� [ql,qr] ˳����ѯ[ql,qr] 
	if( node[k].l==ql && node[k].r==qr ){
		node[k].x.modify(y);
		return node[k].x;
	}else{
		Message p;
		pushdown(k);
		int mid = (node[k].l+node[k].r)/2;
		if(qr<=mid) p=work(node[k].son[L],ql,qr,y);
		else if(mid<ql) p=work(node[k].son[R],ql,qr,y);
		else p=work(node[k].son[L],ql,mid,y) + work(node[k].son[R],mid+1,qr,y);
		update(k);
		return p;
	}
}
*/

int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&ini[i]);
	
	buildTree(root,1,n); 
	
	Message ans;int l,r,val;
	//����[l,r] += val 
	Message y;
	y.add=val;
	work(root,l,r,y);
	//����[l,r] *= val 
	Message y;
	y.mul=val;
	work(root,l,r,y);
	//��ѯ����[l,r] 
	y.add=y.len=y.sum=0;
	ans=work(root,l,r,y);
	cout<<ans.sum<<endl;
	//
	
	//
	
	return 0;
}
