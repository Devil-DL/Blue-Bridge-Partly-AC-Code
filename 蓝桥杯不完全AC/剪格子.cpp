#include <iostream>
using namespace std;
int bre;
int flag[11][11];
int a[11][11];
int sum=0;
int minNum=-1;
int result=0;
int m, n;
int mCount=0;
void Search(int x,int y)
{
	
	
	if (result>sum/2.0) return;
	if (result==sum/2.0)
	{
		if (minNum<0||mCount<minNum) minNum=mCount;
	}
	if (y+1<m&&flag[x][y+1]==0)
	{
		result+=a[x][y+1];
		flag[x][y+1]=1;
		mCount++;
		Search(x,y+1);
		result-=a[x][y+1];
		flag[x][y+1]=0;
		mCount--;
		
	}
	if (x+1<n&&flag[x+1][y]==0)
	{
		result+=a[x+1][y];
		flag[x+1][y]=1;
		mCount++;
		Search(x+1,y);
		result-=a[x+1][y];
		flag[x+1][y]=0;
		mCount--;
	}
	if (y-1>=0&&flag[x][y-1]==0)
	{
		result+=a[x][y-1];
		flag[x][y-1]=1;
		mCount++;
		Search(x,y-1);
		result-=a[x][y-1];
		flag[x][y-1]=0;
		mCount--;
	}
	if (x-1>=0&&flag[x-1][y]==0)
	{
		result+=a[x-1][y];
		flag[x-1][y]=1;
		mCount++;
		Search(x-1,y);
		result-=a[x-1][y];
		flag[x-1][y]=0;
		mCount--;
	}
}
int main()
{
	cin>>m>>n;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin>>a[i][j];
			flag[i][j]=0;
			sum+=a[i][j];
		}
	}
	flag[0][0]=1;
	result+=a[0][0];
	mCount++;
	Search(0,0);
	cout<<minNum;
	return 0;
}