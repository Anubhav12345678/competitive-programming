
/*

The next lecture in a high school requires two topics to be discussed. The i-th topic is interesting by ai units
 for the teacher and by bi units for the students.

The pair of topics i and j (i<j) is called good if ai+aj>bi+bj (i.e. it is more interesting for the teacher).

Your task is to find the number of good pairs of topics.



*/

/*

Let's rewrite the inequality from ai+aj>bi+bj to (ai−bi)+(aj−bj)>0. This looks much simpler.
 Let's build the array c where ci=ai−bi and sort this array. Now our problem is to find the number of pairs i<j such that ci+cj>0.

Let's iterate over all elements of c from left to right. For simplicity, we consider only 
"greater" summands. Because our sum (ci+cj) must be greater than 0, then at least one of
 these summands will be positive. So, if ci≤0, just skip it. Now ci>0 and we need to 
 calculate the number of such j that ci+cj>0 and j<i. It means that each cj≥−ci+1 (for some j<i)
  will be okay. Such leftmost position j can be found with std::lower_bound or binary search. Then 
  add the value i−j to the answer and consider the next element.

Time complexity: O(nlogn).

*/



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
ll solve(ll a[],ll b[],ll n)
{
	ll i,j,k,l,ans=0;
	vector<ll> c(n);
	for(i=0;i<n;i++) c[i] = a[i]-b[i];
	// sort(c,c+n);
	sort(c.begin(),c.end());
	for(i=0;i<n;i++)
	{
		if(c[i]>0)
		{
		 ll y = -c[i]+1;
		 ll x = lower_bound(c.begin(),c.end(),y)-c.begin();
		 ans+=i-x;
		}
	}
	return ans;
	
}
int main() {
	ll i,j,k,l,n;
	cin>>n;
	ll a[n],b[n];
	for(i=0;i<n;i++) cin>>a[i];
	for(j=0;j<n;j++) cin>>b[j];
	cout<<solve(a,b,n)<<endl;
	// your code goes here
	return 0;
}