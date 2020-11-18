#include <bits/stdc++.h>
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100010
#define maxc 1000000007

using namespace std;

int n, a[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("INP.TXT", "r")) {
		freopen("INP.TXT", "r", stdin);
		freopen("OUT.TXT", "w", stdout);
	}
	int Tests; cin >> Tests;
	while (Tests--) {
		cin >> n;
		FOR(i, 1, n) cin >> a[i];
		a[0] = -maxc;
		a[n+1] = maxc;
		int lef = 1;
		int rig = n;

		FOR(i, 2, n) {
			if (a[i] > a[i-1]) lef = i;
			else break;
		}
		FORD(i, n-1, 1) {
			if (a[i] < a[i+1]) rig = i;
			else break;
		}
		if (lef == n) {
			cout <<1ll*n*(n+1)/2 - 1<<'\n';
			continue;
		}
		long long res = 0;
		FOR(i, rig, n+1) {
			int pos = lower_bound(a, a+lef+1, a[i]) - a;
			res += pos;
		}
		cout <<res - 1<<'\n';
	}
}
