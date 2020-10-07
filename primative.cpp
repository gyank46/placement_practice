#include<iostream>
#include<vector>
#include<math.h>


using namespace std;





    string sum(string A,string B)
    {
        int carry=0;
        string c="";
        string temp;
        if(A.length()<=B.length())
        {
        	temp=A;
            A=B;
            B=temp;
        }
        	int k=A.length()-1;	
            cout<<A<<" "<<B<<endl;
            for(int i=B.length()-1;i>=0;i--)
            {
                c+=(((A[k]-'0')+(B[i]-'0')+carry)%10)+'0';
                carry=(((A[k]-'0')+(B[i]-'0')+carry)/10);
                k--;
            }
            for(int i=k;i>=0;i--)
            {
            	c+=(((A[k]-'0')+carry)%10)+'0';
                carry=(((A[k]-'0')+carry)/10);
            }
            if(carry>0)
                c+=(carry+'0');
            reverse(c.begin(),c.end());
            return c;
    }
        
     
    string multi(string a,int num)
    {
        int carry=0;
        string c="";
        for(int i=a.length()-1;i>=0;i--)
        {
            c+=(((((a[i]-'0')*num)+carry)%10)+'0');
            carry=((((a[i]-'0')*num)+carry)/10);
        }
        if(carry>0)
            c+=(carry+'0');
        reverse(c.begin(),c.end());
        return c;
    }
    string multiply(string A, string B)
    {
        vector<string> c;                                         								        		
        string t;																								
        {
        	t=A;
            A=B;
            B=t;
        }
            for(int i=B.length()-1;i>=0;i--)
            {
                string d=multi(A,B[i]-'0');
                for(int j=0;j<(B.length()-1-i);j++)
                    d+='0';
                c.push_back(d);
            }
            string sumi=c[0];
            for(int i=1;i<c.size();i++)
            {	
            	cout<<sumi<<endl;
                sumi=sum(sumi,c[i]);
            }
            string sumii;
            int i;
            for(i=0;i<sumi.length();i++)
            {
                if(sumi[i]!='0')
                    break;
            }
            for(int j=i;j<sumi.length();j++)
                sumii+=sumi[j];
            if(sumii=="")
                sumii+='0';
            return sumii;
    }
        
        



int main()
{
	string a,b;
	cin>>a>>b;
	cout<<multiply(a,b)<<endl;

	return 0;

}