class Solution {
public:
    bool check(const string& t, const string& s) {
        int m = t.size(), n = s.size();
        if (m != n - 1) return false;
        int cnt = 0;
        for (int i = 0, j = 0; i < m && j < n; ) {
            if (t[i] == s[j]) {
                ++i;
                ++j;
            } else {
                if (cnt > 0) return false;
                ++cnt;
                ++j;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& s) {
        sort(s.begin(), s.end(),
            [](const string& s, const string& t) {
                return s.size() < t.size();
            });
        int n = s.size();
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (check(s[j], s[i])) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ret = *max_element(dp.begin(), dp.end());
        return ret;
    }
};