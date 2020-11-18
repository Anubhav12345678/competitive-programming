// C++ implementation of the above approach 
/*
Given an array arr[] and an integer K. The task is to divide the array into K parts
 ( subarray ) such that the sum of the values of all subarray is minimum.

The value of every subarray is defined as:

Take the maximum from that subarray.
Subtract each element of the subarray with the maximum.
Take the sum of all the values after subtraction.
The task is to minimize the sum of the values after dividing the array into K parts.

Examples:

Input: arr[] = { 2, 9, 5, 4, 8, 3, 6 }, K = 2
Output: 19
Explanation:
The two groups are : {2} with max = 2 and {9, 5, 4, 8, 3, 6} with max=9,
sum of difference of first group = 2 – 2 = 0,
sum of difference of second group = (9-9) + (9-5) + (9-4) + (9-8) + (9-3) + (9-6) = 19
*/
#include <bits/stdc++.h> 
using namespace std; 

// Function to divide an array into k 
// parts such that the sum of difference 
// of every element with the maximum element 
// of that part is minimum 
int divideArray(int arr[], int n, int k) 
{ 
	// Dp to store the values 
	int dp[500][500] = { 0 }; 

	k -= 1; 

	// Fill up the dp table 
	for (int i = n - 1; i >= 0; i--) { 
		for (int j = 0; j <= k; j++) { 
			// Intitilize maximum value 
			dp[i][j] = INT_MAX; 

			// Max element and the sum 
			int max_ = -1, sum = 0; 

			// Run a loop from i to n 
			for (int l = i; l < n; l++) { 
				// Find the maximum number 
				// from i to l and the sum 
				// from i to l 
				max_ = max(max_, arr[l]); 
				sum += arr[l]; 

				// Find the sum of difference 
				// of every element with the 
				// maximum element 
				int diff = (l - i + 1) * max_ - sum; 

				// If the array can be divided 
				if (j > 0) 
					dp[i][j] 
						= min(dp[i][j], 
							diff + dp[l + 1][j - 1]); 
				else
					dp[i][j] = diff; 
			} 
		} 
	} 

	// Returns the minimum sum 
	// in K parts 
	return dp[0][k]; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2, 9, 5, 4, 8, 3, 6 }; 
	int n = sizeof(arr) / sizeof(int); 
	int k = 2; 

	cout << divideArray(arr, n, k) << "\n"; 

	return 0; 
} 
