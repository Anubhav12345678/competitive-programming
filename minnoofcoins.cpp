//LEETCODEVVVVVVVVVVVVVIMP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int i,j,k,l,n=coins.size();
        int cnt=0;
        sort(coins.begin(),coins.end());
        i=n-1;
        int ans=0;
        int dp[n+1][amount+1];
        // dp[0][0]=1;
        // for(i=1;i<=n;i++)
        //     dp[i][0]=1;
        for(i=0;i<=amount;i++)
            dp[0][i]=INT_MAX-1;
         for(i=1;i<=n;i++)
            dp[i][0]=0;
        for(i=1;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[1][i] = i/coins[0];
            else
                dp[1][i] = INT_MAX-1;
            
        }
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=amount;j++)
            {
                if(j>=coins[i-1])
                    dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        // return dp[n][amount];
        if(dp[n][amount]==INT_MAX-1)
            return -1;
        return dp[n][amount];
        
    }
};



















// C++ program to find minimum number of denominations 
#include <bits/stdc++.h> 
using namespace std; 

// All denominations of Indian Currency 
int deno[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 }; 
int n = sizeof(deno) / sizeof(deno[0]); 

void findMin(int V) 
{ 
	// Initialize result 
	vector<int> ans; 

	// Traverse through all denomination 
	for (int i = n - 1; i >= 0; i--) { 
		// Find denominations 
		while (V >= deno[i]) { 
			V -= deno[i]; 
			ans.push_back(deno[i]); 
		} 
	} 

	// Print result 
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << " "; 
} 

// Driver program 
int main() 
{ 
	int n = 93; 
	cout << "Following is minimal number of change for " << n << ": "; 
	findMin(n); 
	return 0; 
} 
