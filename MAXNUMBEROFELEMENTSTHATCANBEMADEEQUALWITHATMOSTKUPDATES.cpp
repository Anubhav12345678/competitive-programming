// C++ program to find maximum elements that can 
// be made equal with k updates 
#include <bits/stdc++.h> 
using namespace std; 

// Function to calculate the maximum number of 
// equal elements possible with atmost K increment 
// of values .Here we have done sliding window 
// to determine that whether there are x number of 
// elements present which on increment will become 
// equal. The loop here will run in fashion like 
// 0...x-1, 1...x, 2...x+1, ...., n-x-1...n-1 
bool ElementsCalculationFunc(int pre[], int maxx[], 
							int x, int k, int n) 
{ 
	for (int i = 0, j = x; j <= n; j++, i++) { 

		// It can be explained with the reasoning 
		// that if for some x number of elements 
		// we can update the values then the 
		// increment to the segment (i to j having 
		// length -> x) so that all will be equal is 
		// (x*maxx[j]) this is the total sum of 
		// segment and (pre[j]-pre[i]) is present sum 
		// So difference of them should be less than k 
		// if yes, then that segment length(x) can be 
		// possible return true 
		if (x * maxx[j] - (pre[j] - pre[i]) <= k) 
			return true; 
	} 
	return false; 
} 

void MaxNumberOfElements(int a[], int n, int k) 
{ 
	// sort the array in ascending order 
	sort(a, a + n); 
	int pre[n + 1]; // prefix sum array 
	int maxx[n + 1]; // maximum value array 

	// Initializing the prefix array 
	// and maximum array 
	for (int i = 0; i <= n; ++i) { 
		pre[i] = 0; 
		maxx[i] = 0; 
	} 

	// set the first element of both 
	// array 
	maxx[0] = a[0]; 
	pre[0] = a[0]; 
	for (int i = 1; i < n; i++) { 

		// Calculating prefix sum of the array 
		pre[i] = pre[i - 1] + a[i]; 

		// Calculating max value upto that position 
		// in the array 
		maxx[i] = max(maxx[i - 1], a[i]); 
	} 

	// Binary seach applied for 
	// computation here 
	int l = 1, r = n, ans; 
	while (l < r) { 
		int mid = (l + r) / 2; 

		if (ElementsCalculationFunc(pre, maxx, 
							mid - 1, k, n)) { 
			ans = mid; 
			l = mid + 1; 
		} 
		else
			r = mid - 1; 
	} 

	// printing result 
	cout << ans << "\n"; 
} 

int main() 
{ 
	int arr[] = { 2, 4, 9 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 
	MaxNumberOfElements(arr, n, k); 
	return 0; 
} 
/*
Given an array and a value k. We have to find the maximum number of equal elements possible for the array so that we can 
increase the elements of the array by incrementing a total of at-most k.

Examples:

Input : array = { 2, 4, 9 }, k = 3
Output : 2
We are allowed to do at most three increments. We can make two elements 4 by increasing 2 by 2. Note that we can not make two
 elements 9 as converting 4 to 9 requires 5 increments.
*
/