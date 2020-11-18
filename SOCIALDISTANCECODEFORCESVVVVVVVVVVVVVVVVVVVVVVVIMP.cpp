#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*

Polycarp and his friends want to visit a new restaurant. The restaurant has n
 tables arranged along a straight line. People are already sitting at some tables.
  The tables are numbered from 1 to n in the order from left to right. The state of 
  the restaurant is described by a string of length n which contains characters "1"
   (the table is occupied) and "0" (the table is empty).

Restaurant rules prohibit people to sit at a distance of k or less from each other.
 That is, if a person sits at the table number i, then all tables with numbers from 
 −k to i+k (except for the i-th) should be free. In other words, the absolute difference 
 of the numbers of any two occupied tables must be strictly greater than k.

For example, if n=8 and k=2, then:

strings "10010001", "10000010", "00000000", "00100000" satisfy the rules of the restaurant;
strings "10100100", "10011001", "11111111" do not satisfy to the rules of the restaurant,
 since each of them has a pair of "1" with a distance less than or equal to k=2.
In particular, if the state of the restaurant is described by a string without "1" or
 a string with one "1", then the requirement of the restaurant is satisfied.

You are given a binary string s that describes the current state of the restaurant. It 
is guaranteed that the rules of the restaurant are satisfied for the string s.

Find the maximum number of free tables that you can occupy so as not to violate the rules
 of the restaurant. Formally, what is the maximum number of "0" that can be replaced by "1" such that the requirement will still be satisfied?

For example, if n=6, k=1, s= "100010", then the answer to the problem will be 1, since 
only the table at position 3 can be occupied such that the rules are still satisfied.




*/
ll solve(string s,ll K)
{  
	ll ans=0,i,j,k,l,n=s.size(),r;
    for(i=0;i<n;)
    {
    	bool f=0;
    	for(j=i;j<i+K+1&&j<n;j++)
    	{
    		if(s[j]=='1')
    		{
    			f=1;
    			i=j+K+1;
    			break;
    		}
    	}
    	if(!f)
    	{
    		i=i+K+1;
    		ans++;
    	}
    }
	return ans;
	
}
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		string s;
		cin>>s;
		cout<<solve(s,k)<<endl;
	}
	// your code goes here
	return 0;
}