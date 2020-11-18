//largest-palindromic-number-permuting-digits/
// CPP program to print the largest palindromic 
// number by permuting digits of a number 
#include <bits/stdc++.h> 
using namespace std; 

// function to check if a number can be 
// permuted to form a palindrome number 
bool possibility(unordered_map<int, int> m, 
				int length, string s) 
{ 
	// counts the occurrence of number which is odd 
	int countodd = 0; 
	for (int i = 0; i < length; i++) { 

		// if occurrence is odd 
		if (m[s[i] - '0'] & 1) 
			countodd++; 

		// if number exceeds 1 
		if (countodd > 1) 
			return false; 
	} 

	return true; 
} 

// function to print the largest palindromic number 
// by permuting digits of a number 
void largestPalindrome(string s) 
{ 

	// string length 
	int l = s.length(); 

	// map that marks the occurrence of a number 
	unordered_map<int, int> m; 
	for (int i = 0; i < l; i++) 
		m[s[i] - '0']++; 

	// check the possibility of a palindromic number 
	if (possibility(m, l, s) == false) { 
		cout << "Palindrome cannot be formed"; 
		return; 
	} 

	// string array that stores the largest 
	// permuted palindromic number 
	char largest[l]; 

	// pointer of front 
	int front = 0; 

	// greedily start from 9 to 0 and place the 
	// greater number in front and odd in the 
	// middle 
	for (int i = 9; i >= 0; i--) { 

		// if the occurrence of number is odd 
		if (m[i] & 1) { 

			// place one odd occurring number 
			// in the middle 
			largest[l / 2] = char(i + 48); 

			// decrease the count 
			m[i]--; 

			// place the rest of numbers greedily 
			while (m[i] > 0) { 
				largest[front] = char(i + 48); 
				largest[l - front - 1] = char(i + 48); 
				m[i] -= 2; 
				front++; 
			} 
		} 
		else { 

			// if all numbers occur even times, 
			// then place greedily 
			while (m[i] > 0) { 

				// place greedily at front 
				largest[front] = char(i + 48); 
				largest[l - front - 1] = char(i + 48); 

				// 2 numbers are placed, so decrease the count 
				m[i] -= 2; 

				// increase placing position 
				front++; 
			} 
		} 
	} 

	// print the largest string thus formed 
	for (int i = 0; i < l; i++) 
		cout << largest[i]; 
} 

// Driver Code 
int main() 
{ 
	string s = "313551"; 
	largestPalindrome(s); 
	return 0; 
} 
