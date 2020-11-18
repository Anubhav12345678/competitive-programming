#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*

You are given a bracket sequence s of length n, where n is even (divisible by two). The string s consists of n2 opening brackets '(' and n2 closing brackets ')'.

In one move, you can choose exactly one bracket and move it to the beginning of the string or to the end of the string (i.e. you choose some index i, remove the i-th character of s and insert it before or after all remaining characters of s).

Your task is to find the minimum number of moves required to obtain regular bracket sequence from s. It can be proved that the answer always exists under the given constraints.

Recall what the regular bracket sequence is:

"()" is regular bracket sequence;
if s is regular bracket sequence then "(" + s + ")" is regular bracket sequence;
if s and t are regular bracket sequences then s + t is regular bracket sequence.
For example, "()()", "(())()", "(())" and "()" are regular bracket sequences, but ")(", "()(" and ")))" are not.

You have to answer t independent test cases.



*/
ll solve(string s)
{
	ll i,j,k,l,n=s.size();
	ll cnt=0,open=0;
	stack<ll> st;
	for(i=0;i<n;i++)
	{
		if(s[i]=='(') cnt++;
		else
		{
			cnt--;
			if(cnt<0)
			{
				cnt++;
				open++;
			}
		}
	}
	return open;
}
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--)
    {
    	string s;
    	cin>>n>>s;
    	cout<<solve(s)<<endl;
    }
	// your code goes here
	return 0;
}