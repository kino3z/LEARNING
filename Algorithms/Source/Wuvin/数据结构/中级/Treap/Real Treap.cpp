#include<cstdio>
#include<cstring>
#include<iostream>
/*
������ Treap
ͬʱӵ�жѺ���������������� 
priorityΪ��  valueΪ��������� 
��д��ʽ��������� 
�������ʽ������������ 
֧�ֶ�����
	���룺�ݹ����
	ά�������ʣ��ݹ� 
	ͳ���ֽڵ���������ǵݹ���� 
	���ҵ�K���Ԫ�أ��ݹ����
	ɾ��ĳ�㣺ά�������ʵ�ͬʱ��ת��Ҷ�ڵ㣬Ȼ��ɾ�� 
	
*/
using namespace std;
const int LEFT=0,RIGHT=1;
struct Treap{
	Treap* son[2];
	int value,priority;
	Treap(){
		son[0]=son[1]=NULL;
		value=priority=0;
	}
	Treap(int v,int p){
		son[0]=son[1]=NULL;
		value=v;
		priority=p;
	}
};


Treap** findbyvalue(Treap* &fa,int v){
	int side=-2;
	if(v<fa->value){
		side=LEFT;
	}else if(v==fa->value){
		return &fa;
	}else{
		side=RIGHT;
	}
	if(fa->son[side]!=NULL){
		return findbyvalue(fa->son[side],v);
	}
	return NULL;
}


//��side��ߵ��ӽڵ���ת���� 
void turn(int side,Treap* &u){
	Treap* s=u->son[side];
	u->son[side]=s->son[side^1];
	s->son[side^1]=u;
	u=s;
}

void check(Treap* &u){
	int mv=-1000,side=-1;
	if(u->son[LEFT]!=NULL){
		mv=u->son[LEFT]->value;
		side=LEFT;
	}
	if(u->son[RIGHT]!=NULL){
		if(u->son[RIGHT]->value>mv){
			mv=u->son[RIGHT]->value;
			side=RIGHT;
		}
	}
	if(side!=-1&&mv>u->priority){//��ת 
		turn(side,u);
	}
}

void addTreap(Treap* &fa,int v,int p){
	int side=-1;
	if(v<=fa->value){
		side=LEFT;
	}else{
		side=RIGHT;
	}
	if(fa->son[side]==NULL){//��ӽڵ� 
		fa->son[side]=new Treap(v,p);
	}else{
		addTreap(fa->son[side],v,p);
	}
	check(fa);//ά�������� 
}


//fa->value
//fa->son[0]->value
//fa->son[1]->value
//fa->son[0]
//fa->son[1]
void killpoint(Treap* &fa){
	fa->priority=-10000;
	if(fa->son[LEFT]==NULL&&fa->son[RIGHT]==NULL){
		delete fa;
		fa=NULL;
		return;
	}
	check(fa);
	int side=-1;
	if(fa->son[LEFT]!=NULL){
		if(fa->son[LEFT]->priority==-10000){
			side=LEFT;
		}else{
			side=RIGHT;
		}
	}else{
		side=RIGHT;
	}
	killpoint(fa->son[side]);
	return;
}

void deletebyvalue(Treap* &fa,int v){
	Treap** s=findbyvalue(fa,v);
	if(s!=NULL){
		killpoint(*s);
	}
	
}


//f->value
//f->son[0]->value
//f->son[1]->value
//f->son[0]
//f->son[1]
void jianch(Treap* f){//���������� 
	if(f->son[LEFT]!=NULL){
		jianch(f->son[LEFT]);
	}
	cout<<f->value<<endl;
	if(f->son[RIGHT]!=NULL){
		jianch(f->son[RIGHT]);
	}
	return;
}

int main(){//ע��ά�������ʵĹؼ����������ʼ���� 
	Treap tp(10,10);
	Treap* x=&tp;
	addTreap(x,6,6);
	addTreap(x,4,4);
	addTreap(x,5,5);
	addTreap(x,11,11);
	addTreap(x,1,1);
	deletebyvalue(x,5);
	jianch(x);
	return 0;
}
