// C++ implementation of the approach 
#include <bits/stdc++.h> 
#define MAX 100000 
#define bitscount 32 
using namespace std; 
/*
Given an array arr[] of N and Q queries consisting of a range [L, R].
 the task is to find the bit-wise AND of all the elements of in that index range.

Examples:

Input: arr[] = {1, 3, 1, 2, 3, 4}, q[] = {{0, 1}, {3, 5}}
Output:
1
0
1 AND 3 = 1
2 AND 3 AND 4 = 0

Input: arr[] = {1, 2, 3, 4, 5}, q[] = {{0, 4}, {1, 3}}
Output:
0
0




*/
// Array to store bit-wise 
// prefix count 
int prefix_count[bitscount][MAX]; 

// Function to find the prefix sum 
void findPrefixCount(int arr[], int n) 
{ 

	// Loop for each bit 
	for (int i = 0; i < bitscount; i++) { 

		// Loop to find prefix count 
		prefix_count[i][0] = ((arr[0] >> i) & 1); 
		for (int j = 1; j < n; j++) { 
			prefix_count[i][j] = ((arr[j] >> i) & 1); 
			prefix_count[i][j] += prefix_count[i][j - 1]; 
		} 
	} 
} 

// Function to answer query 
int rangeAnd(int l, int r) 
{ 

	// To store the answer 
	int ans = 0; 

	// Loop for each bit 
	for (int i = 0; i < bitscount; i++) { 
		// To store the number of variables 
		// with ith bit set 
		int x; 
		if (l == 0) 
			x = prefix_count[i][r]; 
		else
			x = prefix_count[i][r] 
				- prefix_count[i][l - 1]; 

		// Condition for ith bit 
		// of answer to be set 
		if (x == r - l + 1) 
			ans = (ans | (1 << i)); 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 7, 5, 3, 5, 2, 3 }; 
	int n = sizeof(arr) / sizeof(int); 

	findPrefixCount(arr, n); 

	int queries[][2] = { { 1, 3 }, { 4, 5 } }; 
	int q = sizeof(queries) / sizeof(queries[0]); 

	for (int i = 0; i < q; i++) 
		cout << rangeAnd(queries[i][0], 
						queries[i][1]) 
			<< endl; 

	return 0; 
} 
