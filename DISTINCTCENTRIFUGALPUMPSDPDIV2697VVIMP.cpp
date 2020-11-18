#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int maxn = 3e5 + 1;
/*
There are n beautiful skyscrapers in New York, the height of the i-th one is hi. Today some villains have set on fire 
first n−1 of them, and now the only safety building is n-th skyscraper.

Let's call a jump from i-th skyscraper to j-th (i<j) discrete, if all skyscrapers between are strictly lower or higher
 than both of them. Formally, jump is discrete, if i<j and one of the following conditions satisfied:

i+1=j
max(hi+1,…,hj−1)<min(hi,hj)
max(hi,hj)<min(hi+1,…,hj−1).
At the moment, Vasya is staying on the first skyscraper and wants to live a little longer, so his goal is to reach n-th 
skyscraper with minimal count of discrete jumps. Help him with calcualting this number.


*/
int h[maxn], dp[maxn], lge[maxn], lle[maxn], rge[maxn], rle[maxn];
vector<int>jumps[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        dp[i] = INF;
    }
    dp[0] = 0;
    vector<pair<int, int> >st;
    for (int i = 0; i < n; i++) { // the nearest greater from the left
        while (!st.empty() && st.back().first < h[i]) {
            st.pop_back();
        }
        if (st.empty()) lge[i] = -1;
        else lge[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = 0; i < n; i++) { // the nearest less from the left
        while (!st.empty() && st.back().first > h[i]) {
            st.pop_back();
        }
        if (st.empty()) lle[i] = -1;
        else lle[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) { // the nearest greater from the right
        while (!st.empty() && st.back().first < h[i]) {
            st.pop_back();
        }
        if (st.empty()) rge[i] = -1;
        else rge[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) { // the nearest less from the right
        while (!st.empty() && st.back().first > h[i]) {
            st.pop_back();
        }
        if (st.empty()) rle[i] = -1;
        else rle[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = 0; i < n; i++) {
        if (rle[i] != -1) jumps[i].push_back(rle[i]);
        if (rge[i] != -1) jumps[i].push_back(rge[i]);
        if (lle[i] != -1) jumps[lle[i]].push_back(i);
        if (lge[i] != -1) jumps[lge[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        for (int to : jumps[i]) {
            dp[to] = min(dp[to], dp[i] + 1);
        }
    }
    cout << dp[n - 1];
    return 0;
}