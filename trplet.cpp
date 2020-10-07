#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j,k,flag=0;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        a[i]=a[i]*a[i];
	    }
	    sort(a,a+n);
	    for(i=n-1;i>=2;i--)
	    {
	        j=0;
	        k=i-1;
	        while(j<k)
	        {
	            if(a[j]+a[k]==a[i])
	            {
	                flag++;
	                break;
	            }
	            if(a[j]+a[k]>a[i])
	                k--;
	            else if(a[j]+a[k]<a[i])
	                j++;
	        }
	        if(flag==1)
	            break;
	    }
	    if(flag>0)
	        cout<<"Yes"<<endl;
	    else
	        cout<<"No"<<endl;
	}
	return 0;
}