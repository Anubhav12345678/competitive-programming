// C++ implementation to count items common to both 
// the lists but with different prices 
#include <bits/stdc++.h> 

using namespace std; 

// details of an item 
struct item 
{ 
	string name; 
	int price; 
}; 

// function to count items common to both 
// the lists but with different prices 
int countItems(item list1[], int m, 
			item list2[], int n) 
{ 
	// 'um' implemented as hash table that contains 
	// item name as the key and price as the value 
	// associated with the key 
	unordered_map<string, int> um; 
	int count = 0; 
	
	// insert elements of 'list1' in 'um' 
	for (int i = 0; i < m; i++) 
		um[list1[i].name] = list1[i].price; 
	
	// for each element of 'list2' check if it is 
	// present in 'um' with a different price 
	// value 
	for (int i = 0; i < n; i++)	 
		if ((um.find(list2[i].name) != um.end()) && 
			(um[list2[i].name] != list2[i].price)) 
			count++; 
	
	// required count of items		 
	return count;		 
} 

// Driver program to test above 
int main() 
{ 
	item list1[] = {{"apple", 60}, {"bread", 20}, 
					{"wheat", 50}, {"oil", 30}}; 
	item list2[] = {{"milk", 20}, {"bread", 15}, 
					{"wheat", 40}, {"apple", 60}}; 
	
	int m = sizeof(list1) / sizeof(list1[0]); 
	int n = sizeof(list2) / sizeof(list2[0]);	 
	
	cout << "Count = "	
		<< countItems(list1, m, list2, n); 
		
	return 0;	 
} 
