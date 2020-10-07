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
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> d(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>d[i];
        int maxd=-1;
        for(int i=0;i<n;i++)
        {
            if(i==0&&a[n-1]+a[1]<d[0])
            {
                // cout<<a[n-1]+a[1]<<" "<<d[i]<<endl;
                maxd=max(maxd,d[i]);
            }
            else if(i==n-1&&a[n-2]+a[0]<d[n-1])
            {
                // cout<<a[n-2]+a[0]<<" "<<d[n-1]<<endl;
                maxd=max(maxd,d[i]);
            }
            else if(i>0&&i<n-1&&a[i-1]+a[i+1]<d[i])
            {
                // cout<<a[i-1]+a[i+1]<<" "<<d[i]<<endl;
                maxd=max(maxd,d[i]);
            }
        }
        cout<<maxd<<endl;
    }
}
