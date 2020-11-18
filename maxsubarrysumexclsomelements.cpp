// C++ Program to find max subarray 
// sum excluding some elements 
#include <bits/stdc++.h> 
using namespace std; 
// (O((n+m)*log(m)) approach)
// Utility function for findMaxSubarraySum() 
// with the following parameters 
// A => Array A, 
// B => Array B, 
// n => Number of elements in Array A, 
// m => Number of elements in Array B 
int findMaxSubarraySumUtil(int A[], int B[], 
						int n, int m) 
{ 

	// set max_so_far to INT_MIN 
	int max_so_far = INT_MIN, curr_max = 0; 

	for (int i = 0; i < n; i++) { 

		// if the element is present in B, 
		// set current max to 0 and move to 
		// the next element 
		if (binary_search(B, B + m, A[i])) { 
			curr_max = 0; 
			continue; 
		} 

		// Proceed as in Kadane's Algorithm 
		curr_max = max(A[i], curr_max + A[i]); 
		max_so_far = max(max_so_far, curr_max); 
	} 
	return max_so_far; 
} 

// Wrapper for findMaxSubarraySumUtil() 
void findMaxSubarraySum(int A[], int B[], 
						int n, int m) 
{ 
	// sort array B to apply Binary Search 
	sort(B, B + m); 

	int maxSubarraySum = findMaxSubarraySumUtil(A, B, 
												n, m); 

	// This case will occour when all elements 
	// of A are present in B, thus no subarray 
	// can be formed 
	if (maxSubarraySum == INT_MIN) { 
		cout << "Maximum subarray sum cant be found"
			<< endl; 
	} 
	else { 
		cout << "The Maximum subarray sum = "
			<< maxSubarraySum << endl; 
	} 
} 

// Driver Code 
int main() 
{ 
	int A[] = { 3, 4, 5, -4, 6 }; 
	int B[] = { 1, 8, 5 }; 

	int n = sizeof(A) / sizeof(A[0]); 
	int m = sizeof(B) / sizeof(B[0]); 

	// Calling fucntion 
	findMaxSubarraySum(A, B, n, m); 
	return 0; 
} 
