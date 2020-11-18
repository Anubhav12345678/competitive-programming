// C++ program to find minimum cost to get exactly
// W Kg with given packets
#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

// cost[] initial cost array including unavailable packet
// W capacity of bag
int MinimumCost(int cost[], int n, int W)
{
	// val[] and wt[] arrays
	// val[] array to store cost of 'i' kg packet of orange
	// wt[] array weight of packet of orange
	vector<int> val, wt;

	// traverse the original cost[] array and skip
	// unavailable packets and make val[] and wt[]
	// array. size variable tells the available number
	// of distinct weighted packets
	int size = 0;
	for (int i=0; i<n; i++)
	{
		if (cost[i]!= -1)
		{
			val.push_back(cost[i]);
			wt.push_back(i+1);
			size++;
		}
	}

	n = size;
	int min_cost[n+1][W+1];

	// fill 0th row with infinity
	for (int i=0; i<=W; i++)
		min_cost[0][i] = INF;

	// fill 0'th column with 0
	for (int i=1; i<=n; i++)
		min_cost[i][0] = 0;

	// now check for each weight one by one and fill the
	// matrix according to the condition
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=W; j++)
		{
			// wt[i-1]>j means capacity of bag is
			// less then weight of item
			if (wt[i-1] > j)
				min_cost[i][j] = min_cost[i-1][j];

			// here we check we get minimum cost either
			// by including it or excluding it
			else
				min_cost[i][j] = min(min_cost[i-1][j],
					min_cost[i][j-wt[i-1]] + val[i-1]);
		}
	}

	// exactly weight W can not be made by given weights
	return (min_cost[n][W]==INF)? -1: min_cost[n][W];
}

// Driver program to run the test case
int main()
{
	int cost[] = {1, 2, 3, 4, 5}, W = 5;
	int n = sizeof(cost)/sizeof(cost[0]);

	cout << MinimumCost(cost, n, W);
	return 0;
}
/*
Minimum cost to fill given weight in a bag
Last Updated: 23-09-2020
You are given a bag of size W kg and you are provided costs of packets different weights of oranges in array cost[] where cost[i] is basically the cost of ‘i’ kg packet of oranges. Where cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
Find the minimum total cost to buy exactly W kg oranges and if it is not possible to buy exactly W kg oranges then print -1. It may be assumed that there is an infinite supply of all available packet types.
Note: array starts from index 1. 


*/