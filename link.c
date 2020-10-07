#include<stdio.h>
#include<stdlib.h>

struct node
{
	int v;
	struct node *next;
};

struct node *root;
struct node *front;

void push(int a,int b,int c,int d)
{	
	root=(struct node*)malloc(sizeof(struct node));
	root->next=NULL;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->v=a;
	temp->next=NULL;
	front=temp;
	root->next=temp;
	struct node *temp1;
	temp1=(struct node*)malloc(sizeof(struct node));
	temp1->v=b;
	temp1->next=NULL;
	temp->next=temp1;
	front=temp1;
	struct node *temp2;
	temp2=(struct node*)malloc(sizeof(struct node));
	temp2->next=NULL;
	temp2->v=c;
	temp1->next=temp2;
	front=temp2;
	struct node *temp3;
	temp3=(struct node*)malloc(sizeof(struct node));
	temp3->v=d;
	temp3->next=NULL;
	front =temp3;
	temp2->next=temp3;
}

struct node* pop()
{	
	struct node *temp;
	temp=root;
	while(temp->next!=front)
		temp=temp->next;
	temp->next=NULL;
	front=temp;
	return front;
}

int isempty()
{
	if(front==root)
		return 1;
	else
		return 0;
}


int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	push(a,b,c,d);
	{	
		printf("%d\n",pop()->v);
		printf("%d\n",pop()->v);
		printf("%d\n",pop()->v);
		printf("%d\n",pop()->v);
	}
	if(isempty())
	{
		printf("true\n");
	}
	else
		printf("false\n");
	return 0;
}