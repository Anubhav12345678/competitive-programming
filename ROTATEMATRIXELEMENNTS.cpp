#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define R 4
#define C 4
// https://ideone.com/1ClTfQ
void rotate(int m,int n,int mat[R][C])
{
	int i,j,k,l,row=0,col=0;
	while(row<m&&col<n)
	{
		if(row+1==m||col+1==n)
		break;
		int prev,cur;
		prev = mat[row+1][col];
		for(i=col;i<n;i++)
		{
			cur = mat[row][i];
			mat[row][i] = prev;
			prev = cur;
		}
		row++;
		for(i=row;i<m;i++)
		{
			cur = mat[i][n-1];
			mat[i][n-1] = prev;
			prev = cur;
		}
		n--;
		if(row<m)
		{
			for(i=n-1;i>=col;i--)
			{
				cur = mat[m-1][i];
				mat[m-1][i] = prev;
				prev = cur;
				
			}
			m--;
		}
		if(col<n)
		{
			for(i=m-1;i>=row;i--)
			{
				cur = mat[i][col];
				mat[i][col] = prev;
				prev= cur;
			}
			col++;
		}
	}
	  for (int i=0; i<R; i++) 
    { 
        for (int j=0; j<C; j++) 
          cout << mat[i][j] << " "; 
        cout << endl; 
    } 
}
int main() {
	  // Test Case 1 
    int a[R][C] = { {1,  2,  3,  4}, 
        {5,  6,  7,  8}, 
        {9,  10, 11, 12}, 
        {13, 14, 15, 16}  }; 
  
    // Tese Case 2 
    /* int a[R][C] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                      {7, 8, 9} 
                     }; 
     */  rotate(R, C, a); 
    return 0;
	// your code goes here
	// return 0;
}