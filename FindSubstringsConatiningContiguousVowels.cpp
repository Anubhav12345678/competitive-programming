// C++ program to find all substring that 
// contain all vowels 
#include<bits/stdc++.h> 

using namespace std; 

// Returns true if x is vowel. 
bool isVowel(char x) 
{ 
	// Function to check whether a character is 
	// vowel or not 
	return (x == 'a' || x == 'e' || x == 'i' || 
						x == 'o' || x == 'u'); 
} 

// Function to FindSubstrings of string 
void FindSubstring(string str) 
{ 
	set<char> hash; // To store vowels 

	int start = 0; 
	for (int i=0; i<str.length(); i++) 
	{ 
		// If current character is vowel then 
		// insert into hash , 
		if (isVowel(str[i]) == true) 
		{ 
			hash.insert(str[i]); 

			// If all vowels are present in current 
			// substring 
			if (hash.size()==5) 
				cout << str.substr(start, i-start+1) 
					<< " "; 
		} 
		else
		{ 
			start = i+1; 
			hash.clear(); 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	string str = "aeoibsddaeiouudb"; 
	FindSubstring(str); 
	return 0; 
} 
