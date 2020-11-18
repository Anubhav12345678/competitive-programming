// C++ program to find the probability of the 
// Knight to remain inside the chessboard after 
// taking exactly K number of steps 
/*
Probability of Knight to remain in the chessboard
Given an NxN chessboard and a Knight at position (x,y). The Knight has to take exactly
 K steps, where at each step it chooses any of the 8 directions uniformly at random
 What is the probability that the Knight remains in the chessboard after taking K 
 steps, with the condition that it can’t enter the board again once it leaves it.




*/
#include <bits/stdc++.h> 
using namespace std; 

// size of the chessboard 
#define N 8 

// direction vector for the Knight 
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 

// returns true if the knight is inside the chessboard 
bool inside(int x, int y) 
{ 
	return (x >= 0 and x < N and y >= 0 and y < N); 
} 

// Bottom up approach for finding the probability to 
// go out of chessboard. 
double findProb(int start_x, int start_y, int steps) 
{ 
	// dp array 
	double dp1[N][N][N]; 

	// for 0 number of steps, each position 
	// will have probability 1 
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) 
			dp1[i][j][0] = 1; 

	// for every number of steps s 
	for (int s = 1; s <= steps; ++s) 
	{ 
		// for every position (x,y) after 
		// s number of steps 
		for (int x = 0; x < N; ++x) 
		{ 
			for (int y = 0; y < N; ++y) 
			{ 
				double prob = 0.0; 

				// for every position reachable from (x,y) 
				for (int i = 0; i < 8; ++i) 
				{ 
					int nx = x + dx[i]; 
					int ny = y + dy[i]; 

					// if this position lie inside the board 
					if (inside(nx, ny)) 
						prob += dp1[nx][ny][s-1] / 8.0; 
				} 

				// store the result 
				dp1[x][y][s] = prob; 
			} 
		} 
	} 

	// return the result 
	return dp1[start_x][start_y][steps]; 
} 

// Driver program 
int main() 
{ 
	// number of steps 
	int K = 3; 

	cout << findProb(0, 0, K) << endl; 

	return 0; 
} 
