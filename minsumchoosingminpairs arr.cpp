// CPP program to minimize the cost 
// of array minimization 
#include <bits/stdc++.h> 
using namespace std; 

// Returns minimum possible sum in 
// array B[] 
int minSum(int A[], int n) 
{ 
	int min_val = *min_element(A, A+n); 
	return (min_val * (n-1)); 
} 

// driver function 
int main() 
{ 
	int A[] = { 3, 6, 2, 8, 7, 5}; 
	int n = sizeof(A)/ sizeof (A[0]); 
	cout << minSum(A, n); 
	return 0; 
} 
