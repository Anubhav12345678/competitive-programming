#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
#include<set>
map<int,int> m;
set<int> s;
int main() {
	int n,i,j,k,l,ans;
	cin>>n;
	ans=n;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	{
		m.clear();
		s.clear();
		for(j=0;j<n;j++)
		{
			m[a[j]]++;
			s.insert(a[j]);
		}
		if(s.size()==n)
		{
			ans=0;
			break;
		}
		for(j=i;j<n;j++)
		{
			m[a[j]]--;
			if(m[a[j]]==0)
			s.erase(a[j]);
			if(s.size()==(n-(j-i+1)))
			ans = min(ans,j-i+1);
		}
	}
	cout<<ans<<endl;
	// your code goes here
	return 0;
}