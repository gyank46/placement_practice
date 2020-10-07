#include <iostream>
//#include <bits/stdc++.h>
using namespace std  ;
int recursive(int n , int N , int p , int k )
{
	if(n == N )
	{
	return 1 ; 
	}
	if(p >= k )
	{
		return recursive(n +1  , N , p , 0 ) ; 
	}else if (p < k )
	{
		return recursive(n+1 , N , p , k+1)  + recursive(n+1 ,N , p , 0 ) ;  
	}
}
int main(){
	int t ; 
	cin>>t; 
	while(t > 0 ){
	 int n , p ;  
	 cin>>n>>p  ; 
	 cout<<(recursive(2 ,n , p , 0 ))<<endl; 
	 t-- ; 
	}
}