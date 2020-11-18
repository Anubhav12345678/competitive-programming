#include <bits/stdc++.h>
using namespace std;
#define  ll  long long
int main() {
	ll h,b,f,c,p,i,j,k,l,t;
	cin>>t;
	while(t--)
	{
		ll res=0;
		cin>>b>>p>>f;
		cin>>h>>c;
		b/=2;
		if(h<c)
		{
			swap(h,c);
			swap(p,f);
		}
		ll cnt = min(b,p);
		b-=cnt;
		p-=cnt;
		res+=cnt*h;
		cnt = min(b,f);
		res+=cnt*c;
		cout<<res<<endl;
	}
	
	// your code goes here
	return 0;
}