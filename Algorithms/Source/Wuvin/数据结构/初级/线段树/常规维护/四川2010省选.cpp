#include<cstdio>

/*
***�Ĵ�2010ʡѡ  ���в���
0 a b ��[a, b]�����ڵ�������ȫ���0
1 a b ��[a, b]�����ڵ�������ȫ���1
2 a b ��[a,b]�����ڵ�������ȫ��ȡ����Ҳ����˵�����е�0���1�������е�1���0
3 a b ѯ��[a, b]�������ܹ��ж��ٸ�1
4 a b ѯ��[a, b]����������ж��ٸ�������1 
*/
using namespace std;
struct node{
	int left,right,mid;//���� (left,mid)  (mid+1,right) 
	int index;//���  �����index*2 �Ҷ���index*2+1 
	int cz[3];//���ֲ��� 1 2 3   1Ҫ���� �����һ����1 0-not nessary 
	void addcz(int *t){}//�������
		if(t[0]==1){//���� 
			cz[1]=0;cz[0]=1;cz[2]=0;
		}else if(t[1]==1){//��һ 
			cz[0]=0;cz[1]=1;cz[2]=0;
		}else if(t[2]==1){//ȡ�� 
			if(cz[0]==1){
				cz[0]=0;cz[1]=1;cz[2]=0;
			}else if(cz[1]==1){
				cz[0]=1;cz[1]=0;cz[2]=0;
			}else if(cz[2]==1){
				cz[0]=0;cz[1]=0;cz[2]=0;
			}else{
				cz[0]=0;cz[1]=0;cz[2]=1;
			} 
		}
		return;
	}
	int yi,ling;//1��0�ĸ���
	int l1,r1,l0,r0;//��������������0 1
	int long1,long0;//�м��0 1
	int qing;//��һɫ 0��=10�� ���� 1��=11��  
	void doit(){}//���в���
		if(cz[0]){
			l0=r0=right-left+1;
			l1=r1=0;
			long1=0;long0=l0;
			yi=0;ling=l0;
		}else if(cz[1]){
			l1=r1=right-left+1;
			l0=r0=0;
			long1=l1;long0=0;
			yi=long1;ling=0;
		}else if(cz[2]){
			swap(l0,l1);swap(r0,r1);swap(long0,long1);swap(yi,ling);
		}
		int len=right-left+1;
		if((l0==len)||(r0==len)){
			qing=10;
		}else if((l1==len)||(r1==len)){
			qing=11;
		}else{
			qing=0;
		}
		return 0;
	}
	void fresh(const node& lson,const node& rson){//�����ӽڵ�ˢ�� 
		if(left==right){
			return;
		}
		yi=lson.yi+rson.yi;ling=lson.ling+rson.ling;
		if(lson.qing==11){//���ȫ1 
			l1=lson.l1+rson.l1;l0=0;
			if(rson.qing==11){
				r1=l1;r0=0;
				long1=l1;long0=0;qing=11;
			}else{
				r1=rson.r1;r0=rson.r0;
				long1=rson.l1+lson.l1;long0=rson.long0;qing=0;
			}
		}else if(lson.qing==10){//���ȫ0 
			l0
		} 
	}
}; 
int main(){
	
	return 0;
}
