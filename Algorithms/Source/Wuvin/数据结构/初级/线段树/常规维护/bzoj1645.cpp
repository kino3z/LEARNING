/*
�������STLˮ����ֵ���߶�����ƽ����ˮ��
���һ��ǻ���������һ������ȡmax�ɡ�
���һ���һ������ȡmax
���WCӪԱ����segment tree beats
�ȵ�ò�ƻ�Ҫ��ɢ�����ظ�Ȩ������
�����ˣ�Ӳ������������������ȡmax�治�Ǻ����⣩��
����ȡmax������������ɶ�̬�������޷����ˣ�
����������ߺ���Ҳû��ʲô�����ķ�����
���԰�������߶�ֵҪ��double������������ûʲôӰ��
�ȵȸ߶�ֵ��������10^18��double��longdouble�ľ���Ҫ��
�ðɣ����Ȿ���Ͳ�������ȡmax��ġ�
�ͼ���ȡmax����Ҫ����fimin,semin�Լ����Եĸ����Ͷ��ˡ�
����
*/
#include<cstdio>
#include<iostream>
#define N 200005
using namespace std;
int n,m,cnt,root;
const int L=0,R=1;
struct opera{
    int l,r,h;
    double hi;
    LL li,ri;
}q[40005];
struct lshh{
    int *a;int name;
}lsh[80005];
//--------xds-----------

//----------------------
void pre(){
    for(int i=1;i<=m;i++){
        lsh[i*2-1].a=&q[i].l;
    }
}
//----------------------
int main(){
    
    
    return 0;
}