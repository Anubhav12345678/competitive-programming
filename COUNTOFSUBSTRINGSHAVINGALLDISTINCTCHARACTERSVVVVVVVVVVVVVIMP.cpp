// C++ Program to implement 
// the above appraoach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to count total 
// number of valid substrings 
long long int countSub(string str) 
{ 
	int n = (int)str.size(); 

	// Stores the count of 
	// substrings 
	long long int ans = 0; 

	// Stores the frequency 
	// of characters 
	int cnt[26]; 

	memset(cnt, 0, sizeof(cnt)); 

	// Initialised both pointers 
	// to beginning of the string 
	int i = 0, j = 0; 

	while (i < n) { 

		// If all characters in 
		// substring from index i 
		// to j are distinct 
		if (j < n && (cnt[str[j] - 'a'] 
					== 0)) { 

			// Increment count of j-th 
			// character 
			cnt[str[j] - 'a']++; 

			// Add all substring ending 
			// at j and starting at any 
			// index between i and j 
			// to the answer 
			ans += (j - i + 1); 

			// Increment 2nd pointer 
			j++; 
		} 

		// If some characters are repeated 
		// or j pointer has reached to end 
		else { 

			// Decrement count of j-th 
			// character 
			cnt[str[i] - 'a']--; 

			// Increment first pointer 
			i++; 
		} 
	} 

	// Return the final 
	// count of substrings 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	string str = "gffg"; 

	cout << countSub(str); 

	return 0; 
} 
