#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool myfunction(int i,int j)
{
    if(i>j)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,myfunction);
    vector<int>v;
    for(int i=0;i<n-k+1;i++)
    {   
        v.push_back(a[i]-a[i+k-1]);
    }
    int min=v[0];
    for(int i=0;i<v.size();i++)
    {   
        //cout<<v[i]<<" "<<endl;
        if(v[i]<min)
            min=v[i];
    }
    cout<<min<<endl;
}