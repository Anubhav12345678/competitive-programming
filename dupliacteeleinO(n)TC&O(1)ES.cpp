#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<math.h>
// duplicate ele in O(n) timme and O(1) extra space
int main() {
	ll a[100005],i,j,n;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	if(a[abs(a[i])]>=0)
	a[abs(a[i])]*=-1;
	else
	{
		// previously negative so itmeans it is repeating
		cout<<abs(a[i])<<" ";
	}
	
	// your code goes here
	return 0;
}