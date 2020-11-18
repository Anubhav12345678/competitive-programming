// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 

// Function to return the maximum length 
// of the sub-array such that the 
// absolute difference between every two 
// consecutive elements is either 1 or 0 
int getMaxLength(int arr[],int n) 
{ 
	int l = n; 
	int i = 0, maxlen = 0; 
	while (i < l) 
	{ 
		int j = i; 
		while (i+1 < l && 
			(abs(arr[i] - arr[i + 1]) == 1 || 
			abs(arr[i] - arr[i + 1]) == 0)) 
		{ 
			i++; 
		} 

			// Length of the valid sub-array currently 
			// under consideration 
			int currLen = i - j + 1; 

			// Update the maximum length 
			if (maxlen < currLen) 
				maxlen = currLen; 

			if (j == i) 
				i++; 
	} 

	// Any valid sub-array cannot be of length 1 
	//maxlen = (maxlen == 1) ? 0 : maxlen; 

	// Return the maximum possible length 
	return maxlen; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << getMaxLength(arr, n); 
} 

// This code is contributed by 
// Surendra_Gangwar 
