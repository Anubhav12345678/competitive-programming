// C++ program to find difference between two 
// given times. 
#include <bits/stdc++.h> 
using namespace std; 

// remove ':' and convert it into an integer 
int removeColon(string s) 
{ 
	if (s.size() == 4) 
		s.replace(1, 1, ""); 
	
	if (s.size() == 5) 
		s.replace(2, 1, ""); //s.replace(i,len,"<new string>") replaces string starting from ith index of length len with the new string
	
	return stoi(s); // converts given string to integer
} 

// Main function which finds difference 
string diff(string s1, string s2) 
{ 

	// change string (eg. 2:21 --> 221, 00:23 --> 23) 
	int time1 = removeColon(s1); 
	int time2 = removeColon(s2); 

	// difference between hours 
	int hourDiff = time2 / 100 - time1 / 100 - 1; 

	// difference between minutes 
	int minDiff = time2 % 100 + (60 - time1 % 100); 

	if (minDiff >= 60) { 
		hourDiff++; 
		minDiff = minDiff - 60; 
	} 

	// convert answer again in string with ':' 
	string res = to_string(hourDiff) + ':' + to_string(minDiff); 
	return res; 
} 

// Driver program to test above functions 
int main() 
{ 
	string s1 = "14:00"; 
	string s2 = "16:45"; 
	cout << diff(s1, s2) << endl; 
	return 0; 
} 
