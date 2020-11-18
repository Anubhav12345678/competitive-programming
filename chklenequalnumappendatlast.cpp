// C++ program to check if size of string is appended 
// at the end or not. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find if given number is equal to 
// length or not 
bool isequal(string str) 
{ 
	int n = str.length(); 

	// Traverse string from end and find the number 
	// stored at the end. 
	// x is used to store power of 10. 
	int num = 0, x = 1, i = n - 1; 
	for (i = n - 1; i >= 0; i--) { 
		if ('0' <= str[i] && str[i] <= '9') { 
			num = (str[i] - '0') * x + num; 
			x = x * 10; 
		} 
		else
			break; 
	} 

	// Check if number is equal to string length except 
	// that number's digits 
	return num == i + 1; 
} 

// Drivers code 
int main() 
{ 
	string str = "geeksforgeeks13"; 
	isequal(str) ? cout << "Yes" : cout << "No"; 
	return 0; 
} 
