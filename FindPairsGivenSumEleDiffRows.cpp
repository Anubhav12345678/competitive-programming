// C++ program to find a pair with given sum such that 
// every element of pair is in different rows. 
#include<bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 

// Function to find pair for given sum in matrix 
// mat[][] --> given matrix 
// n --> order of matrix 
// sum --> given sum for which we need to find pair 
void pairSum(int mat[][MAX], int n, int sum) 
{ 
	// First sort all the rows in ascending order 
	for (int i=0; i<n; i++) 
		sort(mat[i], mat[i]+n); 

	// Select i'th row and find pair for element in i'th 
	// row in j'th row whose summation is equal to given sum 
	for (int i=0; i<n-1; i++) 
	{ 
		for (int j=i+1; j<n; j++) 
		{ 
			int left = 0, right = n-1; 
			while (left<n && right>=0) 
			{ 
				if ((mat[i][left] + mat[j][right]) == sum) 
				{ 
					cout << "(" << mat[i][left] 
						<< ", "<< mat[j][right] << "), "; 
					left++; 
					right--; 
				} 
				else
				{ 
					if ((mat[i][left] + mat[j][right]) < sum) 
						left++; 
					else
						right--; 
				} 
			} 
		} 
	} 
} 

// Driver program to run the case 
int main() 
{ 
	int n = 4, sum = 11; 
	int mat[][MAX] = {{1, 3, 2, 4}, 
					{5, 8, 7, 6}, 
					{9, 10, 13, 11}, 
					{12, 0, 14, 15}}; 
	pairSum(mat, n, sum); 
	return 0; 
} 
