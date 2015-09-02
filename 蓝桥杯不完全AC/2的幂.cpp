#include <iostream>
#include <cmath>
using namespace std;
int table[17];
int bre;
void dfs(int x)
{
	if (x==1)
	{
		return;
	}
	if (x==0) 
	{
		cout<<"0";
		return;
	}
	int temp;
	for (int k=15;k>=0;k--)
	{
		if (x/table[k]>=1)
		{
			cout<<"2";
			if (k!=1) cout<<"(";
			dfs(k);
			if (k!=1) cout<<")";
		}
		if (x-table[k]>0) cout<<'+';
		if (x-table[k]>=0) 
		{
			x=x-table[k];
		}
	}
}
int main()
{
//pow(2,15)=32768,所以最高只需要15位
	for (int i=0;i<16;i++) table[i]=pow(2,i);
	int n;
	cin>>n;
	dfs(n);
	return 0;
}