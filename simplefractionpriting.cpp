#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<map>
#include<iterator>
int main() {
	map<ll, ll> mp;
	mp.clear();
	ll t,d,n,r,rem;
	string res;
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		if(n%d==0)
		{
			cout<<n/d<<endl;
			continue;
		}
		else
		{
			res = "";
			res+=to_string(n/d);
			res+=".";
			mp.clear();
			rem = n%d;
			while(rem!=0&&mp.find(rem)==mp.end())
			{
				// cout<<"rem = "<<res<<endl;
				mp[rem] = res.length();//to make sure that;
				rem*=10;
				ll res_part = rem/d;
				res+=to_string(res_part);
				rem = rem%d;
			}
			
			cout<<res<<endl;
		}
	}
	// your code goes here
	return 0;
}