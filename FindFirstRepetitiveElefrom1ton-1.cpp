// CPP program to find the only repeating 
// element in an array where elements are 
// from 1 to n-1. 
#include <bits/stdc++.h> 
using namespace std; 

int findRepeating(int arr[], int n) 
{ 

// res is going to store value of 
// 1 ^ 2 ^ 3 .. ^ (n-1) ^ arr[0] ^ 
// arr[1] ^ .... arr[n-1] 
int res = 0; 
for (int i=0; i<n-1; i++) 
	res = res ^ (i+1) ^ arr[i]; 
res = res ^ arr[n-1]; 
	
return res; 
} 

// driver code 
int main() 
{ 
	int arr[] = { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findRepeating(arr, n); 
	return 0; 
} 
