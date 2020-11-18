// C++ program to find distinct elements 
// common to all rows of a matrix 
#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 

// function to individually sort 
// each row in increasing order 
void findAndPrintCommonElements(int mat[][MAX], int n) 
{ 
	unordered_set<int> us; 

	// map elements of first row 
	// into 'us' 
	for (int i=0; i<n; i++) 
		us.insert(mat[0][i]); 

	for (int i=1; i<n; i++) 
	{ 
		unordered_set<int> temp; 
		// mapping elements of current row 
		// in 'temp' 
		for (int j=0; j<n; j++) 
			temp.insert(mat[i][j]); 

		unordered_set<int>:: iterator itr; 

		// iterate through all the elements 
		// of 'us' 
		for (itr=us.begin(); itr!=us.end(); itr++) 

			// if an element of 'us' is not present 
			// into 'temp', then erase that element 
			// from 'us' 
			if (temp.find(*itr) == temp.end()) 
				us.erase(*itr); 

		// if size of 'us' becomes 0, 
		// then there are no common elements 
		if (us.size() == 0) 
			break; 
	} 

	// print the common elements 
	unordered_set<int>:: iterator itr; 
	for (itr=us.begin(); itr!=us.end(); itr++) 
		cout << *itr << " "; 
} 

// Driver program to test above 
int main() 
{ 
	int mat[][MAX] = { {2, 1, 4, 3}, 
					{1, 2, 3, 2}, 
					{3, 6, 2, 3}, 
					{5, 2, 5, 3} }; 
	int n = 4; 
	findAndPrintCommonElements(mat, n); 
	return 0; 
} 
