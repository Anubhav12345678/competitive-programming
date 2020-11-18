class Solution {
public://LEETCODE
     int anyNumberOfTransactions(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int i=0,j,k,l,n=prices.size(),ans=0;
        while(i<n-1)
        {
            while(i<n-1&&prices[i+1]<=prices[i]) i++;
            if(i==n-1) break;
            k=i++;
            while(i<n&&prices[i-1]<=prices[i]) i++;
            ans+=prices[i-1]-prices[k];
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.empty()) {
            return 0;
        }
        
        if (k >= prices.size()) {
            return anyNumberOfTransactions(prices);
        }
        
        // Transactions to day
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        
        /* 
         Max profit for i transactions on day j
         is max of:
         1. Max profit with i transactions on day j (i.e no transaction on this day), and
         2. prices[j] - prices[l] + max profit with i-1 transactions on day l (i.e transaction today having 
            bought on some day 'l' + the max profit with one less transaction on that day l)
            
            l is some day < j where the difference of prices[j] and prices[l] is the maximum
         */
        
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j < prices.size(); ++j) {
                
                int maxDiff = 0;
                int diff = 0;
                for (int l = 0; l < j; ++l) {
                    diff = prices[j] - prices[l];
                    maxDiff = max(maxDiff, diff + dp[i-1][l]);
                }
                
                dp[i][j] = max(dp[i][j-1], maxDiff);
            }
        }
        
        return dp[k][prices.size()-1];
    }
};





















// C++ program to find out maximum profit by 
// buying and selling a share atmost k times 
// given stock price of n days 
#include <climits> 
#include <iostream> 
using namespace std; 

// Function to find out maximum profit by buying 
// & selling a share atmost k times given stock 
// price of n days 
int maxProfit(int price[], int n, int k) 
{ 
	// table to store results of subproblems 
	// profit[t][i] stores maximum profit using 
	// atmost t transactions up to day i (including 
	// day i) 
	int profit[k + 1][n + 1]; 

	// For day 0, you can't earn money 
	// irrespective of how many times you trade 
	for (int i = 0; i <= k; i++) 
		profit[i][0] = 0; 

	// profit is 0 if we don't do any transation 
	// (i.e. k =0) 
	for (int j = 0; j <= n; j++) 
		profit[0][j] = 0; 

	// fill the table in bottom-up fashion 
	for (int i = 1; i <= k; i++) { 
		for (int j = 1; j < n; j++) { 
			int max_so_far = INT_MIN; 

			for (int m = 0; m < j; m++) 
				max_so_far = max(max_so_far, 
								price[j] - price[m] + profit[i - 1][m]); 

			profit[i][j] = max(profit[i][j - 1], max_so_far); 
		} 
	} 

	return profit[k][n - 1]; 
} 

// Driver code 
int main() 
{ 
	int k = 2; 
	int price[] = { 10, 22, 5, 75, 65, 80 }; 
	int n = sizeof(price) / sizeof(price[0]); 

	cout << "Maximum profit is: "
		<< maxProfit(price, n, k); 

	return 0; 
} 


//new and better method
class Solution {
public:
     int anyNumberOfTransactions(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i-1] > 0) {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        
        return maxProfit;
    }
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.empty()) {
            return 0;
        }
        
        if (k >= prices.size()) {
            return anyNumberOfTransactions(prices);
        }
        
        // Transactions to day
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        
        /* 
         Max profit for i transactions on day j
         is max of:
         1. Max profit with i transactions on day j (i.e no transaction on this day), and
         2. prices[j] - prices[l] + max profit with i-1 transactions on day l (i.e transaction today having 
            bought on some day 'l' + the max profit with one less transaction on that day l)
            
            l is some day < j where the difference of prices[j] and prices[l] is the maximum
         */
        
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j < prices.size(); ++j) {
                
                int maxDiff = 0;
                int diff = 0;
                for (int l = 0; l < j; ++l) {
                    diff = prices[j] - prices[l];
                    maxDiff = max(maxDiff, diff + dp[i-1][l]);
                }
                
                dp[i][j] = max(dp[i][j-1], maxDiff);
            }
        }
        
        return dp[k][prices.size()-1];
    }
};