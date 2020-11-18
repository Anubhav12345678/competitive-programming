/*
Flipkart IIT Kanpur 2018
https://www.hackerrank.com/contests/hack-it-to-win-it-paypal/challenges/q4-traveling-is-fun
*/
/*

Julia is planning a vacation and has a list of cities she wants to visit. She doesn't have a map 
of the area, but she does have some data that will help here determine whether there is a road 
connection all the cities she wants to visit. The data comes in the form of two arrays. Each of
 the first array's elements is an origin city. Each of the second array's is a destination.
  There is also an integer value threshold. She can tell that any two cities are connected 
  if the values at origin and destination share a common divisor greater than the threshold. Citites are indexed starting at 0.

Each of the pairs, originCities[0] and destinationCities[0] for example, represents a route 
she wants to take. For each pair, determine whether there is a route between cities. The route
 does not have to be direct. See the explanation to Sample Case 1 relating to originCity equals 2 or 4 for examples.

For instance, consider an array originCities = [1,2,3] and destinationCities = [4,5,6]. The 
threshold value is 2. There are 6 total cities. To draw the map, first determine the divisors of all cities:

Origin Cities   Divisors    Destination Cities  Divisors
1   1   4   1,2,4
2   1,2 5   1,5
3   1,3 6   1,2,3,6
The threshold is 2, so we can eliminate cities 1 and 2. Their deivisors are not greater than 
the threshold. This leaves city 3 to check in the origins list. It has a divisor in common 
with city 6, and is greater than the threshold so there is a road between them. This is the
 only pair connected cities. Now that we have created a map, we can check her routes.

She wants to go from originCity[0] = 1 to desitinationCity[0] = 4 but there is no road. There 
is no road for her second route either, form city 2 to 5. There is only a road that matches her
 third route at index 2, from city 3 to 6. A true/fals array of her results would be paths = [0,0,1].

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
    vector<int> par, sz;
    dsu(int n): par(n), sz(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int root(int a) {
        if (a == par[a]) return a;
        return par[a] = root(par[a]);
    }
    void merge(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

vector<int> findReachable(int n, int g, vector<int> from, vector<int> to) {
    dsu d(n);
    for (int k = g + 1; k <= n; k++) {
        for (int x = 2 * k; x <= n; x += k) {
            d.merge(x - 1, x - k - 1);
        }
    }

    int m = from.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        ans.push_back(d.root(from[i] - 1) == d.root(to[i] - 1));
    }
    return ans;
}

signed main() {
    vector<int> from {10, 4, 3, 6};
    vector<int> to {3, 6, 2, 9};
    vector<int> reachable = findReachable(10, 1, from, to);
    for (int i = 0; i < 4; i++) {
        cout << "From " << from[i] << " to " << to[i] << ": ";
        cout << (reachable[i] ? "Possible" : "Not possible") << '\n';
    }
    return 0;
}