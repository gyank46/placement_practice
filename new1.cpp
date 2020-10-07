#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int conv(string s,int b)
{
    int i=s.length()-1;
    long long int sum=0;
    while(i>=0)
    {
        sum+=(s[i]-48)*pow(b,s.length()-1-i);
        i--;
    }
    return sum;

}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string s;
    cin>>s;
    int k,b,m;
    cin>>k>>b>>m;
    vector<string> v;
    for(int i=0;i<=s.length()-k;i++)
    {
        v.push_back(s.substr(i,k));
    }
    vector<int> a(v.size());
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        a[i]=conv(v[i],b);
        sum+=a[i]%m;
    }
    cout<<sum<<endl;
    return 0;
}
