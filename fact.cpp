#include<iostream>
#include<algorithm>
#include<string>
#include<vector>


using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int max=INT_MIN,sum=0;
		for(int i=0;i<n;i++)
		{
			sum=a[i];
			for(int j=i+1;j<n;j++)
			{
				sum+=a[j];
				if(sum>max)
					max=sum;
			}
		}
		cout<<max<<endl;
	}

	
}