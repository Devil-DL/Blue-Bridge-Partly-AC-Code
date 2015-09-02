#include <iostream>
#include <string>
#include <fstream>
#define maxSize 100000
using namespace std;
char c[maxSize];
int main()
{
	int m,n;
	int rubbish;
	cin>>rubbish;
	cin.getline(c,maxSize-1,0);
	int mCount=0;
	int a=0;
	int temp;
	int num[maxSize];
	for (int i=0;i<maxSize;i++)
	{
		if (c[i]>='0'&&c[i]<='9') 
		{
			a=a*10+c[i]-'0';
			if (i+1<maxSize&&(c[i+1]<'0'||c[i+1]>'9'))
			{
				num[mCount]=a;
				a=0;
				mCount++;
			}
		}	
	}
	for (int i=0;i<mCount-1;i++)
	{
		for (int j=0;j<=mCount-2-i;j++)
		{
			if (num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;	
			}
		}
	}
	for (int i=0;i<mCount-1;i++)
	{
		if (num[i]==num[i+1]) n=num[i];
		else if (num[i]+1!=num[i+1]) m=num[i]+1;
	}
	cout<<m<<' '<<n;
	return 0;
}