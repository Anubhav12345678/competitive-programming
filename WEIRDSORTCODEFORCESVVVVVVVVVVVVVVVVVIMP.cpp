#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*

You are given an array a of length n.

You are also given a set of distinct positions p1,p2,…,pm, where 1≤pi<n. The position pi means that you can swap elements a[pi] and a[pi+1]. You can apply this operation any number of times for each of the given positions.

Your task is to determine if it is possible to sort the initial array in non-decreasing order (a1≤a2≤⋯≤an) using only allowed swaps.

For example, if a=[3,2,1] and p=[1,2], then we can first swap elements a[2] and a[3] (because position 2 is contained in the given set p). We get the array a=[3,1,2]. Then we swap a[1] and a[2] (position 1 is also contained in p). We get the array a=[1,3,2]. Finally, we swap a[2] and a[3] again and get the array a=[1,2,3], sorted in non-decreasing order.

You can see that if a=[4,1,2,3] and p=[3,2] then you cannot sort the array.

You have to answer t independent test cases.

*/
int main() {
	int i,j,k,l,n,m,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<int> a(n),p(n,0);
		for(i=0;i<n;i++) cin>>a[i];
		for(i=0;i<m;i++){
			int pos;
			cin>>pos;
			p[pos-1]=1;
		}
		// bool ok=0;
		while(true)
		{
			bool ok=0;
		for(i=0;i<n;i++)
		{
			if(p[i]&&a[i]>a[i+1])
			{
				ok=1;
				swap(a[i],a[i+1]);
			}
		}
		if(!ok) break;
		}
		// if(!ok)
		// cout<<"NO\n";
		// else{
			bool ok=1;
			for(i=0;i<n-1;i++)
			ok&=(a[i]<=a[i+1]);
			if(ok) cout<<"YES\n";
			else
			cout<<"NO\n";
		// }
		// cout<<solve(a,p)<<endl;
		    
	}
	// your code goes here
	return 0;
}