#include <bits/stdc++.h>
using namespace std;

/*

Polycarp wants to buy exactly n shovels. The shop sells packages with shovels. The store has k types of packages: the package of the i-th type consists of exactly i shovels (1≤i≤k). The store has an infinite number of packages of each type.

Polycarp wants to choose one type of packages and then buy several (one or more) packages of this type. What is the smallest number of packages Polycarp will have to buy to get exactly n shovels?

For example, if n=8 and k=7, then Polycarp will buy 2 packages of 4 shovels.

Help Polycarp find the minimum number of packages that he needs to buy, given that he:

will buy exactly n shovels in total;
the sizes of all packages he will buy are all the same and the number of shovels in each package is an integer from 1 to k, inclusive.


*/
int main() {
	int test;
	cin >> test;

	for (int tt = 0; tt < test; tt++) {
		int n, k;
		cin >> n >> k;

		int ans = n;

		for (int j = 1; j * j <= n; j++) {
			if (n % j == 0) {
				if (j <= k) {
					ans = min(ans, n / j);
				}

				if (n / j <= k) {
					ans = min(ans, j);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}