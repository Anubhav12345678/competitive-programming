// C++ program to find an element x in a 
// sorted array using Exponential search. 
#include <bits/stdc++.h> 
using namespace std; 
  //Time Complexity : O(Log n)
int binarySearch(int arr[], int, int, int); 
  
// Returns position of first ocurrence of 
// x in array 
int exponentialSearch(int arr[], int n, int x) 
{ 
    // If x is present at firt location itself 
    if (arr[0] == x) 
        return 0; 
  
    // Find range for binary search by 
    // repeated doubling 
    int i = 1; 
    while (i < n && arr[i] <= x) 
        i = i*2; 
  
    //  Call binary search for the found range. 
    return binarySearch(arr, i/2, min(i, n), x); 
} 