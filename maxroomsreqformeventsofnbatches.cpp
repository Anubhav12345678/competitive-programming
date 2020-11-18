// CPP program to find minimum number of rooms 
// required 
#include <bits/stdc++.h> 
using namespace std; 

// Returns minimum number of rooms required 
// to perform classes of n groups in m slots 
// with given schedule. 
int findMinRooms(string slots[], int n, int m) 
{ 
	// Store count of classes happening in 
	// every slot. 
	int counts[m] = { 0 }; 
	for (int i = 0; i < n; i++)	 
		for (int j = 0; j < m; j++)		 
			if (slots[i][j] == '1') 
				counts[j]++; 
	
	// Number of rooms required is equal to 
	// maximum classes happening in a 
	// particular slot. 
	return *max_element(counts, counts+m);	 
} 

// Driver Code 
int main() 
{ 
	int n = 3, m = 7; 
	string slots[n] = { "0101011", 
						"0011001", 
						"0110111" }; 
	cout << findMinRooms(slots, n, m); 
	return 0; 
} 
