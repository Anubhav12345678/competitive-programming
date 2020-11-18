#include <iostream>
using namespace std;
#define M 3
#define N 3
void rotatematrix(int mat[][M],int k)
{
	int i,j,l,tmp[M];
	k=k%M;
	for(i=0;i<N;i++)
	{
		for(int t=0;t<M-k;t++)
		tmp[t] = mat[i][t];
		for(j=M-k;j<M;j++)
		mat[i][j-M+k] = mat[i][j];
		for(j=k;j<M;j++)
		mat[i][j] = tmp[j-k];
	}
}
void displayMatrix(int matrix[][M]) { 
  for (int i = 0; i < N; i++) { 
    for (int j = 0; j < M; j++) 
      cout << matrix[i][j] << " "; 
    cout << endl; 
  } 
} 
  
// Driver's code 
int main() { 
  int matrix[N][M] = {{12, 23, 34}, 
                     {45, 56, 67},  
                     {78, 89, 91}}; 
  int k = 2; 
  
  // rotate matrix by k 
  rotatematrix(matrix, k); 
  
  // display rotated matrix 
  displayMatrix(matrix); 
  
  return 0; 
} 