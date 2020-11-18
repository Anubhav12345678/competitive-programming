// A Dynamic Programming solution for subset sum problem 
#include <stdio.h> 

// Returns true if there is a subset of set[] with sun equal to given sum 
bool isSubsetSum(int set[], int n, int sum) 
{ 
	// The value of subset[i][j] will be true if there is a 
	// subset of set[0..j-1] with sum equal to i 
	bool subset[n+1][sum+1]; 

	// If sum is 0, then answer is true 
	for (int i = 0; i <= n; i++) 
	subset[i][0] = true; 

	// If sum is not 0 and set is empty, then answer is false 
	for (int i = 1; i <= sum; i++) 
	subset[0][i] = false; 

	// Fill the subset table in botton up manner 
	for (int i = 1; i <= n; i++) 
	{ 
	for (int j = 1; j <= sum; j++) 
	{ 
		if(j<set[i-1]) 
		subset[i][j] = subset[i-1][j]; 
		if (j >= set[i-1]) 
		subset[i][j] = subset[i-1][j] || 
								subset[i - 1][j-set[i-1]]; 
	} 
	} 

	/* // uncomment this code to print table 
	for (int i = 0; i <= n; i++) 
	{ 
	for (int j = 0; j <= sum; j++) 
		printf ("%4d", subset[i][j]); 
	printf("\n"); 
	}*/

	return subset[n][sum]; 
} 

// Driver program to test above function 
int main() 
{ 
int set[] = {3, 34, 4, 12, 5, 2}; 
int sum = 9; 
int n = sizeof(set)/sizeof(set[0]); 
if (isSubsetSum(set, n, sum) == true) 
	printf("Found a subset with given sum"); 
else
	printf("No subset with given sum"); 
return 0; 
} 
// This code is contributed by Arjun Tyagi. 
// another
// Returns true if there exists a subset 
// with given sum in arr[] 
#include <stdio.h> 
#include <stdbool.h> 

bool isSubsetSum(int arr[], int n, int sum) 
{ 
	// The value of subset[i%2][j] will be true 
	// if there exists a subset of sum j in 
	// arr[0, 1, ...., i-1] 
	bool subset[2][sum + 1]; 

	for (int i = 0; i <= n; i++) { 
		for (int j = 0; j <= sum; j++) { 

			// A subset with sum 0 is always possible 
			if (j == 0) 
				subset[i % 2][j] = true; 

			// If there exists no element no sum 
			// is possible 
			else if (i == 0) 
				subset[i % 2][j] = false; 
			else if (arr[i - 1] <= j) 
				subset[i % 2][j] = subset[(i + 1) % 2] 
			[j - arr[i - 1]] || subset[(i + 1) % 2][j]; 
			else
				subset[i % 2][j] = subset[(i + 1) % 2][j]; 
		} 
	} 

	return subset[n % 2][sum]; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 6, 2, 5 }; 
	int sum = 7; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	if (isSubsetSum(arr, n, sum) == true) 
		printf("There exists a subset with given sum"); 
	else
		printf("No subset exists with given sum"); 
	return 0; 
} 
