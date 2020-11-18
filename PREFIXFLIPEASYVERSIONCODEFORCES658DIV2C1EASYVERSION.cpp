#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
/*
This is the easy version of the problem. The difference between the versions is the constraint on n and the required number
 of operations. You can make hacks only if all versions of the problem are solved.

There are two binary strings a and b of length n (a binary string is a string consisting of symbols 0 and 1). In an operation,
 you select a prefix of a, and simultaneously invert the bits in the prefix (0 changes to 1 and 1 changes to 0) and reverse
  the order of the bits in the prefix.

For example, if a=001011 and you select the prefix of length 3, it becomes 011011. Then if you select the entire string, it 
becomes 001001.

Your task is to transform the string a into b in at most 3n operations. It can be proved that it is always possible.

*/
int main() {
	
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		string a,b;
		cin>>a>>b;
		vector<ll> ans;
		for(i=0;i<n;i++){
			if(a[i]!=b[i])
			{
				ans.pb(i+1);
				ans.pb(1);
				ans.pb(i+1);
			}
		}
		k = ans.size();
		cout<<k<<" ";
		for(i=0;i<k;i++)
		cout<<ans[i]<<" ";
		cout<<endl;
	}
	// your code goes here
	return 0;
}