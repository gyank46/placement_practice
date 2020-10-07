#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
	int v;
	struct node *next;
};

node* add(struct node *a,int x)
{
	struct node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->v=x;
	temp->next=a;
	return temp;
}
/*void replace(struct node * head, int num, int replacedNum)
{
    struct node * p = head;

    while (p->next != NULL) {
        if (p->val == num) {
            break;
        }

        p = p->next;
    }

    p->val = replacedNum;
}*/

void bfs(struct node *x[],int level[],int start)
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
}
	
	
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        struct node *a[v+1];
        for(int i=0;i<=v;i++)
            a[i]=NULL;
        for(int i=1;i<=e;i++)
        {
            int x,y;
            cin>>x>>y;
            struct node *temp;
            temp=a[x];
            a[x]=add(a[x],y);
            a[y]=add(a[y],x);
        }
        int level[v+1];
        for(int i=0;i<v+1;i++)
        {
            level[i]=-1;
        }
        int s;
        cin>>s;
        bfs(a,level,s);
        for(int i=1;i<=v;i++)
        {
            if(i==s)
                continue;
            if(level[i]>0)
                cout<<level[i]*6<<" ";
            else
                cout<<level[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
