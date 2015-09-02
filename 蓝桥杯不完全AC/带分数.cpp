#include <iostream>
#define maxDef 11
int bre;
using namespace std;
int inPut=0;
int flag[maxDef];
int num[maxDef];
int mCount=0;
int aCount=0,bCount=0,cCount=0;
void fun(int n)
{
	if (n==maxDef) 
	{
		if (cCount==0) return;
		if (bCount%cCount==0)
		{
			if (aCount+bCount/cCount==inPut) mCount++;
		}
		return;
	}
	for (int i=0;i<maxDef;i++)
	{
		if (flag[i]==1) continue;
		if (aCount>inPut) break;
		if (flag[10]==1&&(inPut-aCount>bCount)) break;
		if (i==10&flag[9]==0) continue;
		flag[i]=1;
		if (flag[9]==0&&i!=9&&i!=10) aCount=10*aCount+i+1;
		if (flag[9]==1&&flag[10]==0&&i!=9&&i!=10) bCount=bCount*10+i+1;
		if (flag[10]==1&&i!=9&&i!=10) cCount=cCount*10+i+1;
		fun(n+1);
		flag[i]=0;
		if (flag[9]==0&&i!=9&&i!=10) aCount=(aCount-i-1)/10;
		if (flag[9]==1&&flag[10]==0&&i!=9&&i!=10) bCount=(bCount-i-1)/10;
		if (flag[10]==1&&i!=9&&i!=10) cCount=(cCount-i-1)/10;
	}
}
int main()
{
	for (int i=0;i<maxDef;i++) flag[i]=0;//clear
	cin>>inPut;
	fun(0);
	cout<<mCount;
	return 0;
}