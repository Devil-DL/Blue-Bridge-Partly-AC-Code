#include <iostream>
#include <fstream>
using namespace std;
ifstream in("C:\\Users\\Administrator\\Desktop\\put.txt");
char map[100][10000];
int len[100];
struct Node
{
	int value;
	int id;
	Node *leftChild;
	Node *rightChild;
	Node(int v=0)
	{
		value=v;
		id=0;
		leftChild=NULL;
		rightChild=NULL;
	}
};
int floor=0;
int count1=0;//最后存了点的数量		 
Node *root=NULL;//树根
void Insert(int x,Node *subTree)
{
	if (x > subTree->value)
	{
		if (subTree->leftChild==NULL)
		{
			Node *p=new Node(x);
			subTree->leftChild=p;
		}
		else Insert(x,subTree->leftChild);
	}
	else
	{
		if (subTree->rightChild ==NULL)
		{
			Node *p=new Node(x);
			subTree->rightChild=p;
		}
		else Insert(x,subTree->rightChild);
	}
}

void Remove(Node *subTree)
{
	if (subTree==NULL) return;
	Remove (subTree->leftChild);
	Remove (subTree->rightChild);
	delete subTree;
}

void MidTravel(Node *subTree,void (*visit) (Node *subTree))
{
	if (subTree==NULL) return;
	floor+=1;
	MidTravel(subTree->leftChild,visit);
	floor-=1;
	visit(subTree);
	floor+=1;
	MidTravel(subTree->rightChild,visit);
	floor-=1;
}
void Fun1(Node*subTree)
{
	subTree->id=count1;
	count1++;
}

void Draw(Node *subTree,int flr)
{
	int temp=subTree->value;
	int count2=1;
	while (temp=temp/10) count2++;
	temp=subTree->value;
	int temp2=flr;
	while (count2!=0)
	{
		map[subTree->id][temp2+count2-1]=temp%10+'0';
		temp=temp/10;
		count2--;
		flr++;
	}
	if(subTree->leftChild||subTree->rightChild) 
	{
		map[subTree->id][flr]='-';
		len[subTree->id]=flr+1;
	}
	else len[subTree->id]=flr-1;
	if (subTree->leftChild!=NULL)
	{
		for (int i=subTree->id;i>=subTree->leftChild->id;i--) map[i][flr+1]='|';
		map[subTree->leftChild->id][flr+2]='-';
	}
	if (subTree->rightChild!=NULL)
	{
		for (int i=subTree->id;i<=subTree->rightChild->id;i++) map[i][flr+1]='|';
		map[subTree->rightChild->id][flr+2]='-';
	}
	if (subTree->leftChild) Draw(subTree->leftChild,flr+3);
	if (subTree->rightChild) Draw(subTree->rightChild,flr+3);
}

int main() 
{
	int temp;
	cin>>temp;
	root=new Node(temp);
	while (cin>>temp)
	{
		Insert(temp,root);	
	}
	MidTravel(root,Fun1);
	Draw(root,0);	
	for (int i=0;i<count1;i++)
	{
		for (int j=0;j<=len[i];j++)
		{
			if ((map[i][j]>='0'&&map[i][j]<='9')||map[i][j]=='-'||map[i][j]=='|') cout<<map[i][j];
			else cout<<'.';
		}
		cout<<endl;
	}
	Remove(root);
	in.close();
	return 0;
}