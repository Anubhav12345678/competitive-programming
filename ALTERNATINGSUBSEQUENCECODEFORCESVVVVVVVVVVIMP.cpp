#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*
Recall that the sequence b is a a subsequence of the sequence a if b can be derived from a by removing zero or more elements without changing the order of the remaining elements. For example, if a=[1,2,1,3,1,2,1], then possible subsequences are: [1,1,1,1], [3] and [1,2,1,3,1,2,1], but not [3,2,3] and [1,1,1,1,2].

You are given a sequence a consisting of n positive and negative elements (there is no zeros in the sequence).

Your task is to choose maximum by size (length) alternating subsequence of the given sequence (i.e. the sign of each next element is the opposite from the sign of the current element, like positive-negative-positive and so on or negative-positive-negative and so on). Among all such subsequences, you have to choose one which has the maximum sum of elements.

In other words, if the maximum length of alternating subsequence is k then your task is to find the maximum sum of elements of some alternating subsequence of length k.

You have to answer t independent test cases.	

*/
ll solve(vector<ll> &v)
{
	ll i,j,k,l,n=v.size();
	ll ans=0LL;
	for(i=0;i<n;i++)
	{
		ll maxi=v[i];
		j=i;
		while(j<n&&v[i]*v[j]>0)
		{
			maxi = max(maxi,v[j++]);
		}
		ans+=maxi;
		i=j-1;
	}
	return ans;
}
int main() {
	ll t,i,j,k,l,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<ll> v(n);
		for(i=0;i<n;i++) cin>>v[i];
		cout<<solve(v)<<endl;
	}
	// your code goes here
	return 0;
}