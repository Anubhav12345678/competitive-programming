// C++ program for above implementation 
#include<bits/stdc++.h> 
using namespace std; 

// Utility function to find maximum string 
string maximumNum(string curr_num, string res) 
{ 
	int len1 = curr_num.length(); 
	int len2 = res.length(); 

	// If both having equal lengths 
	if (len1 == len2) 
	{ 
		// Reach first unmatched character / value 
		int i = 0; 
		while (curr_num[i]== res[i]) 
			i++; 

		// Return string with maximum value 
		if (curr_num[i] < res[i]) 
			return res; 
		else
			return curr_num; 
	} 

	// If different lengths 
	// return string with maximum length 
	return len1 < len2 ? res: curr_num; 
} 

// Function to extract the maximum value 
string extractMaximum(string str) 
{ 
	int n = str.length(); 
	string curr_num =""; 
	string res; 

	// Start traversing the string 
	for (int i = 0; i<n; i++) 
	{ 
		// Ignore leading zeroes 
		while (i<n && str[i]=='0') 
			i++; 

		// Store numeric value into a string 
		while (i<n && str[i]>='0' && str[i]<='9') 
		{ 
			curr_num = curr_num + str[i]; 
			i++; 
		} 

		if (i == n) 
			break; 

		if (curr_num.size() > 0) 
			i--; 

		// Update maximum string 
		res = maximumNum(curr_num, res); 

		curr_num = ""; 
	} 

	// To handle the case if there is only 
	// 0 numeric value 
	if (curr_num.size()== 0 && res.size()== 0) 
		res = res + '0'; 

	// Return maximum string 
	return maximumNum(curr_num, res); 
} 

// Drivers program 
int main() 
{ 
	string str ="100klh564abc365bg"; 
	cout << extractMaximum(str) << endl; 
	return 0; 
} 
