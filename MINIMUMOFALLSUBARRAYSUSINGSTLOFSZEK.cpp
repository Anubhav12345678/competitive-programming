// CPP program to pint Minimum of 
// all Subarrays using set in C++ STL 

#include <bits/stdc++.h> 
using namespace std; 

// Function to pint Minimum of 
// all Subarrays using set in C++ STL 
void minOfSubarrays(int arr[], int n, int k) 
{ 
	// Create a set of pairs 
	set<pair<int, int> > q; 

	// Create an iterator to the set 
	set<pair<int, int> >::iterator it; 

	// Insert the first k elements along 
	// with their indices into the set 
	for (int i = 0; i < k; i++) { 
		q.insert(pair<int, int>(arr[i], i)); 
	} 

	for (int j = 0; j < n - k + 1; j++) { 

		// Iterator to the beginning of the 
		// set since it has the minimum value 
		it = q.begin(); 

		// Print the minimum element 
		// of current window 
		cout << it->first << " "; 

		// Delete arr[j](Leftmost element of 
		// current window) from the set 
		q.erase(pair<int, int>(arr[j], j)); 

		// Insert next element 
		q.insert(pair<int, int>(arr[j + k], j + k)); 
	} 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 5, 3, 4, 1, 1 }; 

	int K = 3; 

	int n = sizeof(arr) / sizeof(arr[0]); 

	minOfSubarrays(arr, n, K); 

	return 0; 
} 
