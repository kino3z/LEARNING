#include<cstdio>
#include<algorithm> 
using namespace std;
/*
�������������˰�������
�Ǿ�����ʽ+ѹλ�� �O(m*2^n) 
��Ҫrank1 
*/
inline int read(){
	char c=' ';
	while(c=='\n'||c==' ') c=getchar();
	return c-'0';
}
int n,m;
int ques[102];
int num[102],ones[102];//the answer of the number of 1s in the int 
int next[102];//next[0] shows the begining . if(next[i]==0) then its end;


int nn[102];
bool prework(){
	scanf("%d%d",&n,&m);bool ncf=false;
	for(int i=1;i<=m;i++){
		int f=0;
		for(int j=1;j<=n;j++){
			f<<=1;f&=read();
			if(f&1) ones[i]++;
		}
		ques[i]=f;
		scanf("%d",&num[i]);
		nn[i]=num[i];
		if(num[i]>ones[i]) ncf=true;
	}
	if(ncf) return false;
	for(int i=1,p=1,last=0;i<=n;i++,p<<=1){
		bool confirm=false;int ne=0;int mmin=200;
		for(int j=1;j<=m;j++){
			if(ques[j]&p){
				confirm=true;
				if(mmin>ones[j]){
					mmin=ones[j]-1;
					ne=j;
				}
				ones[j]--;
			}
		}
		if(confirm){
			next[last]=ne;
			/*
			�ð��ҷ���
			ò������������������ر��д
			ӦΪ������ֻ��2��ѡ��
			������������û��������ôǿ��
			����ÿ����ѡ��ʣ��δȷ���������ٵ�
			���������Ӧ�û��кü�ʮ��
			ÿ����λ�û�����
			���Ի���ֱ��ö��+����� 
			*/
		}else{
			return false;
		}
	}
}
int main(){
	
	return 0;
}
