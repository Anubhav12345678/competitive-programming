// C++ program burst balloon problem 
#include <bits/stdc++.h> 
#include <iostream> 
using namespace std; 
/*
We have been given N balloons, each with a number of coins associated with it. On bursting a balloon i, the number of 
coins gained is equal to A[i-1]*A[i]*A[i+1]. Also, balloons i-1 and i+1 now become adjacent. Find the maximum possible
 profit earned after bursting all the balloons. Assume an extra 1 at each boundary.
Examples: 

Input : 5, 10
Output : 60
Explanation - First Burst 5, Coins = 1*5*10
              Then burst 10, Coins+= 1*10*1
              Total = 60

Input : 1, 2, 3, 4, 5
Output : 110

*/
int getMax(int A[], int N) 
{ 
	// Add Bordering Balloons 
	int B[N + 2]; 

	B[0] = 1; 
	B[N + 1] = 1; 

	for (int i = 1; i <= N; i++) 
		B[i] = A[i - 1]; 

	// Declare DP Array 
	int dp[N + 2][N + 2]; 
	memset(dp, 0, sizeof(dp)); 

	for (int length = 1; length < N + 1; length++) 
	{ 
		for (int left = 1; left < N - length + 2; left++) 
		{ 
			int right = left + length - 1; 
			// For a sub-array from indices left, right 
			// This innermost loop finds the last balloon burst 
			for (int last = left; last < right + 1; last++) 
			{ 
				dp[left][right] = max(dp[left][right], 
									dp[left][last - 1] + 
									B[left - 1] * B[last] * B[right + 1] + 
									dp[last + 1][right]); 
			} 
		} 
	} 
	return dp[1][N]; 
} 


// Driver code 
int main() 
{ 
	int A[] = { 1, 2, 3, 4, 5 }; 
	
	// Size of the array 
	int N = sizeof(A) / sizeof(A[0]); 

	// Calling function 
	cout << getMax(A, N) << endl; 
} 

// This code is contributed by ashutosh450 
