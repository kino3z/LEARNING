#include<cstdio>
#include<vector>
using namespace std;
/*
����Ŀ���⡿
�� M ����Ȧ��ÿ����Ȧ���ʼʱ������ͷ��һ��ʼ������Ȧ���ǹرյġ���
������ N ���˿ͣ�ÿ���˿ͷֱ���ָ���ļ�����Ȧ������������ͷ��ÿ
���˿ͷֱ������ܹ�������������ޡ�ÿ���˿��ߺ����򿪵���Щ��Ȧ�е�
�������Ա�����ص������������ŵ���Ȧ�Ȼ��������Ȧ���¹��ϡ����ܹ�
�������������ͷ����1 <= N <= 100, 1 <= M <= 1000��
�ٸ�������˵���� 3 ����Ȧ����ʼʱ�ֱ��� 3��1 �� 10 ͷ���������� 3 ���˿ͣ�
��һ���� 1 �ź� 2 ����Ȧ������� 2 ͷ���ڶ����� 1 �ź� 3 ����Ȧ�������
3 ͷ���������� 2 ����Ȧ������� 6 ͷ����ô����õĿ�����֮һ���ǵ�һ��
�˿ʹ� 1 ��Ȧ�� 2 ͷ��Ȼ��� 1 ��Ȧʣ�µ� 1 ͷ�ŵ� 2 ��Ȧ���ڶ����˿ʹ� 3
��Ȧ�� 3 ͷ���������˿ʹ� 2 ��Ȧ�� 2 ͷ���ܹ����� 2+3+2=7 ͷ��
*/
int n,m;
int c(int times,int pigname){
	return times*1000+pigname;//1000>=pigname>=1
}
struct edge{
	int from,to,flow,cap,cost;
	edge(int from_,int to_,int flow_,int cap_){
		from=from_;to=to_;flow=flow_;cap=cap_;
	}
	edge(int from_,int to_,int flow_,int cap_,int cost_){
		from=from_;to=to_;flow=flow_;cap=cap_;cost=cost_;
	}
};
vector<edge> e;

void addedge


int zhu[1005];//��Ȧ 
struct custom{
	int a;//Ҫ�򼸸���Ȧ
	vector<int> v;
	int buy;//Ҫ��ֻ�� 
}cu[105];







int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d",&zhu[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&cu[i].a);
		for(int c,i=1;i<=cu[i].a;i++){
			scanf("%d",&c);
			cu[i].v.push_back(c);
		}
		scanf("%d",&cu[i].buy);
	}
	
	
	
	return 0;
}
