// A C++ program to find the maximum depth of nested 
// parenthesis in a given expression 
#include <iostream> 
using namespace std; 

// function takes a string and returns the 
// maximum depth nested parenthesis 
int maxDepth(string S) 
{ 
	int current_max = 0; // current count 
	int max = 0; // overall maximum count 
	int n = S.length(); 

	// Traverse the input string 
	for (int i = 0; i< n; i++) 
	{ 
		if (S[i] == '(') 
		{ 
			current_max++; 

			// update max if required 
			if (current_max> max) 
				max = current_max; 
		} 
		else if (S[i] == ')') 
		{ 
			if (current_max>0) 
				current_max--; 
			else
				return -1; 
		} 
	} 

	// finally check for unbalanced string 
	if (current_max != 0) 
		return -1; 

	return max; 
} 

// Driver program 
int main() 
{ 
	string s = "( ((X)) (((Y))) )"; 
	cout << maxDepth(s); 
	return 0; 
} 
