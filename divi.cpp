#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include <limits.h>
#include<queue>

using namespace std;

unsigned long long int lcd(unsigned long long int a,unsigned long long int b,unsigned long long int n)
{
    unsigned long long int count=0;
    unsigned long long int t=max(a,b);
    while(t<n)
    {
        if(t%a==0&&t%b==0)
            count++;
        t+=t;
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n,k,a,b;
        cin>>n>>a>>b>>k;
        unsigned long long int lcm=lcd(a,b,n);
        if(n-lcm>=k)
            cout<<"Win"<<endl;
        else
            cout<<"Lose"<<endl;
    }
}
