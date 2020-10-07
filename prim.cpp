#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include <limits.h>
#include<queue>

using namespace std;

struct node
{
	int v;
	int w;
	struct node *next;
};

node* add1(struct node *a,int x,int y)
{
	struct node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->v=x;
	temp->w=y;
	temp->next=a;
	return temp;
}

/*int minpos(int distance[],int visited[],int v,int start)
{
	int i,index=-1;
	int min=INT_MAX;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0&&distance[i]<min)
		{
			min=distance[i];
			index=i;
		}
	}
	return index;
}*/

/*void sp(struct node *a[],int v,int start,int level[])
{
	int visited[v+1];
	int distance[v+1];
	int parent[v+1];
	for(int i=1;i<=v;i++)
	{
		distance[i]=INT_MAX;
		visited[i]=0;
		parent[i]=0;
	}
	distance[start]=0;
	for(int i=1;i<=v;i++)
	{
		struct node *temp;
		int t=minpos(distance,visited,v,start);
		temp=a[t];
		while(temp!=NULL)
		{
			parent[temp->v]=t;
			if(distance[temp->v]>distance[t]+temp->w)
			{
				distance[temp->v]=distance[t]+temp->w;
			}
			temp=temp->next;
		}
		visited[t]=1;
	}
	for(int i=1;i<=v;i++)
	{
		if(distance[i]==INT_MAX)
			cout<<"-1"<<" ";
		else if(i==start)
			continue;
		else
			cout<<distance[i]<<" ";
	}
}
*/

/*void bfs(struct node *x[],int level[],int start)
{
    level[start]=0;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        struct node *temp;
        temp=x[q.front()];
        while(temp!=NULL)
        {   
            if(level[temp->v]==-1)
            {
                level[temp->v]=level[q.front()]+1;
                q.push(temp->v);
            }
            temp=temp->next;
        }
        q.pop();
    }
}*/


void prim(struct node *a[],int start,int v)
{
	int distance[v+1][v+1];
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
			distance[i][j]=INT_MAX;
	}
	for(int i=1;i<=v;i++)
	{	
		distance[i][i]=0;
		struct node *temp;
		temp=a[i];
		while(temp!=NULL)
		{
			distance[i][temp->v]=temp->w;
			temp=temp->next;
		}		
	}
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
			cout<<distance[i][j]<<" ";
		cout<<endl;
	}
	
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int v,e;
		cin>>v>>e;
		struct node *a[v+1];
		for(int i=1;i<=v;i++)
			a[i]=NULL;
		for(int i=1;i<=e;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[x]=add1(a[x],y,z);
			a[y]=add1(a[y],x,z);
		}
		//int level[v+1];
		//for(int i=0;i<=v;i++)
		//	level[i]=-1;
		int s;
		cin>>s;
		//bfs(a,level,s);
		//sp(a,v,s,level);
		prim(a,s,v);
		cout<<endl;
	}
}
	
