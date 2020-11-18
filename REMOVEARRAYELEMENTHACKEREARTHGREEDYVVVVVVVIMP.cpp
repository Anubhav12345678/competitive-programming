#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define pb push_back
const ll INF=1e18;
const int mod=1000000007;
/*
You are given an integer array A of size N. You can perform an operation exactly N number of times. In the operation,
 you can remove one element from the array A and the operation will cost Ai units if ith is removed from the array. The 
 operation will take 1 second.

Elements of array A will keep on increasing every second until it is removed. Let ith element is Ai at jth  second. Then the ith 
 element will increase by (j+1)*Ai and the element will become Ai+(j+1)*A[i] at (j+1)th second.

Your task is to find the minimum cost to remove all the elements from the array A. As the answer can be very large, 
print the answer module 1e9+7.

*/
ll arr[100005], fact[100005];
int main()
{
    ll t,n,m,i,j,k;
    fact[0]=1;
    for (i=1;i<100005;++i)
        fact[i]=(i*fact[i-1])%mod;
    scanf ("%lld",&t);
    while (t--)
    {
        scanf ("%lld",&n);
        for (i=1;i<=n;++i)
            scanf ("%lld",&arr[i]);
        sort(arr+1,arr+n+1,greater<>());
        ll ans=0;
        for (i=1;i<=n;++i)
            ans=(ans+fact[i]*arr[i])%mod;
        printf ("%lld\n",ans);
    }
	return 0;
}