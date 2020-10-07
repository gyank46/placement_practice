#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int util(vector<int>A,int l,int n)
{
	
	//cout<<
	if (n == 0)
        return 1;
     
    // If n is less than 0 then no 
    // solution exists
    if (n < 0)
        return 0;
 
    // If there are no coins and n 
    // is greater than 0, then no
    // solution exist
    if (l<=0 && n >= 1)
        return 0;
	return max(A[l-1]*util( A, l - 1, n ),A[l-1]*util( A, l, n-A[l-1] ));

}


int main()
{
	int n;
	cin>>n;
	vector<int> a(n-1);
	for(int i=0;i<n-1;i++)
	{
		a[i]=i+1;
		//cout<<a[i]<<endl;
	}
	cout<<util(a,n-1,n)<<endl;
}