// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Specify number of rows and columns 
#define M 4 
#define N 5 

// Returns common element in all rows of mat[M][N]. If there is no 
// common element, then -1 is returned 
int findCommon(int mat[M][N]) 
{ 
	// A hash map to store count of elements 
	unordered_map<int, int> cnt; 

	int i, j; 

	for (i = 0; i < M; i++) { 

		// Increment the count of first 
		// element of the row 
		cnt[mat[i][0]]++; 

		// Starting from the second element 
		// of the current row 
		for (j = 1; j < N; j++) { 

			// If current element is different from 
			// the previous element i.e. it is appearing 
			// for the first time in the current row 
			if (mat[i][j] != mat[i][j - 1]) 
				cnt[mat[i][j]]++; 
		} 
	} 

	// Find element having count equal to number of rows 
	for (auto ele : cnt) { 
		if (ele.second == M) 
			return ele.first; 
	} 

	// No such element found 
	return -1; 
} 

// Driver Code 
int main() 
{ 
	int mat[M][N] = { 
		{ 1, 2, 3, 4, 5 }, 
		{ 2, 4, 5, 8, 10 }, 
		{ 3, 5, 7, 9, 11 }, 
		{ 1, 3, 5, 7, 9 }, 
	}; 
	int result = findCommon(mat); 
	if (result == -1) 
		cout << "No common element"; 
	else
		cout << "Common element is " << result; 

	return 0; 
} 
