#include <bits/stdc++.h> 
using namespace std; 

// Returns count of ways n people 
// can remain single or paired up. 
int countFriendsPairings(int n) 
{ 
	int a = 1, b = 2, c = 0; 
	if (n <= 2) { 
		return n; 
	} 
	for (int i = 3; i <= n; i++) { 
		c = b + (i - 1) * a; 
		a = b; 
		b = c; 
	} 
	return c; 
} 

// Driver code 
int main() 
{ 
	int n = 4; 
	cout << countFriendsPairings(n); 
	return 0; 
} 

// This code is contributed by mits 
