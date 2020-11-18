//countinversions in O(nlogn)  
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll merge(ll a[],ll temp[],ll left,ll mid,ll right)
{
	ll inv_cnt=0;
	ll i=left;// for the ledft subarray
	ll j=mid;// // for the right subarray
	ll k =left;// for the merged subarray
	while(i<=mid-1&&j<=right)
	{
		if(a[i]<=a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
			inv_cnt+= mid-i;
		}
	}
	 while (i <= mid - 1)  
        temp[k++] = arr[i++];  
  
    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right)  
        temp[k++] = arr[j++];  
	for(i=left;i<=right;i++)
	a[i] =temp[i];
	return inv_cnt;
	
}
ll _mergesort(ll a[],ll temp[],ll left,ll right)
{
	ll inv_cnt=0;
	if(right>left)
	{
		ll mid = (right+left)/2;
		inv_cnt = _mergesort(a,temp,left,mid);
		inv_cnt+= _mergesort(a,temp,mid+1,right);
		inv_cnt+=merge(a,temp,left,mid+1,right);
		// return inv_cnt;
	}
	return inv_cnt;
}
ll mergesort(ll arr[], ll array_size)  
{  
    ll temp[array_size];  
    return _mergesort(arr, temp, 0, array_size - 1);  
} 
int main() {
	ll n;
	cin>>n;
	ll i,a[100001];
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<mergesort(a,n);
    // return 0;
	// your code goes here
	return 0;
}                                                                                                                                                                                                                                                                                                                                                          