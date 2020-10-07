#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
//int v[100000000]={0};

void s(string a,string b)
{
	int carry=0;
	int j=b.length()-1;
	int i=a.length()-1;
	string c;
	while(j>=0&&i>=0)
	{
		c+=((carry+a[i]-48+b[j]-48)%10)+48;
		carry=(carry+a[i]-48+b[j]-48)/10;
		j--;
		i--;
	}
	while(j>=0)
	{
		c+=((b[j]-48+carry)%10)+48;
		carry=(carry+b[j]-48)/10;
		j--;
	}
	while(i>=0)
	{
		c+=((a[i]-48+carry)%10)+48;
		carry=(carry+a[i]-48)/10;
		i--;
	}
	if(carry>0)
		c+=carry+48;
	for(int i=c.length()-1;i>=0;i--)
		cout<<c[i];
	cout<<endl;

}
void p(string a,string b)
{

}


 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		s(a,b);
		//cout<<a<<" "<<b;
 
	}
}  