#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string>

int main() {
	string s;
	cin>>s;
	int n = s.size();
	int i,j,k,l,q,r;
	int a[n]={0};
    int cnt=0;
    for(i=1;i<n;i++)
    {
    if(s[i]==s[i-1])
    {
    	cnt++;
    }
    a[i]=cnt;
    }
    cin>>q;
    while(q--)
    {
    	cin>>l>>r;
    	l--,r--;
    	cout<<a[r]-a[l]<<endl;
    }
   
	// your code goes here
	return 0;
}