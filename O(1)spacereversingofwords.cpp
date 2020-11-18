// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to resturn the string after 
// reversing the individual words 
string reverseWords(string str) 
{ 

	// Pointer to the first character 
	// of the first word 
	int start = 0; 
	for (int i = 0; i <= str.size(); i++) { 

		// If the current word has ended 
		if (str[i] == ' ' || i == str.size()) { 

			// Pointer to the last character 
			// of the current word 
			int end = i - 1; 

			// Reverse the current word 
			while (start < end) { 
				swap(str[start], str[end]); 
				start++; 
				end--; 
			} 

			// Pointer to the first character 
			// of the next word 
			start = i + 1; 
		} 
	} 

	return str; 
} 

// Driver code 
int main() 
{ 
	string str = "Geeks for Geeks"; 

	cout << reverseWords(str); 

	return 0; 
} 
