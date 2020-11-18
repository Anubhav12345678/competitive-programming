#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
ll solve(string s,char c,ll k)
{
	ll lft=0,lftcnt=0,rgt=0,rgtcnt=0,i,j;
	ll freq=0,res=0,len= s.size();
	while(s[lft]!=c&&lft<len)
	{
		lft++;
		lftcnt++;
	}
	rgt = lft+1;
	while(freq!=(k-1)&&rgt-1<len)
	{
		if(s[rgt]==c)
		freq++;
		rgt++;
	}
	while(lft<len&&rgt-1<len)
	{
		while(lft<len&&s[lft]!=c)
		{
			lft++;
			lftcnt++;
		}
		while(rgt<len&&s[rgt]!=c)
		{
			if(s[rgt]==c)
			freq++;
			rgt++;
			rgtcnt++;
		}
		res+=(lftcnt+1)*(rgtcnt+1);
		freq=k-1;
		lftcnt=0;
		rgtcnt=0;
		lft++;
		rgt++;
	}
	return res;
}
int main() {
	string s = "3123231"; 
    char c = '3'; 
    ll k = 2; 
  
    cout << solve(s, c, k);
	// your code goes here
	return 0;
}