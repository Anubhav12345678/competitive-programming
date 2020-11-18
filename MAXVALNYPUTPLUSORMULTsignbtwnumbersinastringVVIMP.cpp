#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
ll solve(string s)
{
	int n = s.size();
	int res = (s[0]-'0');
	int i,j,k,l;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='0'||s[i]=='1'||res<2)
		res+=(s[i]-'0');
		else
		res*=(s[i]-'0');
	}
	return res;
}
int main() {
	string str = "01891"; 
    cout << solve(str); 
    return 0;
	// your code goes here
	// return 0;
}