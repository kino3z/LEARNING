/*-------------------
codevs 1285
��Treap 
---------------------*/
#include<bits/stdc++.h>
using namespace std;
const int L=0;
const int R=1;
const int NO_nessary=-1;
const int Turn_Myleftson=0;
const int Turn_Myrightson=1;
struct Treap{
	int key;//size��ȫ���Լ��ֶ����� 
	int pri;//priority
	Treap* son[2];
	Treap(){
	}
	Treap(int keys){
		key=keys;son[L]=son[R]=NULL;
	}
	void add(int x){//�����ֵΪx�Ľڵ� 
		int side=(x<key)? L:R;
		if(son[side]==NULL){
			son[side]=new Treap(x);
		}else{
			son[side]->insert(x);//��Ϊ���������ݹ鶯�� 
		}
	}
	/*---------BST����д�꣬�Ѳ��ֿ�ʼ---------*/
	void zhuan(int from,int side){//����son[from]���߸��ڵ���Ҫ��תside�������ڵ� 
		Treap* s=son[from];Treap* gs=s->son[side];//grandson
		s->son[side]=gs->son[side^1];
		gs->son[side^1]=s;
		son[from]=gs; 
	}
	int check(){//�����Ƿ���Ҫ��ת �����Ҫ���ط��� 
		if(son[L]==son[R]==NULL){
		}else if(son[L]==NULL){
			if(son[R]->pri > pri){
				return Turn_Myrightson;
			}
		}else if(son[R]==NULL){
			if(son[L]->pri > pri){
				return Turn_Myleftson;
			}
		}else{
			int ma=max(son[L]->pri,son[R]->pri);
			if(ma>pri){
				if(son[L]->pri==ma){
					return Turn_Myleftson;
				}else{
					return Turn_Myrightson; 
				}
			}
		}
		return NO_nessary;
	}
	/*--------�Ѳ������------------*/
	void insert(int x){
		add(x);
		
	} 
};

int main(){
	return 0;
} 
