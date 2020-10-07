#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct node
{
    struct node *c[10];
    int count=0;
};

bool add(node *root,string x)
{
    struct node *temp;
    temp=root;
    int i=0;
    while(x[i]!='\0')
    {   
        if(temp->c[x[i]-'a']==NULL)
        {
            struct node *n;
            n=(node*)malloc(sizeof(node));
            temp->c[x[i]-'a']=n;
        }
        
        temp=temp->c[x[i]-'a'];
        if(temp->count==1)
        {
            cout<<"BAD SET"<<endl<<x<<endl;
            return true;
        }
        i++;
    }
    temp->count++;
    return false;
    
    
    
}


int main() 
{   
    struct node *root;
    root=(node*)malloc(sizeof(node));
    int t;
    cin>>t;
    vector<string> s;
    while(t--)
    {
        string x;
        cin>>x;
        s.push_back(x);
    }
    unsigned int i;
    for(i=0;i<s.size();i++)
    {
        if(add(root,s[i]))
            break;
    }
    if(i==s.size())
        cout<<"GOOD SET"<<endl;
    free(root);
    
    return 0;
}