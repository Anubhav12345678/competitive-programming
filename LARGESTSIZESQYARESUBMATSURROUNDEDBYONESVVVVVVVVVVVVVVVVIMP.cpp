#include <iostream>
using namespace std;

// Dimensions of input matrix M X N
#define M 8
#define N 6

// Function to find the largest square sub-matrix which is surrounded by all 1's
int findLargestSquareSubMatrix(short mat[][N])
{
	// create two auxiliary matrix filled with all 0's of size M X N
	int X[M][N] = {};
	int Y[M][N] = {};

	// update the auxiliary matrix X[][] and Y[][] with
	// number of continuous 1's ending at the cell
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j])
			{
				if (i == 0) {
					Y[i][j] = 1;
				} else {
					Y[i][j] = Y[i - 1][j] + 1;
				}

				if (j == 0) {
					X[i][j] = 1;
				} else {
					X[i][j] = X[i][j - 1] + 1;
				}
			}
		}
	}

	// to keep track of the largest square sub-matrix
	int max_length = 0;

	// process each cell (i, j) of the auxiliary matrix starting from the
	// last cell in the last row

	for (int i = M - 1; i >= 1; i--)
	{
		for (int j = N - 1; j >= 1; j--)
		{
			// The minimum of X[i][j] and Y[i][j] would be the length of
			// right vertical line and bottom horizontal line of the
			// square matrix ending at cell (i, j)

			int len = min(X[i][j], Y[i][j]);
			while (len)
			{
				// the cell ending at current cell (i, j) forms a square
				// sub-matrix if there exists a left vertical line and a
				// top horizontal line of at-least length 'len'

				bool isSquare = Y[i][j - len + 1] >= len &&
								X[i - len + 1][j] >= len;

				// check if square ending at current cell is largest so far
				if (isSquare && max_length < len) {
					max_length = len;
				}

				// reduce the length by 1 to check for smaller squares ending
				// at current cell
				len--;
			}
		}
	}

	return max_length;
}

int main()
{
	short mat[M][N] =
	{
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 0, 1 },
		{ 0, 1, 1, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 0, 0 },
		{ 1, 0, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1 }
	};

	cout << "The size of largest square sub-matrix is "
		 << findLargestSquareSubMatrix(mat);

	return 0;
}