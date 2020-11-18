#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sq(x) ((x)*(x))
#define fo(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<n;i++)
#define Fo(i,n) for(int i=1;i<=n;i++)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
const double pi = 3.14159265358979323846;
#define uni(c) (c).resize(unique(all(c))-(c).begin())
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
//pair <int, int> w[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};   // for matrix movement:
/*
You are given an array A of length N. You have to choose a subset S from given array A, such that average 
of S is less than K. You need to print the maximum possible length of S.

*/
void cp()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
void solve()
{
	ll n; cin >> n;
	ll a[n];
	fo(i, n)cin >> a[i];
	sort(a, a + n);
	ll sum = 0;
	vi dp(n, 0);
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		dp[i] = sum / (i + 1);
	}
	ll q; cin >> q;
	while (q--)
	{
		ll x; cin >> x;
		cout << lower_bound(all(dp), x) - dp.begin() << "\n";
	}
 
}
int main()
{
	fast;
	//cp();
	ll t = 1;
	//cin >> t;
	while (t--)
		solve();
 
 
	return 0;
}