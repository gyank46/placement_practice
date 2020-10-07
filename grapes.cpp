#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z,a,b,c;
    cin>>x>>y>>z;
    cin>>a>>b>>c;
    if(a-x+b-y>=0&&a-x>=0&&a-x+b-y+c-z>=0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
