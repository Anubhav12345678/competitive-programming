// CPP program to find Longest subarray 
// having average greater than or equal 
// to x. 
#include <bits/stdc++.h> 

using namespace std; 

// Comparison function used to sort preSum vector. 
bool compare(const pair<int, int>& a, const pair<int, int>& b) 
{ 
	if (a.first == b.first) 
		return a.second < b.second; 

	return a.first < b.first; 
} 

// Function to find index in preSum vector upto which 
// all prefix sum values are less than or equal to val. 
int findInd(vector<pair<int, int> >& preSum, int n, int val) 
{ 

	// Starting and ending index of search space. 
	int l = 0; 
	int h = n - 1; 
	int mid; 

	// To store required index value. 
	int ans = -1; 

	// If middle value is less than or equal to 
	// val then index can lie in mid+1..n 
	// else it lies in 0..mid-1. 
	while (l <= h) { 
		mid = (l + h) / 2; 
		if (preSum[mid].first <= val) { 
			ans = mid; 
			l = mid + 1; 
		} 
		else
			h = mid - 1; 
	} 

	return ans; 
} 

// Function to find Longest subarray having average 
// greater than or equal to x. 
int LongestSub(int arr[], int n, int x) 
{ 
	int i; 

	// Update array by subtracting x from 
	// each element. 
	for (i = 0; i < n; i++) 
		arr[i] -= x; 

	// Length of Longest subarray. 
	int maxlen = 0; 

	// Vector to store pair of prefix sum 
	// and corresponding ending index value. 
	vector<pair<int, int> > preSum; 

	// To store current value of prefix sum. 
	int sum = 0; 

	// To store minimum index value in range 
	// 0..i of preSum vector. 
	int minInd[n]; 

	// Insert values in preSum vector. 
	for (i = 0; i < n; i++) { 
		sum = sum + arr[i]; 
		preSum.push_back({ sum, i }); 
	} 

	sort(preSum.begin(), preSum.end(), compare); 

	// Update minInd array. 
	minInd[0] = preSum[0].second; 

	for (i = 1; i < n; i++) { 
		minInd[i] = min(minInd[i - 1], preSum[i].second); 
	} 

	sum = 0; 
	for (i = 0; i < n; i++) { 
		sum = sum + arr[i]; 

		// If sum is greater than or equal to 0, 
		// then answer is i+1. 
		if (sum >= 0) 
			maxlen = i + 1; 

		// If sum is less than 0, then find if 
		// there is a prefix array having sum 
		// that needs to be added to current sum to 
		// make its value greater than or equal to 0. 
		// If yes, then compare length of updated 
		// subarray with maximum length found so far. 
		else { 
			int ind = findInd(preSum, n, sum); 
			if (ind != -1 && minInd[ind] < i) 
				maxlen = max(maxlen, i - minInd[ind]); 
		} 
	} 

	return maxlen; 
} 

// Driver code. 
int main() 
{ 
	int arr[] = { -2, 1, 6, -3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	int x = 3; 

	cout << LongestSub(arr, n, x); 
	return 0; 
} 
