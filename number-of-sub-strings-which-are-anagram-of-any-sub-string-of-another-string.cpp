// C++ program to find the number of sub-strings 
// of s1 which are anagram of any sub-string of s2 

#include <bits/stdc++.h> 
using namespace std; 

#define ALL_CHARS 256 

// This function returns true if 
// contents of arr1[] and arr2[] 
// are same, otherwise false. 
bool compare(char* arr1, char* arr2) 
{ 
	for (int i = 0; i < ALL_CHARS; i++) 
		if (arr1[i] != arr2[i]) 
			return false; 

	return true; 
} 

// This function search for all permutations 
// of string pat[] in string txt[] 
bool search(string pat, string txt) 
{ 
	int M = pat.length(); 
	int N = txt.length(); 

	int i; 

	// countP[]: Store count of all characters 
	// of pattern 
	// countTW[]: Store count of current 
	// window of text 
	char countP[ALL_CHARS] = { 0 }; 
	char countTW[ALL_CHARS] = { 0 }; 
	for (i = 0; i < M; i++) { 
		(countP[pat[i]])++; 
		(countTW[txt[i]])++; 
	} 

	// Traverse through remaining 
	// characters of pattern 
	for (i = M; i < N; i++) { 

		// Compare counts of current 
		// window of text with 
		// counts of pattern[] 
		if (compare(countP, countTW)) { 
			// cout<<pat<<" "<<txt<<" "; 
			return true; 
		} 

		// Add current character to current window 
		(countTW[txt[i]])++; 

		// Remove the first character 
		// of previous window 
		countTW[txt[i - M]]--; 
	} 

	// Check for the last window in text 
	if (compare(countP, countTW)) 
		return true; 

	return false; 
} 

// Function to return the number of sub-strings of s1 
// that are anagrams of any sub-string of s2 
int calculatesubString(string s1, string s2, int n) 
{ 
	// initializing variables 
	int count = 0, j = 0, x = 0; 

	// outer loop for picking starting point 
	for (int i = 0; i < n; i++) { 

		// loop for different length of substrings 
		for (int len = 1; len <= n - i; len++) { 

			// If s2 has any substring which is 
			// anagram of s1.substr(i, len) 
			if (search(s1.substr(i, len), s2)) { 

				// increment the count 
				count = count + 1; 
			} 
		} 
	} 
	return count; 
} 

// Driver code 
int main() 
{ 
	string str1 = "PLEASEHELPIMTRAPPED"; 
	string str2 = "INAKICKSTARTFACTORY"; 

	int len = str1.length(); 

	cout << calculatesubString(str1, str2, len); 

	return 0; 
} 
