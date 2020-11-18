#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
/*
For the given integer n (n>2) let's write down all the strings of length n which contain n−2 letters 'a'
 and two letters 'b' in lexicographical (alphabetical) order.

Recall that the string s of length n is lexicographically less than string t of length n, if there exists
 such i (1≤i≤n), that si<ti, and for any j (1≤j<i) sj=tj. The lexicographic comparison of
  strings is implemented by the operator < in modern programming languages.

For example, if n=5 the strings are (the order does matter):

aaabb
aabab
aabba
abaab
ababa
abbaa
baaab
baaba
babaa
bbaaa
It is easy to show that such a list of strings will contain exactly n⋅(n−1)2 strings.

You are given n (n>2) and k (1≤k≤n⋅(n−1)2). Print the k-th string from the list.
*/
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, k;
        cin >> n >> k;
        string s(n, 'a');
        for (int i = n - 2; i >= 0; i--) {
            if (k <= (n - i - 1)) {
                s[i] = 'b';
                s[n - k] = 'b';
                cout << s << endl;
                break;
            }
            k -= (n - i - 1);
        }
    }
}   