// The main function that returns index of row with maximum number of 1s. 
int rowWithMax1s(bool mat[R][C]) 
{ 
	// Initialize first row as row with max 1s 
	int max_row_index = 0; 

	// The function first() returns index of first 1 in row 0. 
	// Use this index to initialize the index of leftmost 1 seen so far 
	int j = first(mat[0], 0, C-1); 
	if (j == -1) // if 1 is not present in first row 
	j = C - 1; 

	for (int i = 1; i < R; i++) 
	{ 
		// Move left until a 0 is found 
		while (j >= 0 && mat[i][j] == 1) 
		{ 
		j = j-1; // Update the index of leftmost 1 seen so far 
		max_row_index = i; // Update max_row_index 
		} 
	} 
	return max_row_index; 
} 
