// CPP program to make sorted array elements 
// distinct by incrementing elements and keeping 
// sum to minimum. 
#include <iostream> 
using namespace std; 

// To find minimum sum of unique elements. 
int minSum(int arr[], int n) 
{ 
	int sum = arr[0]; 

	for (int i = 1; i < n; i++) { 
		if (arr[i] == arr[i - 1]) {			 

			// While current element is same as 
			// previous or has become smaller 
			// than previous. 
			int j = i; 
			while (j < n && arr[j] <= arr[j - 1]) {		 
				arr[j] = arr[j] + 1; 
				j++; 
			} 
		} 
		sum = sum + arr[i]; 
	} 

	return sum; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2, 2, 3, 5, 6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << minSum(arr, n) << endl; 
	return 0; 
} 
/*
Given a sorted integer array. We need to make array elements distinct by 
increasing values and keeping array sum minimum possible. We need to print the minimum possible sum as output.

Examples:

Input : arr[] = { 2, 2, 3, 5, 6 } ; 
Output : 20
Explanation : We make the array as {2, 
3, 4, 5, 6}. Sum becomes 2 + 3 + 4 + 
5 + 6 = 20

Input : arr[] = { 20, 20 } ; 
Output : 41
Explanation : We make {20, 21}

Input :  arr[] = { 3, 4, 6, 8 };
Output : 21
Explanation : All elements are unique 
so result is sum of each elements.  
*/