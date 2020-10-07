#include<iostream>
#include<algorithm>


using namespace std;

long long mini(long long a,long long b)
{
	if(a<b)
		return a;
	return b;
}

long long coinChange(int amount)
{
	if(amount<3)
		return -1;
	if(amount==3||amount==5||amount==10)
		return 1;
	long long a[amount+1];
	for(int i=0;i<=amount;i++)
	{
		a[i]=INT_MAX;
		//cout<<a[i]<<endl;
	}

	long long b[]={3,5,10};
	a[0]=0;
	a[3]=1;
	a[5]=1;
	a[10]=1;
	for(int i=1;i<=amount;i++)
	{
		long long temp=a[i];
		for(int j=0;j<3;j++)
		{
			if(i-b[j]>0)
			{
				temp=mini(a[i],a[i-b[j]]+1);
			}
		}

		a[i]=temp;
		cout<<a[i]<<endl;
	}
	if(a[amount]>=INT_MAX)
		return -1;
	return a[amount];

} 

int main()
{
	int n;
	cin>>n;
	cout<<coinChange(n)<<endl;
}