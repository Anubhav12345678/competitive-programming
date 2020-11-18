#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD = 1000000 + 3;

int fact[MOD], inv[MOD], Tn, N, L, R;

int C (int n, int k) {
	if (k > n)
		return 0;
	return (fact[n] * 1LL * inv[k] * 1LL * inv[n - k]) % MOD;
}

int binpow (int k, int pw, int mod) {
	if (pw == 1)
		return k;
	int q = binpow(k, pw / 2, mod);
	q = (q * 1LL * q) % mod;
	if (pw % 2 == 1)
		q = (q * 1LL * k) % mod;
	return q;
}

int main (int argc, char * const argv[]) {
	ios_base::sync_with_stdio(false);
	fact[0] = inv[0] = 1;
	for(int i = 1; i <= MOD - 1; i++) {
		fact[i] = (fact[i - 1] * 1LL * i) % MOD;
		inv[i] = binpow(fact[i], MOD - 2, MOD);
	}
	cin >> Tn;
	while (Tn--) {
		cin >> N >> L >> R;
		int k = R - L + 1;
		int n = N + 1;
//		cout << C(n + k - 1, n - 1) << endl;		// first subtask
		long long ret = C((n + k - 1) / MOD, (n - 1) / MOD) * 1LL * C((n + k - 1) % MOD, (n - 1) % MOD) % MOD;
		cout << (ret - 1 + MOD) % MOD << endl;
	}
    return 0;
}