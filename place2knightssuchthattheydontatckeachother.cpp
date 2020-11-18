#include <bits/stdc++.h>
using namespace std;
#define ll long long
//place2knightssuchthattheydontatckeachother
ll solve(ll n,ll m)
{
	ll s=0,i=0,j=0,k=0,c=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			// cout<<"i = "<<i<<" j = "<<j<<endl;
			
			// cout<<"i = "<<i<<" j = "<<j<<endl;
			// cout<<"c = "<<c<<endl;
			c=0;
			// cout<<"c = "<<c<<endl;
			if(i+1<n&&j+2<m)
			{
				// cout<<"first if\n";
				// cout<<"i = "<<i<<" j = "<<j<<endl;
				// cout<<"c = "<<c<<endl;
			c++;
			// cout<<"c = "<<c<<endl;
			}
			if(i+2<n&&j+1<m)
			{
				// cout<<"second if\n";
				// cout<<"i = "<<i<<" j = "<<j<<endl;
				// cout<<"c = "<<c<<endl;
			c++;
			// cout<<"c = "<<c<<endl;
			}
			if(i-1>=0&&j+2<m)
			{
				// cout<<"third if\n";
				// cout<<"i = "<<i<<" j = "<<j<<endl;
				// cout<<"c = "<<c<<endl;
			c++;
			// cout<<"c = "<<c<<endl;
			}
			if(i-2>=0&&j+1<m)
			{
				// cout<<"fourth if\n";
				// cout<<"i = "<<i<<" j = "<<j<<endl;
				// cout<<"c = "<<c<<endl;
			c++;
			// cout<<"c = "<<c<<endl;
			}
			if(i+1<n&&j-2>=0)
			{
				// cout<<"fifth if\n";
				// cout<<"i = "<<i<<" j = "<<j<<endl;
				// cout<<"c = "<<c<<endl;
			c++;
			// cout<<"c = "<<c<<endl;
			}
			if(i+2<n&&j-1>=0)
			{
				// cout<<"sixth if\n";
				// cout<<"i = "<<i<<" j = "<<j<<endl;
				// cout<<"c = "<<c<<endl;
			c++;
			// cout<<"c = "<<c<<endl;
			}
			if(i-1>=0&&j-2>=0)
			{
				// cout<<"seventh if\n";
				// cout<<"i = "<<i<<" j = "<<j<<endl;
				// cout<<"c = "<<c<<endl;
			c++;
			// cout<<"c = "<<c<<endl;
			}
			if(i-2>=0&&j-1>=0)
			{
				// cout<<"last if\n";
				// cout<<"i = "<<i<<" j = "<<j<<endl;
				// cout<<"c = "<<c<<endl;
			c++;
			// cout<<"c = "<<c<<endl;
			}
			// cout<<"c = "<<c<<endl;
			// cout<<"s = "<<s<<endl;
			s+=(n*m)-1-c;
			// cout<<"s = "<<s<<endl;
		}
	}
	return s;
}
int main() {
	ll t,n,m,i,j;
	cin>>t;
	while(t--)
	{
	cin>>n>>m;
	cout<<solve(n,m)<<endl;
	}
	
	// your code goes here
	return 0;
}