#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>


using namespace std;

bool subs(vector<int> a,int sum)
{
	vector<vector<int> >res(sum+1,vector<int>(a.size()));
	for(int i=0;i<a.size();i++)
		res[0][i]=1;
	//cout<<1<<endl;
	for(int i=a.size()-1;i>=0;i--)
	{
		for(int j=1;j<=sum;j++)
		{
			int x=j-a[i]>=0?res[i][j-a[i]]:0;
			int y=i+1<a.size()?res[i+1][j]:0;
			res[i][j]=x||y;
		}
	}
	return res[0][sum];
}

int sol(vector<int> a,int sum,int index)
{
	if(sum==0)
		return 1;
	if(sum<0)
		return 0;
	if(sum>0&&index>=a.size())
		return 0;
	return sol(a,sum-a[index],index)+sol(a,sum,index+1);
}

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
		int sum;
		cin>>sum;
		cout<<sol(a,sum,0)<<endl;

	}
}