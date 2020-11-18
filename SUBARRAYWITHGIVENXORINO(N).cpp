#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
// fun to cal no of subarrays with gvn xor
// m: req xor val
ll int solve(int a[],int n,int m)
{
	int i,j,k,l;
	int xorarr[n];
	xorarr[0] = a[0];
	for(i=1;i<n;i++)
	xorarr[i] = xorarr[i-1]^a[i];
	map<int,int> mp;
	ll int ans=0;
	for(i=0;i<n;i++)
	{
		int tmp =  m^xorarr[i];
		ans+=(ll)mp[tmp];
		if(xorarr[i]==m)
		ans++;
		mp[xorarr[i]]++;
	}
	return ans;
}
int main() {
	 int arr[] = { 4, 2, 2, 6, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int m = 6; 
  
    cout << "Number of subarrays having given XOR is "
         << solve(arr, n, m); 
    return 0; 
}