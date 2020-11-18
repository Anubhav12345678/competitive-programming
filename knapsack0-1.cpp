// A Dynamic Programming based solution for 0-1 Knapsack problem 
#include<stdio.h> 
// knapsack 0-1 using dp
// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 

// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
int i, w; 
int K[n+1][W+1]; 

// Build table K[][] in bottom up manner 
for (i = 0; i <= n; i++) 
{ 
	for (w = 0; w <= W; w++) 
	{ 
		if (i==0 || w==0) 
			K[i][w] = 0; 
		else if (wt[i-1] <= w) 
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
		else
				K[i][w] = K[i-1][w]; 
	} 
} 

return K[n][W]; 
} 

int main() 
{ 
	int val[] = {60, 100, 120}; 
	int wt[] = {10, 20, 30}; 
	int W = 50; 
	int n = sizeof(val)/sizeof(val[0]); 
	printf("%d", knapSack(W, wt, val, n)); 
	return 0; 
} 

// below is knapsack without using dp
/* A Naive recursive implementation of 0-1 Knapsack problem */
#include<stdio.h> 

// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 

// Returns the maximum value that can be put in a knapsack of capacity W 

int knapSack(int W, int wt[], int val[], int n,int dp[][10005]) 
{ 
// Base Case 
if (n == 0 || W == 0) 
	return 0; 
if(dp[n][W]!=0)
	return dp[n][W];
// If weight of the nth item is more than Knapsack capacity W, then 
// this item cannot be included in the optimal solution 
if (wt[n-1] > W) 
	return dp[n][W] = knapSack(W, wt, val, n-1); 

// Return the maximum of two cases: 
// (1) nth item included 
// (2) not included 
else return dp[n][W] = max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
					knapSack(W, wt, val, n-1) 
				); 
} 

// Driver program to test above function 
int main() 
{ 
	int val[] = {60, 100, 120}; 
	int wt[] = {10, 20, 30}; 
	int W = 50; 
	int n = sizeof(val)/sizeof(val[0]); 
	int dp[n+1][W+1];
	memset(dp,0,sizeof(dp));
	printf("%d", knapSack(W, wt, val, n,dp)); 
	return 0; 
} 
//this has 2^n complexity as it solves the sam subproblems again and again


