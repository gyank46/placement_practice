#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>


using namespace std;

int choice(int A,int B,int i1,int i2,vector<pair<int,int> > a)
{
	if(A<0||B<0)
		return 0;
	if(i1==1&&i2==2)
		return max(choice(A+a[i1].first,B+a[i1].second,0,2,a),choice(A+a[i2].first,B+a[i2].second,0,1,a))+1;
	else if(i1==0&&i2==1)
		return max(choice(A+a[i1].first,B+a[i1].second,1,2,a),choice(A+a[i2].first,B+a[i2].second,0,2,a))+1;
	else if(i1==0&&i2==2)
		return max(choice(A+a[i1].first,B+a[i1].second,1,2,a),choice(A+a[i2].first,B+a[i2].second,0,1,a))+1;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<pair<int,int> > a(3);
		int A,B;
		cin>>A>>B;
		for(int i=0;i<3;i++)
		{
			int x,y;
			cin>>x>>y;
			a[i]=make_pair(x,y);
		}
		int x=choice(A+a[0].first,B+a[0].second,1,2,a);
		int y=choice(A+a[1].first,B+a[1].second,0,2,a);
		int z=choice(A+a[2].first,B+a[2].second,0,1,a);
		cout<<max(x,max(y,z))<<endl;
	}
}