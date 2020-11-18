// C++ program to evaluate value of an expression. 
#include <bits/stdc++.h> 

using namespace std; 

int evaluateBoolExpr(string s) 
{ 
	int n = s.length(); 

	// Traverse all operands by jumping 
	// a character after every iteration. 
	for (int i = 0; i < n; i += 2) { 

		// If operator next to current operand 
		// is AND. 
		if (s[i + 1] == 'A') { 
			if (s[i + 2] == '0'|| s[i] == '0') 
				s[i + 2] = '0'; 
			else
				s[i + 2] = '1'; 
		} 

		// If operator next to current operand 
		// is OR. 
		else if (s[i + 1] == 'B') { 
			if (s[i + 2] == '1'|| s[i] == '1') 
				s[i + 2] = '1'; 
			else
				s[i + 2] = '0'; 
		} 

		// If operator next to current operand 
		// is XOR (Assuming a valid input) 
		else { 
			if (s[i + 2] == s[i]) 
				s[i + 2] = '0'; 
			else
				s[i + 2] = '1'; 
		} 
	} 
	return s[n - 1] -'0'; 
} 

// Driver code 
int main() 
{ 
	string s = "1C1B1B0A0"; 
	cout << evaluateBoolExpr(s); 
	return 0; 
} 
