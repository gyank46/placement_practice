#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>


using namespace std;

int mini(int x,int y,int z)
{
	if(x<=y&&x<=z)
		return x;
	if(y<=x&&y<=z)
		return y;
	else
		return z;
}
int res(string a,int sa,string b,int sb)
{
	if(sa==a.length()&&sb==b.length())
		return 0;
	if(sa==a.length())
	{
		int sum=0;
		for(int i=sb;i<b.length();i++)
			sum+=b[i];
		return sum;
	}
	if(sb==b.length())
	{
		int sum=0;
		for(int i=sa;i<a.length();i++)
			sum+=a[i];
		return sum;
	}

	if(a[sa]==b[sb])
		return res(a,sa+1,b,sb+1);
	else
		return mini(a[sa]+res(a,sa+1,b,sb),b[sb]+res(a,sa,b,sb+1),a[sa]+b[sb]+res(a,sa+1,b,sb+1));


}
int res1(string a,string b)
{
	int n=a.length(),m=b.length();
	vector<vector<int> > res(n+1,vector<int>(m+1));
	res[n][m]=0;
	for(int i=m-1;i>=0;i--)
	{
		res[n][i]=res[n][i+1]+a[i];
		//cout<<b[i]<<" ";
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	//cout<<endl;
	for(int i=n-1;i>=0;i--)
	{
		res[i][m]=res[i+1][m]+b[i];
		//cout<<a[i]<<" ";
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(a[i]==b[j])
				res[i][j]=res[i+1][j+1];
			else
				res[i][j]=mini(a[i]+res[i][j+1],b[j]+res[i+1][j],a[i]+b[j]+res[i+1][j+1]);
		}
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	return res[0][0];
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<s1<<" "<<s2<<endl;
	cout<<res1(s1,s2)<<endl;
}