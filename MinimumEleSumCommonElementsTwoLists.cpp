// Hashing based C++ program to find common elements 
// with minimum index sum. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print common strings with minimum index sum 
void find(vector<string> list1, vector<string> list2) 
{ 
	// mapping strings to their indices 
	unordered_map<string, int> map; 
	for (int i = 0; i < list1.size(); i++) 
		map[list1[i]] = i; 

	vector<string> res; // resultant list 

	int minsum = INT_MAX; 
	for (int j = 0; j < list2.size(); j++) 
	{ 
		if (map.count(list2[j])) 
		{ 
			// If current sum is smaller than minsum 
			int sum = j + map[list2[j]]; 
			if (sum < minsum) 
			{ 
				minsum = sum; 
				res.clear(); 
				res.push_back(list2[j]); 
			} 

			// if index sum is same then put this 
			// string in resultant list as well 
			else if (sum == minsum) 
				res.push_back(list2[j]); 
		} 
	} 

	// Print result 
	for (int i = 0; i < res.size(); i++) 
		cout << res[i] << " "; 
} 

// Driver code 
int main() 
{ 
	// Creating list1 
	vector<string> list1; 
	list1.push_back("GeeksforGeeks"); 
	list1.push_back("Udemy"); 
	list1.push_back("Coursera"); 
	list1.push_back("edX"); 

	// Creating list2 
	vector<string> list2; 
	list2.push_back("Codecademy"); 
	list2.push_back("Khan Academy"); 
	list2.push_back("GeeksforGeeks"); 

	find(list1, list2); 
	return 0; 
} 
