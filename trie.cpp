#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<stdlib.h>

using namespace std;


struct node
{
	struct node *children[26];
	string n;
};
void insert(node *root,string y,string p)
{
	struct node *temp;
	temp=root;
	int i=0;
	while(y[i]!='\0')
	{
		if(temp->children[y[i]-'a']==NULL)
		{
			struct node *new1;
			new1=(node*)malloc(sizeof(node));
			temp->children[y[i]-'a']=new1;
		}
		temp=temp->children[y[i]-'a'];
		i++;
	}
	temp->n.append(p);
}
bool search(node *root,string y)
{
	struct node *temp;
	temp=root;
	int i=0;
	while(y[i]!='\0'&&temp->children[y[i]-'a']!=NULL)
	{
		temp=temp->children[y[i]-'a'];
		i++;
	}
	if(y[i]=='\0')
	{
		if(temp->n.length()>0)
			{
				cout<<"passwrd is: "<<temp->n<<endl;
				return true;
			}
		else
		{
			cout<<"not listed"<<endl;
			return false;
		}
	}
	else
	{
		cout<<"not listed"<<endl;
		return false;
	}		
	
}
void remove(node *root,string y)
{	
	if(search(root,y))
	{
		struct node *temp;
		temp=root;
		int i=0;
		while(y[i]!='\0'&&temp->children[y[i]-'a']!=NULL)
		{
			temp=temp->children[y[i]-'a'];
			i++;
		}
		if(y[i]=='\0')
		{
			temp->n="";
		}
	}
	else
		cout<<"Not listed"<<endl;
}

using namespace std;
int main()
{
	struct node *root;
	root=(node*)malloc(sizeof(node));
	insert(root,"gyan","12345");
	insert(root,"gyan1","abcd");
	insert(root,"hannah","13");
	//search(root,"gy");
	remove(root,"gyan");
	search(root,"gyan");
	search(root,"gyan1");
	search(root,"gyan");
	return 0;
}