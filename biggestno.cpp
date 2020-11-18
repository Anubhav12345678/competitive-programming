#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<vector>
#define pb push_back
int mycompare(string x,string y)
{
	string xy = x.append(y);
	string yx = y.append(x);
	return (xy.compare(yx))?1:0;
}

int biggestno(vector<string> arr)
{
	ll i;
	sort(arr.begin(),arr.end(),mycompare);
	for(i=0;i<arr.size();i++)
	cout<<arr[i];
}
int main()
{
	ll t,n;
	vector<string> a;
	cin>>t;
	string x;
	while(t--)
	{
		cin>>n;
		for(ll i=0;i<n;i++)
		{
		  cin>>x;
		  a.pb(x);	
		}
		cout<<biggestno(a)<<endl;
		a.clear();
	}
	
}
