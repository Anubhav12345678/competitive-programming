// C++ program to find minimum swaps 
// required to group all 1's together 
#include <iostream> 
#include <limits.h> 

using namespace std; 

// Function to find minimum swaps 
// to group all 1's together 
int minSwaps(int arr[], int n) { 

int noOfOnes = 0; 

// find total number of all in the array 
for (int i = 0; i < n; i++) { 
	if (arr[i] == 1) 
	noOfOnes++; 
} 

// length of subarray to check for 
int x = noOfOnes; 

int maxOnes = INT_MIN; 

// array to store number of 1's upto 
// ith index 
int preCompute[n] = {0}; 

// calculate number of 1's upto ith 
// index and store in the array preCompute[] 
if (arr[0] == 1) 
	preCompute[0] = 1; 
for (int i = 1; i < n; i++) { 
	if (arr[i] == 1) { 
	preCompute[i] = preCompute[i - 1] + 1; 
	} else
	preCompute[i] = preCompute[i - 1]; 
} 

// using sliding window technique to find 
// max number of ones in subarray of length x 
for (int i = x - 1; i < n; i++) { 
	if (i == (x - 1)) 
	noOfOnes = preCompute[i]; 
	else
	noOfOnes = preCompute[i] - preCompute[i - x]; 
	
	if (maxOnes < noOfOnes) 
	maxOnes = noOfOnes; 
} 

// calculate number of zeros in subarray 
// of length x with maximum number of 1's 
int noOfZeroes = x - maxOnes; 

return noOfZeroes; 
} 

// Driver Code 
int main() { 
int a[] = {1, 0, 1, 0, 1}; 
int n = sizeof(a) / sizeof(a[0]); 
cout << minSwaps(a, n); 
return 0; 
} 
