#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 4191;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;


 
void nika_orz(int tc = 0) {
	cin >> n >> m;
	
	bool on[n][m];
	memset(on, 0, sizeof(on));
	int state[n][m];
	memset(state, 0, sizeof(state));
	
	ll bulb, block;
	cin >> bulb >> block;
	
	for (ll i = 0; i < bulb; i++) {
		ll r, c;
		cin >> r >> c;
		--r; --c;
		state[r][c] = 1;
	}
	for (ll i = 0; i < block; i++) {
		ll r, c;
		cin >> r >> c;
		--r; --c;
		state[r][c] = 2;
	}
	
	for (ll i = 0; i < n; i++) {
		bool lit = 0;
		ll start = 0;
		for (ll j = 0; j < m; j++) {
			if (state[i][j] == 2) {
				start = j + 1;
				lit = 0;
			} else if (state[i][j] == 1) {
				while (start < j) {
					on[i][start] = 1;
					++start;
				}
				lit = 1;
			}
			
			if (lit && state[i][j] != 2) on[i][j] = 1;
		}
	}
	
	for (ll i = 0; i < m; i++) {
		bool lit = 0;
		ll start = 0;
		for (ll j = 0; j < n; j++) {
			if (state[j][i] == 2) {
				start = j + 1;
				lit = 0;
			} else if (state[j][i] == 1) {
				while (start < j) {
					on[start][i] = 1;
					++start;
				}
				lit = 1;
			}
			
			if (lit && state[j][i] != 2) on[j][i] = 1;
		}
	}
	
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cnt += on[i][j];
		}
	}
	
	cout << cnt << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) nika_orz(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
} 


/*

We have a grid with 
H
 rows and 
W
 columns. Let square 
(
i
,
j
)
 be the square at the 
i
-th row and 
j
-th column in this grid.
There are 
N
 bulbs and 
M
 blocks on this grid. The 
i
-th bulb is at square 
(
A
i
,
B
i
)
, and the 
i
-th block is at square 
(
C
i
,
D
i
)
. There is at most one object - a bulb or a block - at each square.
Every bulb emits beams of light in four directions - up, down, left, and right - that extend until reaching a square with a block, illuminating the squares on the way. A square with a bulb is also considered to be illuminated. Among the squares without a block, find the number of squares illuminated by the bulbs.


*/