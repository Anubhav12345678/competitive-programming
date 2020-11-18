// C++ program to check if input number 
// is a valid number 
#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 

int valid_number(string str) 
{ 
	int i = 0, j = str.length()-1; 
	
	//Handling whitespaces 
	while(i < str.length() && str[i] == ' ') 
		i++; 
	while(j >=0 && str[j] == ' ') 
		j--; 
	
	if(i > j) 
		return 0; 
		
	// if string is of length 1 and the only 
	// character is not a digit 
	if(i==j && !(str[i] >= '0' && str[i] <= '9')) 
		return 0; 
		
	// If the 1st char is not '+', '-', '.' or digit 
	if(str[i] != '.' && str[i] != '+' && 
		str[i] != '-' && !(str[i] >= '0' && 
		str[i] <= '9')) 
		return 0; 

	// To check if a '.' or 'e' is found in given 
	// string. We use this flag to make sure that 
	// either of them appear only once. 
	bool flagDotOrE = false; 
	
	for(i ; i <= j ; i++) 
	{ 
		// If any of the char does not belong to 
		// {digit, +, -, ., e} 
		if(str[i] != 'e' && str[i] != '.' && 
			str[i] != '+' && str[i] != '-' && 
			!(str[i] >= '0' && str[i] <= '9')) 
			return 0; 
			
		if(str[i] == '.') 
		{ 
			// checks if the char 'e' has already 
			// occurred before '.' If yes, return 0. 
			if(flagDotOrE == true) 
				return 0; 
				
			// If '.' is the last character. 
			if(i+1 > str.length()) 
				return 0; 
				
			// if '.' is not followed by a digit. 
			if(!(str[i+1] >= '0' && str[i+1] <= '9')) 
				return 0; 
		} 
		
		else if(str[i] == 'e') 
		{ 
			// set flagDotOrE = 1 when e is encountered. 
			flagDotOrE = true; 
			
			// if there is no digit before 'e'. 
			if(!(str[i-1] >= '0' && str[i-1] <= '9')) 
				return 0; 
			
			// If 'e' is the last Character	 
			if(i+1 > str.length()) 
				return 0; 
				
			// if e is not followed either by 
			// '+', '-' or a digit	 
			if(str[i+1] != '+' && str[i+1] != '-' && 
				!(str[i+1] >= '0' && str[i] <= '9')) 
				return 0; 
		} 
	} 
	
	/* If the string skips all above cases, then 
	it is numeric*/
	return 1; 
} 

// Driver code 
int main() 
{ 
	string str;
	cin>>str;
	if(valid_number(str)) 
		cout << "true"; 
	else
		cout << "false"; 
	return 0; 
} 

// This code is contributed by rahulkumawat2107 
