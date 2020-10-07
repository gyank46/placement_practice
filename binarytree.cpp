#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;
struct node
{   
    int data;
    node* left;
    node* right;
};

int height(node * root)
{
    struct node* temp;
    temp=(node*)malloc(sizeof(node));
    temp=root;
    int count=0;
    int max=0;
    if(temp->left==NULL&&temp->right==NULL)
            return 0;
    else
    {
        if(temp->left!=NULL)
        {
            count=height(temp->left);
            count++;
        }
        if(temp->right!=NULL)
        {
            max=height(temp->right);
            max++;
        }
        
    }
    if(count>max)
        return count;
    else
        return max;
      
} 

int lca(node * root, int v1,int v2)
{   
    struct node* temp;
    temp=(node*)malloc(sizeof(node));
    temp=root;
    vector<node*> myvector;
    int i,count=0,j;
    while(temp->data!=v1)
    {
        if(temp->data>v1)
        {
            myvector.push_back(temp);
            temp=temp->left;
        }
        else
        { 
            myvector.push_back(temp);
            temp=temp->right;    
        }
    }
    myvector.push_back(temp);
    vector<node*>myvector1;
    temp=root;
    while(temp->data!=v2)
    {
        if(temp->data>v2)
        {
            myvector1.push_back(temp);
            temp=temp->left;
        }
        else
        {   
            myvector1.push_back(temp);
            temp=temp->right;    
        }
    }
    myvector1.push_back(temp);
    for(i=myvector.size()-1;i>=0;i--)
    {
        for(j=myvector1.size()-1;j>=0;j--)
        {
            if(myvector[i]==myvector1[j])
            {
                count++;
                break;
            }
        }
        if(count==1)
            break;
    }
    return myvector[i]->data;  
}

void postOrder(node *root) 
{
    struct node* temp;
    temp=(node*)malloc(sizeof(node));
    temp=root;
    if(temp!=NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d ",temp->data);
        
    }
}

node * insert(node * root, int value)
{
    struct node *temp,*temp1;
    temp=(node*)malloc(sizeof(node));
    temp1=(node*)malloc(sizeof(node));
    temp=root;
    
    if(temp==NULL)
    {
        temp1->data=value;
        temp1->left=NULL;
        temp1->right=NULL;
        temp=temp1;
        return temp;
    }
    else if(value>temp->data)
    {
        temp->right=insert(temp->right,value);
        
    }
    else
        temp->left=insert(temp->left,value);
    return root;
}

void levelOrder(node * root) 
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        if(q.front()->left!=NULL)
        {
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL)
        {
            q.push(q.front()->right);
        }
        cout<<q.front()->data<<" ";
        q.pop();
    }
    cout<<endl;
  
  
}


int main()
{
    struct node* root;
    root=(node*)malloc(sizeof(node));
    root->left=NULL;
    root->right=NULL;
    root->data=4;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,6);
    root=insert(root,4);
    levelOrder(root);
    //printf("%d ",lca(root,1,3));
    //printf("%d\n",height(root));
}
