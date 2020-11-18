// CPP program to count GP subsequences of size 3. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns count of G.P. subseqeunces 
// with length 3 and common ratio r 
long long subsequences(int a[], int n, int r) 
{ 
	// hashing to maintain left and right array 
	// elements to the main count 
	unordered_map<int, int> left, right; 

	// stores the answer 
	long long ans = 0; 

	// traverse through the elements 
	for (int i = 0; i < n; i++) 
		right[a[i]]++; // keep the count in the hash 

	// traverse through all elements 
	// and find out the number of elements as k1*k2 
	for (int i = 0; i < n; i++) { 

		// keep the count of left and right elements 
		// left is a[i]/r and right a[i]*r 
		long long c1 = 0, c2 = 0; 

		// if the current element is divisible by k, 
		// count elements in left hash. 
		if (a[i] % r == 0) 
			c1 = left[a[i] / r]; 

		// decrease the count in right hash 
		right[a[i]]--; 

		// number of right elements 
		c2 = right[a[i] * r]; 

		// calculate the answer 
		ans += c1 * c2; 

		left[a[i]]++; // left count of a[i] 
	} 

	// returns answer 
	return ans; 
} 

// driver program 
int main() 
{ 
	int a[] = { 1, 2, 6, 2, 3, 6, 9, 18, 3, 9 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	int r = 3; 
	cout << subsequences(a, n, r); 
	return 0; 
} 
