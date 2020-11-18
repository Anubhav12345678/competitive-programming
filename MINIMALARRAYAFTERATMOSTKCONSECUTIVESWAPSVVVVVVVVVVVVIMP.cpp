// C++ program to find lexicographically minimum 
// value after k swaps. 
#include<bits/stdc++.h> 
using namespace std ; 

// Modifies arr[0..n-1] to lexicographically smallest 
// with k swaps. 
void minimizeWithKSwaps(int arr[], int n, int k) 
{ 
	for (int i = 0; i<n-1 && k>0; ++i) 
	{ 
		// Set the position where we want 
		// to put the smallest integer 
		int pos = i; 
		for (int j = i+1; j<n ; ++j) 
		{ 
			// If we exceed the Max swaps 
			// then terminate the loop 
			if (j-i > k) 
				break; 

			// Find the minimum value from i+1 to 
			// max k or n 
			if (arr[j] < arr[pos]) 
				pos = j; 
		} 

		// Swap the elements from Minimum position 
		// we found till now to the i index 
		for (int j = pos; j>i; --j) 
			swap(arr[j], arr[j-1]); 

		// Set the final value after swapping pos-i 
		// elements 
		k -= pos-i; 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = {7, 6, 9, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int k = 3; 

	minimizeWithKSwaps(arr, n, k); 

	//Print the final Array 
	for (int i=0; i<n; ++i) 
		cout << arr[i] <<" "; 
} 
