#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
/*-----------------------------------------------------
�������㷨
����ͼƥ��
O(mn)
�з���/�����ٽ���� 

codevs1222
ֱ��ɾ���������Ƿ����
ɾ�˾Ϳ��Բ��û���ȥ�� 
-----------------------------------------------------*/
int n;
int map[105][105];//  x,y   1-false
bool vis[105];//���y 
int pi[105];//y���ƥ�� 0-δƥ��
int pix[105];
int cur[105];
bool find(int u){//ƥ��u��  u->x
	for(int i=1;i<=n;i++){
		if(map[u][i]!=1&&vis[i]==false){
			vis[i]=true;
			if(pi[i]==0){//�ҵ�δƥ��� 
				pi[i]=u;
				pix[u]=i;
				return true;
			}else{
				int c=pi[i];//���� 
				pi[i]=u;
				if(find(c)){//��г 
					pix[u]=i;
					return true;
				}else{
					pi[i]=c;//����г����ȥ 
					continue;
				}
			}
		}
	}
	return false;
}
int main(){
	scanf("%d",&n);
	int a=0,b=0;
	do{
		map[a][b]=1;
		scanf("%d%d",&a,&b);
	}while(a!=0);
	fill(cur+1,cur+n+1,1);
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		if(find(i)) ans++;
	}
	if(ans!=n){
		printf("none");
		return 0;
	} 
	bool fl=false;
	//��ʼɾ��
	for(int i=1;i<=n;i++){
		int last=0;
		if(pix[i]==0){
			continue;
		}else{//��ƥ�� 
			last=pix[i];
			map[i][last]=1;
			pix[i]=0;
			pi[last]=0;
		}
		memset(vis,false,sizeof(vis));

		if(!find(i)){
			fl=true;
			printf("%d %d\n",i,last);
			pi[last]=i;
		}
		map[i][last]=0;
	} 
	if(!fl){
		printf("none");
	}
	return 0;
}
