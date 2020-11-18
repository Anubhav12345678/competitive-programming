// C++ program to count all distinct palindromic 
// substrings of a string. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns total number of palindrome substring of 
// length greater than equal to 2 
int countPalindromes(string s) 
{ 
	unordered_map<string, int> m; 
	for (int i = 0; i < s.length(); i++) { 

		// check for odd length palindromes 
		for (int j = 0; j <= i; j++) { 

			if (!s[i + j]) 
				break; 

			if (s[i - j] == s[i + j]) { 

				// check for palindromes of length 
				// greater than 1 
				if ((i + j + 1) - (i - j) > 1) 
					m[s.substr(i - j, 
						(i + j + 1) - (i - j))]++; 

			} else
				break; 
		} 

		// check for even length palindromes 
		for (int j = 0; j <= i; j++) { 
			if (!s[i + j + 1]) 
				break; 
			if (s[i - j] == s[i + j + 1]) { 

				// check for palindromes of length 
				// greater than 1 
				if ((i + j + 2) - (i - j) > 1) 
					m[s.substr(i - j, 
						(i + j + 2) - (i - j))]++; 

			} else
				break; 
		} 
	} 
	return m.size(); 
} 

// Driver code 
int main() 
{ 
	string s = "abbaeae"; 
	cout << countPalindromes(s) << endl; 
	return 0; 
} 
