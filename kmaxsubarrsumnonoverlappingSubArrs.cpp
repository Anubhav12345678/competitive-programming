// C++ program to find out k maximum 
// non-overlapping sub-array sums. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to compute k maximum 
// sub-array sums. 
void kmax(int arr[], int k, int n) { 

	// In each iteration it will give 
	// the ith maximum subarray sum. 
	for(int c = 0; c < k; c++){ 

		// Kadane's algorithm. 
		int max_so_far = numeric_limits<int>::min(); 
		int max_here = 0; 

		// compute starting and ending 
		// index of each of the sub-array. 
		int start = 0, end = 0, s = 0; 
		for(int i = 0; i < n; i++) 
		{ 
			max_here += arr[i]; 
			if (max_so_far < max_here) 
			{ 
				max_so_far = max_here; 
				start = s; 
				end = i; 
			} 
			if (max_here < 0) 
			{ 
				max_here = 0; 
				s = i + 1; 
			} 
		} 

		// Print out the result. 
		cout << "Maximum non-overlapping sub-array sum"
			<< (c + 1) << ": "<< max_so_far 
			<< ", starting index: " << start 
			<< ", ending index: " << end << "." << endl; 

		// Replace all elements of the maximum subarray 
		// by -infinity. Hence these places cannot form 
		// maximum sum subarray again. 
		for (int l = start; l <= end; l++) 
			arr[l] = numeric_limits<int>::min(); 
	} 
	cout << endl; 
} 

// Driver Program 
int main() 
{ 
	// Test case 1 
	int arr1[] = {4, 1, 1, -1, -3, 
				-5, 6, 2, -6, -2}; 
	int k1 = 3; 
	int n1 = sizeof(arr1) / sizeof(arr1[0]); 
	
	// Function calling 
	kmax(arr1, k1, n1); 

	// Test case 2 
	int arr2[] = {5, 1, 2, -6, 2, -1, 3, 1}; 
	int k2 = 2; 
	int n2 = sizeof(arr2)/sizeof(arr2[0]); 
	
	// Function calling 
	kmax(arr2, k2, n2); 
	
	return 0; 
} 
