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
        int ans=0;
        vector<int> a(26,0);
        for(int l=0;l<n;l++)
        {
            vector<char> b(26,'0');
            string temp;
            cin>>temp;
            for(int i=0;i<temp.size();i++)
            {
                if(b[temp[i]-'a']=='0')
                    b[temp[i]-'a']='1';
            }
            for(int i=0;i<26;i++)
            {
                if(b[i]=='1')
                    a[i]++;
            }
        }
        for(int i=0;i<26;i++)
        {
            // cout<<a[i]<<" ";
            if(a[i]==n)
                ans++;
        }
        cout<<ans<<endl;

    }
}
