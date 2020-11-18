#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
// 2arrandsumoffunction
// codeforces round #560
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	
	sort(b.begin(), b.end());
	vector<pair<long long, int>> val(n);
	for (int i = 0; i < n; ++i) {
		val[i].first = (i + 1) * 1ll * (n - i) * a[i];
		val[i].second = i;
	}
	sort(val.rbegin(), val.rend());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + (val[i].first % MOD * 1ll * b[i]) % MOD) % MOD;
	}
	cout << ans << endl;
	
	return 0;
}