// C++ program to find the find the Longest continuous 
// sequence of '0' after repeating Given string K time 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the longest substring of 0's 
int longest_substring(string s, int k) 
{ 
	// To store size of the string 
	int n = s.size(); 
	
	if(k>1) 
	{ 
		s += s; 
		n *= 2; 
	}	 
	
	// To store the required answer 
	int ans = 0; 
	
	// Find the longest substring of 0's 
	int i = 0; 
	while (i < n) 
	{ 
		int x = 0; 
		
		// Run a loop upto s[i] is zero 
		while (s[i] == '0' && i < n) 
			x++, i++; 
		ans = max(ans, x); 
		i++; 
	} 
	
	// Check the conditions 
	if(k==1 or ans!=n) 
		return ans; 
		
	else
		return (ans/2)*k; 
} 

// Driver code 
int main() 
{ 
	string s = "010001000"; 
	
	int k = 4; 
	
	// Function call 
	cout << longest_substring(s, k); 
	
	return 0; 
} 
