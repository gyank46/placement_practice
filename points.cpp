#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include <limits.h>
#include<queue>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        // cout<<l1<<r1<<l2<<r2<<endl;
        if(l1<l2&&r1==l2)
            cout<<l1<<" "<<l2<<endl;
        if(l1<l2&&r1<r2)
            cout<<l1<<" "<<l2<<endl;
        if(l1<l2&&r1>r2)
            cout<<l1<<" "<<l2<<endl;
        if(l1>l2&&r2==l1)
            cout<<l1<<" "<<l2<<endl;
        if(l1>l2&&r2>r1)
            cout<<l1<<" "<<l2<<endl;
        if(l1>l2&&r2<r1)
            cout<<l1<<" "<<l2<<endl;
        if(l1==l2&&r1==r2)
            cout<<l1<<" "<<r1<<endl;
        if(l1==l2&&r1>r2)
            cout<<l1<<" "<<r2<<endl;
        if(l1==l2&&r2>r1)
            cout<<l1<<" "<<r2<<endl;
    }

}
