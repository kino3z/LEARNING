#include<iostream>  
/*codevs2549
����һ����ȫ����
ʡѡҪ�������� 
*/ 
using namespace std;  
int f[5000];  
int main()  
{  
    int n;  
    f[0]=1;  
    cin>>n;  
    for(int i=1;i<=n;i++)  
        for(int j=i;j<=n;j++)  
        {  
            f[j]+=f[j-i];  
        }  
    cout<<f[n];  
    return 0;  
}  
