#include<iostream>
#include<algorithm>


using namespace std;

long long mini(long long a,long long b,long long c)
{
	if(a<=b&&a<=c)
		return a;
	if(c<=b&&c<=a)
		return c;
	if(b<=a&&b<=c)
		return b;

}

long long util(int n)
    {
        if(n==0)
            return 0;
        if(n<0)
            return INT_MAX;
        else
        {
            return mini(util(n-3),util(n-5),util(n-10))+1;
        }
    }
int coinChange(int amount) 
{
    long long res=util(amount);
    if(res>=INT_MAX)
      	return -1;
    return res;
}


int main()
{
	int n;
	cin>>n;
	cout<<coinChange(n)<<endl;
}