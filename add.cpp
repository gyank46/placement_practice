#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include <limits.h>
#include<queue>

using namespace std;

struct Node
{
    int data;
   Node* next;
}; 

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
Node*  addTwoLists(Node* first, Node* second)
{
  // Code here
    struct Node *temp=first;
    struct Node *temp1=second;
    string a="";
    string b="";
    while(temp!=NULL)
    {
        a+=((temp->data)+48);
        temp=temp->next;
    }
    while(temp1!=NULL)
    {
        b+=((temp1->data)+48);
        temp1=temp1->next;
    }
    string b1="";
    string a1="";
    int i;
    for(i=a.length()-1;i>=0;i--)
        a1+=a[i];
    for(i=b.length()-1;i>=0;i--)
        b1+=b[i];
    int a2=stoi(a1);
    int b2=stoi(b1);
    int c1=a2+b2;
    string c=to_string(c1);
    i=0;
    struct Node *head;
    head=NULL;
    while(i<c.length())
    {
        struct Node *temp2;
        temp2=(Node*)malloc(sizeof(Node));
        temp2->data=(c[i]-48);
        temp2->next=head;
        head=temp2;
        i++;
    }
    return head;
}

int main()
{   
    int t;
    cin>>t;
    while(t--)
    {    
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int m;
        cin>>m;
        int b[m];
        for(int i=0;i<m;i++)
            cin>>b[i];
        struct Node *head;
        head=NULL;
        int i=0;
        while(i<n)
        {
            struct Node *temp;
            temp=(Node*)malloc(sizeof(Node));
            temp->data=a[i];
            temp->next=head;
            head=temp;
            i++;
        }
        struct Node *head1;
        head1=NULL;
        i=0;
        while(i<m)
        {
            struct Node *temp;
            temp=(Node*)malloc(sizeof(Node));
            temp->data=b[i];
            temp->next=head1;
            head1=temp;
            i++;
        }
        struct Node *final;
        final=addTwoLists(head,head1);
        struct Node *temp;
        temp=final;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}