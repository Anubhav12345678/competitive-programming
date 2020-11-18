// C++ program to print the number of subarrays such 
// that all elements are greater than K 
#include <bits/stdc++.h> 
using namespace std; 

// Function to count number of subarrays 
int countSubarrays(int a[], int n, int x) 
{ 
	int count = 0; 

	int number = 0; 

	// Iterate in the array 
	for (int i = 0; i < n; i++) { 

		// check if array element 
		// greater then X or not 
		if (a[i] > x) { 
			count += 1; 
		} 
		else { 

			number += (count) * (count + 1) / 2; 
			count = 0; 
		} 
	} 

	// After iteration complete 
	// check for the last set of subarrays 
	if (count) 
		number += (count) * (count + 1) / 2; 

	return number; 
} 

// Driver Code 
int main() 
{ 
	int a[] = { 3, 4, 5, 6, 7, 2, 10, 11 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	int k = 5; 

	cout << countSubarrays(a, n, k); 

	return 0; 
} 
