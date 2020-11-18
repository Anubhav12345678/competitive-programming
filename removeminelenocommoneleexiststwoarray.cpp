// CPP program to find minimum element 
// to remove so no common element 
// exist in both array 
#include <bits/stdc++.h> 
using namespace std; 

// To find no elements to remove 
// so no common element exist 
int minRemove(int a[], int b[], int n, int m) 
{ 
	// To store count of array element 
	unordered_map<int, int> countA, countB; 

	// Count elements of a 
	for (int i = 0; i < n; i++) 
		countA[a[i]]++; 

	// Count elements of b 
	for (int i = 0; i < m; i++) 
		countB[b[i]]++; 

	// Traverse through all common element, and 
	// pick minimum occurrence from two arrays 
	int res = 0; 
	for (auto x : countA) 
		if (countB.find(x.first) != countB.end()) 
			res += min(x.second, countB[x.first]); 

	// To return count of minimum elements 
	return res; 
} 

// Driver program to test minRemove() 
int main() 
{ 
	int a[] = { 1, 2, 3, 4 }; 
	int b[] = { 2, 3, 4, 5, 8 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	int m = sizeof(b) / sizeof(b[0]); 

	cout << minRemove(a, b, n, m); 

	return 0; 
} 
