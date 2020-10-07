#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() 
{
	int n=1000;
	vector<vector<int> >res(n+1,vector<int>(n+1));
	    res[1][0]=2;
	    res[1][1]=1;
	    for(int i=2;i<=n;i++)
	        res[1][i]=0;
	    for(int i=2;i<=n;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            int x=j-1>=0?res[i-1][j-1]%(int)(pow(10,9)+7):res[i-1][j+1]%(int)(pow(10,9)+7);
	            int y=j+1<=n?res[i-1][j+1]%(int)(pow(10,9)+7):res[i-1][j-1]%(int)(pow(10,9)+7);
	            int z=res[i-1][j]%(int)(pow(10,9)+7);
	            res[i][j]=(((2*z)%(int)(pow(10,9)+7)+x)%(int)(pow(10,9)+7)+y)%(int)(pow(10,9)+7);
	            //cout<<res[i][j]<<" ";
	        }
	        //cout<<endl;
	    }
	
	    //cout<<"a"<<endl;
	int t;
	cin>>t;
	while(t--)
	{
	    int m;
	    cin>>m;
	    
	    cout<<res[m][0]<<endl;
	}
	return 0;
}