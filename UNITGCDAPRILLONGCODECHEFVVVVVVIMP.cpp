#include <bits/stdc++.h>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		/**
			if the n is 1 the answer is 1

			else
			the lower bound of the answer is floor(N / 2), because no two even numbers can be in the same set
			this bound can be achieved by creating pair of adjacent numbers (i.e (1, 2) (3, 4) (5, 6) ...)
			if N is odd, the number N will be unused, but it can be put in the tuple (1, 2)
			as it's an odd number the GCD(2, N) = 1
		 * */
		if(n == 1){
			cout << 1 << '\n';
			cout << 1 << ' ' << 1 << '\n';
		} else {
			cout << n / 2 << '\n';
			if(n % 2){
				cout << 3 << ' ' << 1 << ' ' << 2 << ' ' << n << '\n';
			} else {
				cout << 2 << ' ' << 1 << ' ' << 2 << '\n';
			}
			for(int i = 4; i <= n; i += 2){
				cout << 2 << ' ' << i - 1 << ' ' << i << '\n';
			}
		}
	}
	return 0;
}