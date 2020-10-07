#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int n;
	int w;
	struct node *next;
};
node* add(node *temp,int ve,int we)
{
	struct node *new1=(node*)malloc(sizeof(node));
	new1->n=ve;
	new1->w=we;
	new1->next=temp;
	return new1;

}

int main()
{
	int v,e;
	cin>>v>>e;
	struct node *vertex[v+1];
	int i=1;
	while(i<=e)
	{
		int v1,v2,weight;
		cin>>v1>>v2>>weight;
		vertex[v1]=add(vertex[v1],v2,weight);
		vertex[v2]=add(vertex[v2],v1,weight);
		i++;
	}
	for(int i=1;i<=v;i++)
	{
		struct node *new1=vertex[i];
		while(new1!=NULL)
		{
			cout<<new1->n<<" "<<new1->w<<" ";
			new1=new1->next;
		}
		cout<<" NULL"<<endl;
	}

return 0;
}