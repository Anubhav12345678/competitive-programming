// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the length of 
// required maximum subarray 
int max_subarray_len(int arr[], 
					int N, int K) 
{ 
	// Initialize answer to 0 
	int ans = 0; 

	// Generate all subarrays having i as the 
	// starting index and j as the ending index 
	for (int i = 0; i < N; i++) { 

		// Stores frequency of subarray elements 
		unordered_map<int, int> map1; 

		// Stores subarray elements with 
		// respective frequencies 
		unordered_map<int, int> map2; 

		for (int j = i; j < N; j++) { 

			// Stores previous 
			// frequency of arr[j] 
			int prev_freq; 

			// If arr[j] hasn't 
			// occurred previously 
			if (map1.find(arr[j]) 
				== map1.end()) { 

				// Set frequency as 0 
				prev_freq = 0; 
			} 

			else { 

				// Update previous frequency 
				prev_freq = map1[arr[j]]; 
			} 

			// Increasing frequency 
			// of arr[j] by 1 
			map1[arr[j]]++; 

			// If frequency is stored 
			if (map2.find(prev_freq) 
				!= map2.end()) { 

				// If previous frequency is 1 
				if (map2[prev_freq] == 1) { 

					// Rove previous frequency 
					map2.erase(prev_freq); 
				} 
				else { 

					// Decrease previous frequency 
					map2[prev_freq]--; 
				} 
			} 

			int new_freq = prev_freq + 1; 

			// Increment new frequncy 
			map2[new_freq]++; 

			// If updated frequency is equal to K 
			if (map2.size() == 1 
				&& (new_freq) == K) { 
				ans = max( 
					ans, j - i + 1); 
			} 
		} 
	} 

	// Return the maximum size 
	// of the subarray 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	// Given array arr[] 
	int arr[] = { 3, 5, 2, 2, 4, 
				6, 4, 6, 5 }; 

	int K = 2; 

	// Size of Array 
	int N = sizeof(arr) 
			/ sizeof(arr[0]); 

	// Function Call 
	cout << max_subarray_len( 
		arr, N, K); 

	return 0; 
} 
/*

Given an array arr[] consisting of N integers and an integer K, the task is to find the length of the longest subarray such that each element occurs K times.

Examples:

Input: arr[] = {3, 5, 2, 2, 4, 6, 4, 6, 5}, K = 2
Output: 8
Explanation: The subarray: {5, 2, 2, 4, 6, 4, 6, 5} of length 8 has frequency of every element as 2.

Input: arr[] = {5, 5, 5, 5}, K = 3
Output: 3
Explanation: The subarray: {5, 5, 5} of length 3 has frequency of every element as 3.


*/