// C++ program to count subsequences of a 
// string divisible by n. 
#include<bits/stdc++.h> 
using namespace std; 

// Returns count of subsequences of str 
// divisible by n. 
int countDivisibleSubseq(string str, int n) 
{ 
	int len = str.length(); 

	// division by n can leave only n remainder 
	// [0..n-1]. dp[i][j] indicates number of 
	// subsequences in string [0..i] which leaves 
	// remainder j after division by n. 
	int dp[len][n]; 
	memset(dp, 0, sizeof(dp)); 

	// Filling value for first digit in str 
	dp[0][(str[0]-'0')%n]++; 

	for (int i=1; i<len; i++) 
	{ 
		// start a new subsequence with index i 
		dp[i][(str[i]-'0')%n]++; 

		for (int j=0; j<n; j++) 
		{ 
			// exclude i'th character from all the 
			// current subsequences of string [0...i-1] 
			dp[i][j] += dp[i-1][j]; 

			// include i'th character in all the current 
			// subsequences of string [0...i-1] 
			dp[i][(j*10 + (str[i]-'0'))%n] += dp[i-1][j]; 
		} 
	} 

	return dp[len-1][0]; 
} 

// Driver code 
int main() 
{ 
	string str = "1234"; 
	int n = 4; 
	cout << countDivisibleSubseq(str, n); 
	return 0; 
} 
