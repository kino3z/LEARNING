#include<bits/stdc++.h>
using namespace std;
/*---------------------------
�����ݽṹ��Ҫ֧�ֵĲ���
�����ֵΪK�Ľڵ�
��ѯ��K��Ľڵ� 
ɾ����ֵ��KС�Ľڵ� 
�ðɣ������ڲ����� 

����������̸һ��treap������ʲô
������֪��BST(���������)�ڻ�������Ķ����
��������ǰ�Ǹ����
20����������������ݻὨ����
����Ҫ����һ�������������
��Ȼ����Ҫ���Լ�������������Ŀ���
���������鷳Ҳ������
so������������һ���ж����ʵ�BST
��ΪBST���Ӹ��еĲ�������
��Ϊ�������ȷ����״�Ա�֤������
������������ά�������� 
 
��˵һ��splay����չ����
1������һ��BST
2����Ҳ�ж�����
3��ͬʱ���԰�ĳ����ת������Ȼ����Է��Ѻͺϲ�//����֮�����ϸ�Ĵ���С�ڹ�ϵO��1��
											//����sizeС�������β������O��nlogn) 
4����Ȼ���ݡ��˶���ԭ�򣬰���Ҫ��ת�����������õ�  
-----------------------------*/
const int L=0;
const int R=1;
struct Treap{
	//����key1��ȷ��BST
	//����key2��ȷ�������� 
	int gz;//���ʼ����� �ؼ���key1 
	int size;//�����ӽڵ����� �����Լ� 
	Treap* son[2];
	Treap(int k){
		gz=k;son[L]=son[R]=NULL;
	}
	int sum(){//��ʼ��size 
		if(son[L]==NULL){
			if(son[R]==NULL){
				size=1;
			}else{
				size=1+son[R]->sum();
			}
		}else{
			if(son[R]==NULL){
				size=1+son[L]->sum();
			}else{
				size=1+son[L]->sum()+son[R]->sum();
			}
		}
		return size;
	}
	
	void check(Treap* &tothis){//��鵱ǰ�ڵ��Ƿ���϶����ʷ�����ת 
	} 
	
	int add(int k){//��С�Ҵ�  //(���ⲻ��)��Ȼ��Ҫά�������� 
		int si=k<gz ? L:R;
		if(son[si]!=NULL){
			son[si]->add(k);
		}else{
			son[si]=new Treap(k);
		}
	}
	//��ת��ǰ�ڵ㵽����  side=L ��ת��Ϊ������ 
	void Turn(int side,Treap* &tothis){
		Treap* k=tothis->son[side^1];
		tothis->son[side^1]=k->son[side];
		k->son[side]=tothis;
		tothis=k;
	}
};


int main(){
	
	return 0;
}
