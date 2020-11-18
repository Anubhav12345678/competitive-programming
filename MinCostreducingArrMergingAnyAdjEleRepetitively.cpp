// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the total minimum 
// cost of merging two consecutive numbers 
int mergeTwoNumbers(vector<int>& numbers) 
{ 
	int len, i, j, k; 

	// Find the size of numbers[] 
	int n = numbers.size(); 

	// If array is empty, return 0 
	if (numbers.size() == 0) { 
		return 0; 
	} 

	// To store the prefix Sum of 
	// numbers array numbers[] 
	vector<int> prefixSum(n + 1, 0); 

	// Traverse numbers[] to find the 
	// prefix sum 
	for (int i = 1; i <= n; i++) { 
		prefixSum[i] = prefixSum[i - 1] 
					+ numbers[i - 1]; 
	} 

	// dp table to memoised the value 
	vector<vector<int> > dp( 
		n + 1, 
		vector<int>(n + 1)); 

	// For single numbers cost is zero 
	for (int i = 1; i <= n; i++) { 
		dp[i][i] = 0; 
	} 

	// Iterate for length >= 1 
	for (len = 2; len <= n; len++) { 

		for (i = 1; i <= n - len + 1; i++) { 
			j = i + len - 1; 

			// Find sum in range [i..j] 
			int sum = prefixSum[j] 
					- prefixSum[i - 1]; 

			// Initialise dp[i][j] to INT_MAX 
			dp[i][j] = INT_MAX; 

			// Iterate for all possible 
			// K to find the minimum cost 
			for (k = i; k < j; k++) { 

				// Update the minimum sum 
				dp[i][j] 
					= min(dp[i][j], 
						dp[i][k] 
							+ dp[k + 1][j] 
							+ sum); 
			} 
		} 
	} 

	// Return the final minimum cost 
	return dp[1][n]; 
} 

// Driver Code 
int main() 
{ 
	// Given set of numbers 
	vector<int> arr1 = { 6, 4, 4, 6 }; 

	// Function Call 
	cout << mergeTwoNumbers(arr1) 
		<< endl; 
	return 0; 
} 
