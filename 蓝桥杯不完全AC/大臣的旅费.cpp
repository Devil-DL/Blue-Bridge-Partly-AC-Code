#include <iostream>
#include <fstream>
using namespace std;
int n;
bool visit[10000+5];
struct Node
{
	int id;
	int value;
	Node* next;
	Node(int i=0,int v=0)
	{
		id=i;
		value=v;
		next=NULL;
	}
	
};
Node *root=NULL;
void AddBian(int a,int b,int c)
{
	Node *p=new Node(b,c);
	p->next=root[a].next;
	root[a].next=p;
}
void Destory(int m)
{
	Node *temp;
	while (root[m].next!=NULL)
	{
		temp=root[m].next;
		root[m].next=temp->next;
		delete temp;
	}
}
int maxDis=-1;
int currentDis=0;
int maxDot=-1;

void DFS(int x)
{
	Node *p=root[x].next;
	while (p!=NULL)
	{
		if (visit[p->id]==true) {p=p->next;continue;}
		visit[p->id]=true;
		currentDis+= (p->value);
		if (maxDis<0||currentDis>maxDis) 
		{
			maxDis=currentDis;
			maxDot=p->id;
		}
		DFS(p->id);
		visit[p->id]=false;
		currentDis-= (p->value);
		p=p->next;
	}
}
void Clr()
{
	for (int i=0;i<n;i++) Destory(i);
	delete []root;
}
int main()
{
	int a,b,c;
	cin>>n;
	root=new Node[n];
	for (int i=0;i<n;i++) visit[i]=false;
	for (int i=0;i<n-1;i++)
	{
		cin>>a>>b>>c;
		AddBian(a-1,b-1,c);
		AddBian(b-1,a-1,c);	
	}
	visit[0]=true;
	DFS(0);
	maxDis=-1;
	currentDis=0;
	visit[0]=false;
	visit[maxDot]=true;
	DFS(maxDot);
	cout<<maxDis*(maxDis+1)/2+10*maxDis;
	Clr();
	return 0;
}