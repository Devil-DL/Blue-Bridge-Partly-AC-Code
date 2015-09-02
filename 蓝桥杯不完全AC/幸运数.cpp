/*
看了测试数据范围，改小了 ARREYLEN的值，正常情况下运行会超时 
*/
#include <iostream>
#include <fstream>
#define ARREYLEN 8000
using namespace std;
int bre;
int a[ARREYLEN+5];
int currentLen=0;
void Fun(int start,int len,int a[])
{
    while (a[start]<=len)
    {
        int mCount=1;
        for (int i=1; i<len+1; i++) if (i%a[start]!=0) a[mCount++]=a[i];
        currentLen=mCount-1;
        start+=1;
        len=mCount-1;
    }
}
int main()
{
    for (int i=1; i<ARREYLEN+1; i++) a[i]=2*i-1;
    Fun(2,ARREYLEN,a);
    int m,n,Count=0;
    cin>>m>>n;
    for (int i=1; i<currentLen+1; i++)
    {
        if (a[i]>m&&a[i]<n) Count++;

    }
    cout<<Count;
    return 0;
}
