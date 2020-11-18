// C++ Program to implement the 
// above approach 
#include <bits/stdc++.h> 
using namespace std; 

string largestString(string num, int k) 
{ 
	// final result string 
	string ans = ""; 

	for (auto i : num) { 

		// If the current char exceeds the 
		// character at the top of the stack 
		while (ans.length() && ans.back() < i 
			&& k > 0) { 

			// Remove from the end of the string 
			ans.pop_back(); 

			// Decrease k for the removal 
			k--; 
		} 

		// Insert current character 
		ans.push_back(i); 
	} 

	// Perform remaining K deletions 
	// from the end of the string 
	while (ans.length() and k--) { 
		ans.pop_back(); 
	} 

	// Return the string 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	string str = "zyxedcba"; 
	int k = 1; 

	cout << largestString(str, k) << endl; 
} 
