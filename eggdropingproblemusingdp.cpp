// A Dynamic Programming based C++ Program for the Egg Dropping Puzzle 
# include <stdio.h> 
# include <limits.h> 
//Since we need to minimize the number of trials in worst case, we take the maximum of two cases. We consider the max of above two cases for every floor and choose the floor which yields minimum number of trials.
/*
k ==> Number of floors
  n ==> Number of Eggs
  eggDrop(n, k) ==> Minimum number of trials needed to find the critical
                    floor in worst case.
  eggDrop(n, k) = 1 + min{max(eggDrop(n - 1, x - 1), eggDrop(n, k - x)): 
                 x in {1, 2, ..., k}}


*/
// this gives gauaranteed the highest floor from which the egg wint break on dropping
// A utility function to get maximum of two integers 
int max(int a, int b) { return (a > b)? a: b; } 

/* Function to get minimum number of trials needed in worst 
case with n eggs and k floors */
int eggDrop(int n, int k) 
{ 
	/* A 2D table where entery eggFloor[i][j] will represent minimum 
	number of trials needed for i eggs and j floors. */
	int eggFloor[n+1][k+1]; 
	int res; 
	int i, j, x; 

	// We need one trial for one floor and0 trials for 0 floors 
	for (i = 1; i <= n; i++) 
	{ 
		eggFloor[i][1] = 1; 
		eggFloor[i][0] = 0; 
	} 

	// We always need j trials for one egg and j floors. 
	for (j = 1; j <= k; j++) 
		eggFloor[1][j] = j; 

	// Fill rest of the entries in table using optimal substructure 
	// property 
	for (i = 2; i <= n; i++) 
	{ 
		for (j = 2; j <= k; j++) 
		{ 
			eggFloor[i][j] = INT_MAX; 
			for (x = 1; x <= j; x++) 
			{ 
				res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]); 
				if (res < eggFloor[i][j]) 
					eggFloor[i][j] = res; 
			} 
		} 
	} 

	// eggFloor[n][k] holds the result 
	return eggFloor[n][k]; 
} 

/* Driver program to test to pront printDups*/
int main() 
{ 
	int n = 2, k = 36; 
	printf ("nMinimum number of trials in worst case with %d eggs and "
			"%d floors is %d \n", n, k, eggDrop(n, k)); 
	return 0; 
} 
//the above is in o(n^2)
//below is in O(nlogk)
// C++ program to find minimum 
// number of trials in worst case. 
#include <bits/stdc++.h> 

using namespace std; 

// Find sum of binomial coefficients xCi 
// (where i varies from 1 to n). If the sum 
// becomes more than K 
int binomialCoeff(int x, int n, int k) 
{ 
	int sum = 0, term = 1; 
	for (int i = 1; i <= n && sum < k; ++i) { 
		term *= x - i + 1; 
		term /= i; 
		sum += term; 
	} 
	return sum; 
} 

// Do binary search to find minimum 
// number of trials in worst case. 
int minTrials(int n, int k) 
{ 
	// Initialize low and high as 1st 
	// and last floors 
	int low = 1, high = k; 

	// Do binary search, for every mid, 
	// find sum of binomial coefficients and 
	// check if the sum is greater than k or not. 
	while (low < high) { 
		int mid = (low + high) / 2; 
		if (binomialCoeff(mid, n, k) < k) 
			low = mid + 1; 
		else
			high = mid; 
	} 

	return low; 
} 

/* Drier program to test above function*/
int main() 
{ 
	cout << minTrials(2, 10); 
	return 0; 
} 
