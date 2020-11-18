// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the minimum cost 
int minCost(string str, int K) 
{ 
	int n = str.length(); 

	// Initialize result 
	int res = 999999999, count = 0, a, b; 

	// To store the frequency of characters 
	// of the string 
	int cnt[27]; 

	// Initialize array with 0 
	memset(cnt, 0, sizeof(cnt)); 

	// Update the frequencies of the 
	// characters of the string 
	for (int i = 0; i < n; i++) 
		cnt[str[i] - 'a' + 1]++; 

	// Loop to check all windows from a-z 
	// where window size is K 
	for (int i = 1; i < (26 - K + 1); i++) { 

		// Starting index of window 
		a = i; 

		// Ending index of window 
		b = i + K; 
		count = 0; 
		for (int j = 1; j <= 26; j++) { 

			// Check if the string contains character 
			if (cnt[j] > 0) { 

				// Check if the character is on left side of window 
				// find the cost of modification for character 
				// add value to count 
				// calculate nearest distance of modification 
				if (j >= a && j >= b) 
					count = count + (min(j - b, 25 - j + a + 1)) * cnt[j]; 

				// Check if the character is on right side of window 
				// find the cost of modification for character 
				// add value to count 
				// calculate nearest distance of modification 
				else if (j <= a && j <= b) 
					count = count + (min(a - j, 25 + j - b + 1)) * cnt[j]; 
			} 
		} 

		// Find the minimum of all costs 
		// for modifying the string 
		res = min(res, count); 
	} 

	// Loop to check all windows 
	// Here window contains characters 
	// before z and after z of window size K 
	for (int i = 26 - K + 1; i <= 26; i++) { 

		// Starting index of window 
		a = i; 

		// Ending index of window 
		b = (i + K) % 26; 
		count = 0; 

		for (int j = 1; j <= 26; j++) { 

			// Check if the string contains character 
			if (cnt[j] > 0) { 

				// If characters are outside window 
				// find the cost for modifying character 
				// add value to count 
				if (j >= b and j <= a) 
					count = count + (min(j - b, a - j)) * cnt[j]; 
			} 
		} 

		// Find the minimum of all costs 
		// for modifying the string 
		res = min(res, count); 
	} 

	return res; 
} 

// Driver code 
int main() 
{ 
	string str = "abcdefghi"; 
	int K = 2; 
	cout << minCost(str, K); 

	return 0; 
} 
