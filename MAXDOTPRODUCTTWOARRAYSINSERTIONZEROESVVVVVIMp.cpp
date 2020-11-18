// C++ program to find maximum dot product of two array 
#include<bits/stdc++.h> 
using namespace std; 
/*

Find Maximum dot product of two arrays with insertion of 0’s
Given two arrays of positive integers of size m and n where m > n. We need to maximize the dot product
 by inserting zeros in the second array but we cannot disturb the order of elements.

Examples:

Input : A[] = {2, 3 , 1, 7, 8} 
        B[] = {3, 6, 7}        
Output : 107
Explanation : We get maximum dot product after
inserting 0 at first and third positions in 
second array.
Maximum Dot Product : = A[i] * B[j] 
2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107

Input : A[] = {1, 2, 3, 6, 1, 4}
        B[] = {4, 5, 1}
Output : 46



*/
// Function compute Maximum Dot Product and 
// return it 
long long int MaxDotProduct(int A[], int B[], 
							int m, int n) 
{ 
	// Create 2D Matrix that stores dot product 
	// dp[i+1][j+1] stores product considering B[0..i] 
	// and A[0...j]. Note that since all m > n, we fill 
	// values in upper diagonal of dp[][] 
	long long int dp[n+1][m+1]; 
	memset(dp, 0, sizeof(dp)); 

	// Traverse through all elements of B[] 
	for (int i=1; i<=n; i++) 

		// Consider all values of A[] with indexes greater 
		// than or equal to i and compute dp[i][j] 
		for (int j=i; j<=m; j++) 

			// Two cases arise 
			// 1) Include A[j] 
			// 2) Exclude A[j] (insert 0 in B[]) 
			dp[i][j] = max((dp[i-1][j-1] + (A[j-1]*B[i-1])) , 
							dp[i][j-1]); 

	// return Maximum Dot Product 
	return dp[n][m] ; 
} 

// Driver program to test above function 
int main() 
{ 
	int A[] = { 2, 3 , 1, 7, 8 } ; 
	int B[] = { 3, 6, 7 } ; 
	int m = sizeof(A)/sizeof(A[0]); 
	int n = sizeof(B)/sizeof(B[0]); 
	cout << MaxDotProduct(A, B, m, n); 
	return 0; 
} 
