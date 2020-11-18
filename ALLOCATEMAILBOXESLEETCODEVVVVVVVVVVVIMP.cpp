class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        const int INF = 1e9 + 10;
        int n = houses.size();
        vector<vector<int>> dp(k + 1, vector<int>(n));
        vector<vector<int>> cost(n, vector<int>(n));

        sort(houses.begin(), houses.end());
        
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                cost[i][j] = 0;
                for(int u = i; u <= j; ++u) {
                    cost[i][j] += abs(houses[u] - houses[i + (j - i) / 2]);
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            dp[1][i] = cost[0][i];
        }

        for(int t = 2; t <= k; ++t) {
            for(int i = 0; i < n; ++i) {
                dp[t][i] = INF;
                for(int j = 0; j < i; ++j) {
                    dp[t][i] = min(dp[t][i], dp[t - 1][j] + cost[j + 1][i]);
                }
            }
        }
        return dp[k][n - 1];
    }
};