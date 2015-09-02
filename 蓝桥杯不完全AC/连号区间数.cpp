#include <iostream>
using namespace std;
int mCount=0;
int mmax,mmin;
int a[50000+5];
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++)
	{
		mmax=a[i];
		mmin=a[i];	
		for (int j=0;i+j<n;j++)
		{
			mmax=a[i+j]>mmax?a[i+j]:mmax;
			mmin=a[i+j]<mmin?a[i+j]:mmin;
			if (mmax-mmin==j) mCount++;
		}
	}
	cout<<mCount;
	return 0;
}