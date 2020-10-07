#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>


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
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<vector<int> > res(2,vector<int>(n));
        res[0][n-1]=a[n-1];
        res[1][n-1]=a[n-1];
        res[1][n-2]=max(a[n-1],a[n-2]);
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(!(i==n-2&&j==1))
                {
                    if(j==0)
                    {
                        res[j][i]=max(a[i]+res[1][i+1],res[0][i+1]);
                    }
                    else
                        res[j][i]=max(a[i]+res[0][i+2],res[0][i+1]);
                }

            }
        }
        cout<<res[0][0]<<endl;
    }
}