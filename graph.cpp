#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include <stdlib.h>
#include <queue>
 
using namespace std;

struct node
{
    int v;
    struct node *next;
};
node* add(struct node *x,int y)
{
    struct node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->v=y;
    temp->next=x;
    return temp;
}
void bfs(struct node *x[],int level[],int parent[],int start)
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
                parent[temp->v]=q.front();
                q.push(temp->v);
            }
            temp=temp->next;
        }
        q.pop();
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    int level[v+1];
    int parent[v+1];
    for(int i=0;i<=v;i++)
    {
        level[i]=-1;
        parent[i]=0;
    }
    struct node *g[v+1];
    for(int i=0;i<v+1;i++)
        g[i]=NULL;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a]=add(g[a],b);
    }
    for(int i=1;i<v+1;i++)
    {
        struct node *temp;
        temp=g[i];
        while(temp!=NULL)
        {
            cout<<i<<"->"<<temp->v<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    bfs(g,level,parent,1);
    for(int i=1;i<=v;i++)
    {
        cout<<i<<" "<<parent[i]<<" "<<level[i]<<endl;
    }
    
}