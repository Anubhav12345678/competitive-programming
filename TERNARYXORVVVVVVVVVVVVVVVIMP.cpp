#include <bits/stdc++.h>

using namespace std;
/*
A number is ternary if it contains only digits 0, 1 and 2. For example, the following numbers are ternary: 1022, 11, 21, 2002.

You are given a long ternary number x. The first (leftmost) digit of x is guaranteed to be 2, the other digits of x can be 0, 1 or 2.

Let's define the ternary XOR operation ⊙ of two ternary numbers a and b (both of length n) as a number c=a⊙b of length n, where ci=(ai+bi)%3 (where % is modulo operation). In other words, add the corresponding digits and take the remainders of the sums when divided by 3. For example, 10222⊙11021=21210.

Your task is to find such ternary numbers a and b both of length n and both without leading zeros that a⊙b=x and max(a,b) is the minimum possible.

You have to answer t independent test cases.


*/
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		string x;
		cin >> n >> x;
		string a(n, '0'), b(n, '0');
		for (int i = 0; i < n; ++i) {
			if (x[i] == '1') {
				a[i] = '1';
				b[i] = '0';
				for (int j = i + 1; j < n; ++j) {
					b[j] = x[j];
				}
				break;
			} else {
				a[i] = b[i] = '0' + (x[i] - '0') / 2;
			}
		}
		cout << a << endl << b << endl;
	}
	
	return 0;
}