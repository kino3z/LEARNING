#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int NN=1000+5;
const int MM=27;
struct ACzdj{
	int ch[NN][MM];
	int val[NN];
	int f[NN];
	int size;
	int root;
	int transform(char &h){
		return h-'a';
	}
	ACzdj(){
		memset(ch,0,sizeof(ch));
		memset(f,0,sizeof(f));
		memset(val,0,sizeof(val));
		//��ʼ��0 
		size=1;root=0;
	}
	void addword(char* s,int key){//key != 0
		int len=strlen(s);
		int p=root;
		for(int i=0;i<len;i++){
			int d=transform(s[i]);
			if(ch[p][d]){
				p=ch[p][d];
			}else{
				ch[p][d]=size++;
				p=ch[p][d];
			}
			if(i==len-1){
				val[p]=key;
			}
		}
	}
	void prefail(){//ʧ�����ת��һ��ͬ�� 
		queue<int> x;
		for(int i=0;i<MM;i++){//��һȦ 
			if(ch[root][i]){
				x.push(ch[root][i]);
			}
		}
		while(!x.empty()){
			int u=x.front();x.pop();
			/*ǧ��������� ��Ȼ��hack*/if(val[f[u]]!=0) f[u]=val[f[u]]; 
			for(int i=0;i<MM;i++){
				int v=ch[u][i];
				if(v==0){//ʧ��  �� 
					ch[u][i]=ch[f[u]][i];continue;
				}
				f[v]=ch[f[u]][i];
				x.push(v);
			}
		}
	}
	
	int find(char *s){//��������ģ���е�һ��ƥ�� 
		int sl=strlen(s);
		int p=root;
		for(int i=0;i<sl;i++){
			int d=transform(s[i]);
			p=ch[p][d];
			if(val[p]){
				return val[p];
			}
		}
		return 0;
	}
};
/*
hack:
2
aca 100
c 10

*/

int main(){
	ACzdj ac;
	int n;
	scanf("%d",&n);
	char p[100];
	for(int j,i=1;i<=n;i++){
		scanf("%s",p);
		scanf("%d",&j);
		ac.addword(p,j);
	}
	ac.prefail();
	printf("%d",ac.find("ac"));
	return 0;
}
