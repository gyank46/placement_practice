#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>


using namespace std;

int reverseWords(string &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,index=-1;
    for(i=0;i<A.length();i++)
    {
        if(A[i]!=' ')
        {
            index=i;
            break;
        }
    }
    if(index==-1)
        return 0;
    string b="";
    for(i=index;i<A.length();i++)
    {   
        if(i==index)
        {
            if(A[i]>='0'&&A[i]<='9')
            {
                b+='+';
                b+=A[i];
            }
            if(A[i]<'0'||A[i]>'9')
            {
                if(A[i]=='+'||A[i]=='-')
                    b+=A[i];
                else
                    break;
            }
        }
        else
        {
            if(A[i]<'0'||A[i]>'9')
                break;
            else
                b+=A[i];
        }
    }
    string c="";
    for(int i=1;i<b.length();i++)
        c+=b[i];
    stringstream g(c);
    int x=0;
    g>>x;
    if(x>INT_MAX&&b[0]=='+')
        return INT_MAX;
    if(x>INT_MAX&&b[0]=='-')
        return INT_MIN;
    if(b[0]=='+')
        return x;
    if(b[0]=='-')
        return (-1*x);
}

int main()
{
	/*int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a.push_back((t));
	}
    //sort(a.begin(),a.end(),myfunction);*/
    string b;
    getline(cin,b);
    int c;
    c=reverseWords(b);
    cout<<c<<endl;
	//int b=repeatedNumber(a);
	//for(int i=0;i<a.size();i++)
	  // b+=a[i];
    //cout<<b<<endl;
}