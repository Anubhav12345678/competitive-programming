// CPP program to print the largest 
// connected component in a grid 
#include <bits/stdc++.h> 
using namespace std; 

const int n = 6; 
const int m = 8; 

// stores information about which cell 
// are already visited in a particular BFS 
int visited[n][m]; 

// result stores the final result grid 
int result[n][m]; 

// stores the count of cells in the largest 
// connected component 
int COUNT; 

// Function checks if a cell is valid i.e it 
// is inside the grid and equal to the key 
bool is_valid(int x, int y, int key, int input[n][m]) 
{ 
	if (x < n && y < m && x >= 0 && y >= 0) { 
		if (visited[x][y] == false && input[x][y] == key) 
			return true; 
		else
			return false; 
	} 
	else
		return false; 
} 

// BFS to find all cells in 
// connection with key = input[i][j] 
void BFS(int x, int y, int i, int j, int input[n][m]) 
{ 
	// terminating case for BFS 
	if (x != y) 
		return; 

	visited[i][j] = 1; 
	COUNT++; 

	// x_move and y_move arrays 
	// are the possible movements 
	// in x or y direction 
	int x_move[] = { 0, 0, 1, -1 }; 
	int y_move[] = { 1, -1, 0, 0 }; 

	// checks all four points connected with input[i][j] 
	for (int u = 0; u < 4; u++) 
		if (is_valid(i + y_move[u], j + x_move[u], x, input)) 
			BFS(x, y, i + y_move[u], j + x_move[u], input); 
} 

// called every time before a BFS 
// so that visited array is reset to zero 
void reset_visited() 
{ 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			visited[i][j] = 0; 
} 

// If a larger connected component 
// is found this function is called 
// to store information about that component. 
void reset_result(int key, int input[n][m]) 
{ 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) { 
			if (visited[i][j] && input[i][j] == key) 
				result[i][j] = visited[i][j]; 
			else
				result[i][j] = 0; 
		} 
	} 
} 
// function to print the result 
void print_result(int res) 
{ 
	cout << "The largest connected "
		<< "component of the grid is :" << res << "\n"; 

	// prints the largest component 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) { 
			if (result[i][j]) 
				cout << result[i][j] << " "; 
			else
				cout << ". "; 
		} 
		cout << "\n"; 
	} 
} 

// function to calculate the largest connected 
// component 
void computeLargestConnectedGrid(int input[n][m]) 
{ 
	int current_max = INT_MIN; 

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) { 
			reset_visited(); 
			COUNT = 0; 

			// checking cell to the right 
			if (j + 1 < m) 
				BFS(input[i][j], input[i][j + 1], i, j, input); 

			// updating result 
			if (COUNT >= current_max) { 
				current_max = COUNT; 
				reset_result(input[i][j], input); 
			} 
			reset_visited(); 
			COUNT = 0; 

			// checking cell downwards 
			if (i + 1 < n) 
				BFS(input[i][j], input[i + 1][j], i, j, input); 

			// updating result 
			if (COUNT >= current_max) { 
				current_max = COUNT; 
				reset_result(input[i][j], input); 
			} 
		} 
	} 
	print_result(current_max); 
} 
// Drivers Code 
int main() 
{ 
	int input[n][m] = { { 1, 4, 4, 4, 4, 3, 3, 1 }, 
						{ 2, 1, 1, 4, 3, 3, 1, 1 }, 
						{ 3, 2, 1, 1, 2, 3, 2, 1 }, 
						{ 3, 3, 2, 1, 2, 2, 2, 2 }, 
						{ 3, 1, 3, 1, 1, 4, 4, 4 }, 
						{ 1, 1, 3, 1, 1, 4, 4, 4 } }; 

	// function to compute the largest 
	// connected component in the grid 
	computeLargestConnectedGrid(input); 
	return 0; 
} 
