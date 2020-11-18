#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<set>
#include<iterator>
#include<string.h>
bool ispalin(string a)
{
    string t = a;
    reverse(t.begin(),t.end());
    if(a.compare(t)==0)
    return 1;
    else
    return 0;
}
ll solve(string s)
{
    ll n = s.size();
    ll i,j,k,len;
    string res;
    set<string> se;
    for(len = 1;len<=n;len++)
    {
        for(i=0;i<n-len+1;i++)
        {
            // j = i+l-1;
            res = s.substr(i,len);
            if(ispalin(res))
            se.insert(res);
        }
    }
    return se.size();
}
int main() {
    ll t,i,j,k,len,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cout<<solve(s)<<endl;
    }
	//code
	return 0;
}