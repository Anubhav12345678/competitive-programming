#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#define noofchar 256
bool ispalinpermuteposs(string s)
{
	ll cnt[noofchar] = {0};
	ll i,j,k;
	for(i=0;i<s.size();i++)
	cnt[s[i]-'a']++;
	ll odd=0;
	for(i=0;i<noofchar;i++)
	if(cnt[i]%2==1)
	odd++;
	if(odd>1)
	return false;
	else
	return true;
}
int main() {
    cout<<(ispalinpermuteposs("geeksogeeks"))?"YES\n":"NO\n";
	// your code goes here
	return 0;
}