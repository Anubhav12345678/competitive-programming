// CPP program to make a permutation of numbers 
// from 1 to n using minimum changes. 
#include <bits/stdc++.h> 
using namespace std; 

void makePermutation(int a[], int n) 
{ 
	// Store counts of all elements. 
	unordered_map<int, int> count; 
	for (int i = 0; i < n; i++) 
		count[a[i]]++; 

	int next_missing = 1; 
	for (int i = 0; i < n; i++) { 
		if (count[a[i]] != 1 || a[i] > n || a[i] < 1) { 
			count[a[i]]--; 

			// Find next missing element to put 
			// in place of current element. 
			while (count.find(next_missing) != count.end()) 
				next_missing++; 

			// Replace with next missing and insert the 
			// missing element in hash. 
			a[i] = next_missing; 
			count[next_missing] = 1; 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	int A[] = { 2, 2, 3, 3 }; 
	int n = sizeof(A) / sizeof(A[0]); 
	makePermutation(A, n); 
	for (int i = 0; i < n; i++) 
		cout << A[i] << " "; 
	return 0; 
} 
