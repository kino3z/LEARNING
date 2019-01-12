/*
������һ����ֵ���
����֧�ֻ�����������LCT��ETT
֧�ֲ�ѯ������������ETT��DFS��
֧���޸ĵ���DFS���LCT
ETT�ᱻ�ջ�ͼ���޸�Ű��
���ԣ�����toptree���Ҿ��ھ��ᵽ�׸����Ǹ�
������DFS��ò�Ʒ��������»��ǿ��Եġ�
����1Ϊ������DFS
�����ѯ�ĵ㲻��1-newroot��·������ô ��������
����ھ��ǲ�ѯ�Ĳ�������������DFS�����������䡣
(����������ױ��ջ�ͼ�����������£����ǿ��Զ��֡��Ȳ�������һ�¡���lower_bound��)
���Ծͽ���ˡ�
���ڿ���LCT��ô�ģ�ò�Ʊ���ĳ�Toptree����ʵҲ���ǲ�ȫ�ڵ㣩 
hh.......��Ͷ��
ETT���޸��� ����Ҳ�ǿ��Եģ�����ͨ��������Toptree��߷��εļӵ�����
�ڵ���*2�Ĵ��������һ�������ֻ�������ȵ��޸�
o(^��^)o��perfect
��дDFS 
�������̫perfect�ˣ���(^w^)����Ҫ��ô����DFS���أ�
֧��ɾ���ϲ�������splay��̬ά��|(^_^)|
�������ò�ƿ��԰�ETT������������¼����ά��һ��Ӧ�������� 
 ����+lca�����ò��ֻ��LCT�ɻ�
����+lca+�޸�+������Сֵ+merge split-______-̫а���� 
��ʱò��ֻ��Toptree������
��������ԭ����DFS��+����lca�ܽ�������ѵ�����
���Ѻ�������Ϊ������ì�ܵ�
����������ɣ��ڸ���===\     /====
                hole�� =\___/= 
                
��������һ�¾͹��� 
*/ 
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define N 100005 
using namespace std;
int xdscnt,root;int d[N*2];//dfs
//---------xds----------------
const int L=0,R=1,INF=0x3f3f3f3f;
struct xds{
	int fr,to,min,son[2];
}x[1800005];
inline void update(int k){
	if(k==0||x[k].fr==x[k].to) return;
	x[k].min=min(x[x[k].son[L]].min,x[x[k].son[R]].min);
}
void build(int &k,int fr,int to){
	k=++xdscnt;x[k].fr=fr;x[k].to=to;
	if(fr==to){x[k].min=d[fr];return;}
	int mid=(fr+to)>>1;
	build(x[k].son[L],fr,mid);
	build(x[k].son[R],mid+1,to);
	update(k);
}
void change(int k,int xx,int y){
	if(x[k].fr==x[k].to){
		x[k].min=y;d[x[k].fr]=y;return;
	}
	int mid=(x[k].fr+x[k].to)>>1;
	if(mid<xx) change(x[k].son[R],xx,y);
	else change(x[k].son[L],xx,y);
	update(k);
}
int query(int k,int fr,int to){
	if(fr>to) return -INF;
	if(x[k].fr==fr&&x[k].to==to){
		return x[k].min;
	}
	int mid=(x[k].fr+x[k].to)>>1;
	if(fr>mid) return query(x[k].son[R],fr,to);
	else if(to<=mid) return query(x[k].son[L],fr,to);
	else return min(query(x[k].son[L],fr,mid),query(x[k].son[R],mid+1,to));
}
//-------------------------
struct node{
	int st,en,val;
	vector<int> x;
}a[N];
int n,m,cnt,troot,newroot;
void DFS(int u){
	a[u].st=++cnt;
	d[cnt]=a[u].val;
	for(int i=0,len=a[u].x.size();i<len;i++){
		DFS(a[u].x[i]);
	}
	a[u].en=++cnt;
	d[cnt]=a[u].val;
}
inline bool cmp1(const int &aa,const int &bb){
	return a[aa].en<a[bb].en;
}
//--------------------------
int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1,f,v;i<=n;i++){
		scanf("%d%d",&f,&v);
		a[i].val=v;
		if(f!=0){
			a[f].x.push_back(i);
		}else troot=i;
	}
	DFS(troot);newroot=troot;
	build(root,1,n<<1);
	for(int i=1;i<=m;i++){
		char s[3];
		int xx,yy;
		scanf("%s",&s);
		if(s[0]=='V'){
			scanf("%d%d",&xx,&yy);
			change(root,a[xx].st,yy);
			change(root,a[xx].en,yy);
		}else if(s[0]=='E'){
			scanf("%d",&xx);
			newroot=xx;
		}else if(s[0]=='Q'){
			scanf("%d",&xx);int ans=0;
			if(xx==newroot){
				ans=query(root,1,n<<1);
			}else if(a[xx].st<a[newroot].st&&a[xx].en>a[newroot].en){
				vector<int>::iterator itr=lower_bound(a[xx].x.begin(),a[xx].x.end(),newroot,cmp1);
				xx=*itr;
				ans=min(query(root,1,a[xx].st-1),query(root,a[xx].en+1,n<<1));
			}else{
				ans=query(root,a[xx].st,a[xx].en);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
} 
