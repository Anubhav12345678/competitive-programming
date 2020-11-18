// C++ implementation to find the 
// largest square in the matrix such 
// that it contains atmost K 1's 

#include <bits/stdc++.h> 
using namespace std; 
const int MAX = 100; 

// Function to find the 
// largest square in the matrix such 
// that it contains atmost K 1's 
void largestSquare(int matrix[][MAX], 
			int R, int C, int q_i[], 
			int q_j[], int K, int Q){ 
	
	int countDP[R][C]; 
	memset(countDP, 0, sizeof(countDP)); 

	// Precomputing the countDP 
	// prefix sum of the matrix 
	countDP[0][0] = matrix[0][0]; 
	for (int i = 1; i < R; i++) 
		countDP[i][0] = countDP[i - 1][0] + 
							matrix[i][0]; 
	for (int j = 1; j < C; j++) 
		countDP[0][j] = countDP[0][j - 1] + 
							matrix[0][j]; 
	for (int i = 1; i < R; i++) 
		for (int j = 1; j < C; j++) 
			countDP[i][j] = matrix[i][j] + 
					countDP[i - 1][j] + 
					countDP[i][j - 1] - 
					countDP[i - 1][j - 1]; 
	
	// Loop to solve Queries 
	for (int q = 0; q < Q; q++) { 
		int i = q_i[q]; 
		int j = q_j[q]; 
		// Calculating the maximum 
		// possible distance of the 
		// centre from edge 
		int min_dist = min(min(i, j), 
		min(R - i - 1, C - j - 1)); 
		int ans = -1; 
		for (int k = 0; k <= min_dist; 
								k++) { 
			int x1 = i - k, x2 = i + k; 
			int y1 = i - k, y2 = j + k; 
			
			// Calculating the number 
			// of 1s in the submatrix 
			int count = countDP[x2][y2]; 
			if (x1 > 0) 
				count -= countDP[x1 - 1][y2]; 
			if (y1 > 0) 
				count -= countDP[x2][y1 - 1]; 
			if (x1 > 0 && y1 > 0) 
				count += countDP[x1 - 1][y1 - 1]; 

			if (count > K) 
				break; 
			ans = 2 * k + 1; 
		} 
		cout << ans << "\n"; 
	} 
} 

// Driver Code 
int main() 
{ 
	int matrix[][MAX] = { { 1, 0, 1, 0, 0 }, 
						{ 1, 0, 1, 1, 1 }, 
						{ 1, 1, 1, 1, 1 }, 
						{ 1, 0, 0, 1, 0 } }; 

	int K = 9, Q = 1; 
	int q_i[] = { 1 }; 
	int q_j[] = { 2 }; 
	largestSquare(matrix, 4, 5, q_i, 
						q_j, K, Q); 
	return 0; 
} 
