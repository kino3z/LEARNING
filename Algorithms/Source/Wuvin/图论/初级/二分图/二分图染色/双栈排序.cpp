#include<cstdio>
#include<iostream>
#include<vector>
/*
����һ���������Ŀ(�����ò��鼯)
���� a b c d a-1 1 a+e ����
��������a ����c>b>a>d 
������Ҫ����1234����n��˳�򵯳�
����a��ջ��bcһ������ѹ��a���棬ֻ���ڶ����ջ
��d��aС������d���ţ�����a���Ӱ��
a-1ͬ��
//����a-1������͸õ�a�ˣ�����ef�ǲ��ÿ��ǵ�(����)
����ʱa-1����һ���ܵ�����Ҫ�ȵ�a-2���˲��У��Դ�����Ҫһֱ���۵����Ҳ��aС����k���У�
��ͼ��a���Ҳ�k֮ǰ��a�������
���ڰ�Ⱦɫ
����ʲô�ֵ���֮���
�ӵ���ͨ�����Ͷ���
Ȼ���ҾͲ���д�����ˡ�����
*/
using namespace std;
const int black=1;
const int white=2;//stack 1
int n;
int xl[1005];
int rxl[1005];//reverse
int map[1005][1005];
int color[1005];//
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&xl[i]);
	}
	for(int i=1;i<=n;i++){
		rxl[xl[i]]=i;
	}
	color[1]=white;
	for(int i=2;i<=n;i++){
		for(int j=)
	}
	return 0;
}