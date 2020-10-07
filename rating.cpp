#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<stdlib.h>

using namespace std;

int main()
{
    int n,r;
    cin>>n>>r;
    while(n--)
    {
        int t;
        cin>>t;
        if(t>=r)
            cout<<"Good boi"<<endl;
        else
            cout<<"Bad boi"<<endl;
    }
}
