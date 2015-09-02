#include <iostream>
using namespace std;
int main()
{
	char a[1005];
	char b[1005];
	cin>>a;
	cin>>b;
	int i=0;
	int mCount=0;
	while (b[i]!=0)
	{
		if (b[i]!=a[i])
		{
			mCount++;
			if (a[i+1]=='*') a[i+1]='o';
			else a[i+1]='*';
		}
		i++;
	}
	cout<<mCount;
	return 0;
}