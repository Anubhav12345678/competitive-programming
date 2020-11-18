// CPP Program to find number of ways to 
// which numbers that are greater than 
// given number can be added to get sum. 
#include <bits/stdc++.h> 
#define MAX 100 
using namespace std; 

// Return number of ways to which numbers 
// that are greater than given number can 
// be added to get sum. 
int numberofways(int n, int m) 
{ 
	int dp[n+2][n+2]; 
	memset(dp, 0, sizeof(dp)); 

	dp[0][n + 1] = 1; 

	// Filling the table. k is for numbers 
	// greater than or equal that are allowed. 
	for (int k = n; k >= m; k--) { 

		// i is for sum 
		for (int i = 0; i <= n; i++) { 

			// initializing dp[i][k] to number 
			// ways to get sum using numbers 
			// greater than or equal k+1 
			dp[i][k] = dp[i][k + 1]; 

			// if i > k 
			if (i - k >= 0) 
				dp[i][k] = (dp[i][k] + dp[i - k][k]); 
		} 
	} 

	return dp[n][m]; 
} 

// Driver Program 
int main() 
{ 
	int n = 3, m = 1; 
	cout << numberofways(n, m) << endl; 
	return 0; 
} 
