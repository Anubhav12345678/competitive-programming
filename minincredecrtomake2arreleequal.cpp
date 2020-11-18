// CPP program to find minimum increment/decrement 
// operations to make array elements same. 
#include <bits/stdc++.h> 
using namespace std; 

int MinOperation(int a[], int b[], int n) 
{ 
	// sorting both arrays in 
	// ascending order 
	sort(a, a + n); 
	sort(b, b + n); 

	// variable to store the 
	// final result 
	int result = 0; 

	// After sorting both arrays 
	// Now each array is in non- 
	// decreasing order. Thus, 
	// we will now compare each 
	// element of the array and 
	// do the increment or decrement 
	// operation depending upon the 
	// value of array b[]. 
	for (int i = 0; i < n; ++i) { 
		if (a[i] > b[i]) 
			result = result + abs(a[i] - b[i]); 

		else if (a[i] < b[i]) 
			result = result + abs(a[i] - b[i]); 
	} 

	return result; 
} 

// Driver code 
int main() 
{ 
	int a[] = { 3, 1, 1 }; 
	int b[] = { 1, 2, 2 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	cout << MinOperation(a, b, n); 
	return 0; 
} 
