#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
void swap(char *a,char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}
ll solve(string s)
{
	ll len = s.size();
	ll i,j,cnt=0,p=0,sum=0;
	vector<ll> v;
	for(i=0;i<len;i++)
	if(s[i]=='[')
	v.pb(i);
	for(i=0;i<len;i++)
	{
		if(s[i]=='[')
		{
			cnt++;//to store cnt of '['
			p++;// to store next pos of '[' in v
		}
		else
		cnt--;
		if(cnt<0)// mns we have to start swapping
		{
			sum+=v[p]-i;//no of consequitive swaps 
			swap(&s[i],&s[v[p]]);
			p++;// so that now p points to the next '[a'
			cnt=1;//as we v encountered a '[' as after swapping ']' with '['
		}
	}
	return sum;
}
int main() {
	string s = "[]][]["; 
    cout << solve(s) << "\n"; 
  
    s = "[[][]]"; 
    cout <<solve(s) << "\n"; 
    return 0;
	// your code goes here
	return 0;
}