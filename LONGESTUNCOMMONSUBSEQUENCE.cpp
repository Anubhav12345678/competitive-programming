// CPP Program to find longest uncommon 
// subsequence. 
#include <iostream> 
using namespace std; 

// function to calculate length of longest 
// uncommon subsequence 
int findLUSlength(string a, string b) 
{ 
	// Case 1: If strings are equal 
	if (!a.compare(b)) 
		return 0; 

	// for case 2 and case 3 
	return max(a.length(), b.length()); 
} 

// Driver code 
int main() 
{ 
	string a = "abcdabcd", b = "abcabc"; 
	cout << findLUSlength(a, b); 
	return 0; 
} 
