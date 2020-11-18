// C++ implementation to find the 
// maximum sum of the array by 
// multiplying the prefix and suffix 
// of the array by -1 

#include <bits/stdc++.h> 

using namespace std; 

// Kadane's algorithm to find 
// the maximum subarray sum 
int maxSubArraySum(int a[], int size) 
{ 
	int max_so_far = INT_MIN, 
		max_ending_here = 0; 
	
	// Loop to find the maximum subarray 
	// array sum in the given array 
	for (int i = 0; i < size; i++) { 
		max_ending_here = 
			max_ending_here + a[i]; 
		if (max_ending_here < 0) 
			max_ending_here = 0; 
		if (max_so_far < max_ending_here) 
			max_so_far = max_ending_here; 
	} 
	return max_so_far; 
} 

// Function to find the maximum 
// sum of the array by multiplying 
// the prefix and suffix by -1 
int maxSum(int a[], int n) 
{ 
	
	// Total intital sum 
	int S = 0; 
	
	// Loop to find the maximum 
	// sum of the array 
	for (int i = 0; i < n; i++) 
		S += a[i]; 
	int X = maxSubArraySum(a, n); 
	
	// Maximum value 
	return 2 * X - S; 
} 

// Driver Code 
int main() 
{ 
	int a[] = { -1, -2, -3 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	int max_sum = maxSum(a, n); 
	cout << max_sum; 
	return 0; 
} 
