// CPP program to find winner of game 
#include <iostream> 
using namespace std; 

int winner(int a[], int n, int k) 
{ 
	// if the number of steps is more then 
	// n-1, 
	if (k >= n - 1) 
		return n; 

	// initially the best is 0 and no of 
	// wins is 0. 
	int best = 0, times = 0; 

	// traverse through all the numbers 
	for (int i = 0; i < n; i++) { 

		// if the value of array is more 
		// then that of previous best 
		if (a[i] > best) { 

			// best is replaced by a[i] 
			best = a[i]; 

			// if not the first index 
			if (i) 
				times = 1; // no of wins is 1 now 
		} 

		else
			times += 1; // if it wins 

		// if any position has more then k wins 
		// then return 
		if (times >= k) 
			return best; 
	} 

	// Maximum element will be winner because 
	// we move smaller element at end and repeat 
	// the process. 
	return best; 
} 

// driver program to test the above function 
int main() 
{ 
	int a[] = { 2, 1, 3, 4, 5 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	int k = 2; 
	cout << winner(a, n, k); 
	return 0; 
} 
	