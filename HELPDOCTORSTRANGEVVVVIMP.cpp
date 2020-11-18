/*
Doctor Strange loves playing with arrays. He can select any even length subarray and divide the choosen subarray into two halves. Choosen subarray can be of zero length. Then he will reverse either the left-half subarray(L) or the right-half subarray(R). Then he computes value of following function for that subarray.
 the sum of product of the corresponding elements in both the left-half() and right-half subarrays().
Let  be an even length array . Let us suppose Doctor strange chooses an even length subarray= . He divides the choosen subarray into two halfs, left-half= and right-half= and reverses the left-half so that it becomes . The value of  for choosen subarray is . Help Doctor strange to choose a subarray with maximum  value.

Note: Doctor Strange has to reverse exactly one of left or right half of choosen subarray.




*/






#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll arr[2*n];
    for(ll i=0; i<2*n; i++)
        cin>>arr[i];
    ll ans=0;
    ll brr[2*n];
    memset(brr,0,sizeof(brr));
    for(ll i=1; i<=n; i++)
    {
         for(ll j=i; j<=2*n-i; j++)
         {
             brr[j]=brr[j]+(arr[j-i]*arr[j+i-1]);
             ans=max(ans,brr[j]);
         }
    }
    cout<<ans<<endl;
    return 0;
}