#include <iostream>
using namespace std;
int a[4*30+6][4*30+6];
void fun1(int n,int x,int y)
{
	if (n==0) 
	{
		a[x][y]=1;
		return;
	}
	for (int i=0;i<4*n+1;i++) a[x][y+i]=1;
	fun1(n-1,x+2,y+2);
}
void fun2(int n,int x,int y)
{
	if (n<0) return;
	for (int i=0;i<3;i++) 
	{
		a[x+i][y]=1;
		a[x+i][y+4*n]=1;
	}
	fun2(n-1,x+2,y+2);
}
void fun3(int n,int x,int y)
{
	if (n<0) return;
	for (int i=0;i<3;i++)
	{
		a[x][y+i]=1;
		a[x][y+4*n+2+i]=1;
	}
	for (int i=0;i<2*n+1;i++)
	{
		a[x+i][y]=1;
		a[x+i][y+4*n+4]=1;
	}
	fun3(n-1,x+2,y+2);
}
int main()
{	
	for (int i=0;i<4*30+6;i++)
		for (int j=0;j<4*30+6;j++) a[i][j]=0;
	int n;
	cin>>n;
	fun1(n,0,2);
	fun2(n,0,2);
	fun3(n,2,0);
	for (int i=0;i<2*n+2;i++)
	{
		for (int j=0;j<4*n+5;j++)
		{
			a[2*n+3+i][j]=a[2*n+3+i-2*(i+1)][j];
		}
	}
	for (int i=0;i<4*n+5;i++)
	{
		for (int j=0;j<4*n+5;j++) 
		{
			if (a[i][j]==1) cout<<'$';
			else cout<<'.';
		}
		cout<<endl;
	}
	return 0;
	
}