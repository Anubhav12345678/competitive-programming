#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
/*
Ashish has an array a of size n.

A subsequence of a is defined as a sequence that can be obtained from a by deleting some elements (possibly none), without changing the order of the remaining elements.

Consider a subsequence s of a. He defines the cost of s as the minimum between:

The maximum among all elements at odd indices of s.
The maximum among all elements at even indices of s.
Note that the index of an element is its index in s, rather than its index in a. The positions are numbered from 1. So, the cost of s is equal to min(max(s1,s3,s5,…),max(s2,s4,s6,…)).

For example, the cost of {7,5,6} is min(max(7,6),max(5))=min(7,5)=5.

Help him find the minimum cost of a subsequence of size k.
*/
 
using namespace std;
int ar[200001];
int k , n;
 
bool isPossibleEven(int val)
{
	int sum = 0;
	
	for(int i=1;i<=n;i++)
	{
		if(sum % 2 == 0) sum++;
		else
		if(ar[i] <= val) sum++;
	}
	
	return sum >= k;
}
 
bool isPossibleOdd(int val)
{
	int sum = 0;
	
	for(int i=1;i<=n;i++)
	{
		if(sum % 2 == 0)
		{
			if(ar[i] <= val) sum++;
		}
		else
		sum++;
	}
	
	return sum >= k;
}
 
int BS(int L , int H)
{
	int ans = H;
	
	while(L <= H)
	{
		int mid = (L + H) / 2;
		
		if(isPossibleOdd(mid) || isPossibleEven(mid))
		ans = mid , H = mid - 1;
		
		else
		L = mid + 1;
	}
	
	return ans;
}
int main()
{
	cin>>n>>k;
	REP(i , n) cin>>ar[i];
	
	cout<<BS(1 , 1e9);
}


////meeeeeeeeeeeeeeeee
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
ll a[200005],n,k;
bool iseven(ll val){
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		if(cnt%2==0) cnt++;
		else
		if(a[i]<=val) cnt++;
	}
	return cnt>=k;
}
bool isodd(ll val){
		ll cnt=0;
	for(ll i=1;i<=n;i++){
		if(cnt%2==0){ if(a[i]<=val) cnt++;}
		else
		cnt++;
	}
	return cnt>=k;
}
ll solve(){
	ll lo=INT_MAX;
	ll hi =-1;
	for(ll i=1;i<=n;i++){
		lo = min(lo,a[i]);
		hi = max(hi,a[i]);
	}
	ll ans=hi;
	while(lo<=hi){
		ll m = (lo+hi)/2;
		if(isodd(m)||iseven(m))
		{
			ans=m;
			hi=m-1;
		}
		else
		lo=m+1;
	}
	return ans;
}
int main(){
	ll i,j,l,m;
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	cout<<solve();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}


















n