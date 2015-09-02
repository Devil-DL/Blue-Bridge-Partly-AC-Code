#include <iostream>
#include <iomanip>  
using namespace std;
double result[100+5][10000];
int n,a,b,x;
int bre;
void Clear()
{
	for (int i=0;i<=n;i++)
	{
		for (int j=a;j<=x;j++) result[i][j]=-1;
	}
}
double Fun(int nn,int xx)
{
	if (result[nn][xx]>=0) return result[nn][xx];
	if (nn==1)
	{
		double temp=0;
		if (xx>=a&&xx<=b) temp=1.0/(b-a+1);
		result[nn][xx]=temp;
		return temp;
	}
	double ans=0;
	for (int i=a;i<=b;i++)
	{
		ans=ans+Fun(1,i)*Fun(nn-1,xx-i);
	}
	result[nn][xx]=ans;
	return ans;
	
}
int main()
{
	cin>>n>>a>>b>>x;
	Clear();
	cout<<fixed<<setprecision(4)<<Fun(n,x);
	return 0;
}