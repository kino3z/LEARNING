/*
�����е��
ֱ�ӿ��ռ俪����
���һ����ո�
MLE

���ԣ�
��400W��int����ָ���MLE�������������400W��char����MLE��
���Կ��Դ��������ַ���Ȼ��ѹ��·����Trie TAT��
ʲô��ѹ��·������һ��Ҷ�ڵ㴢�����ַ�

��yanba @ 2015-03-10 21:57:53 [ Quote ] [ Edit ] [ Delete ] 3#
hash���ˡ���
hash�ڿƼ����������� 

������һhash��WA������
���£�����hash 
hashֵ���ܱ�mod�� 
��WA 
�ð�����Ҫ�ϸ���ʷ����� 
һ��������10^7��hashֵ
��������һ��Ҫ����10^7 
���ݸ�����ʵ���ϴ���sqrt��n���ͻ����ظ� 
�������ڿռ����ⲻ�ܿ�˫hash 
��Ͷ�� 
*/
#include<cstdio>
#define LL unsigned int
using namespace std;
const LL P=3001,mod=25000007;
LL hash[25000009];
char word[20005];
int read(char *w){
    int p=0;char c=getchar();
    while(c=='\n'||c=='\r') c=getchar();
    while(c!='\n'&&c!='\r') w[p++]=c,c=getchar();
    return p;
}
int n;
LL maxn=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int m=read(word);
        for(int i=0,ha=1;i<m;i++){
            ha=ha*P+word[i];
            ha%=mod;
            hash[ha]+=i+1;
            maxn=maxn<hash[ha]? hash[ha]:maxn;
        }
    }
    printf("%d",maxn);
    return 0;
} 
