// See the Cormen book for details of the 
// following algorithm 
#include<bits/stdc++.h> 
using namespace std; 

// Matrix Ai has dimension p[i-1] x p[i] 
// for i = 1..n 
int MatrixChainOrder(int p[], int n) 
{ 

	/* For simplicity of the program, one 
	extra row and one extra column are 
	allocated in m[][]. 0th row and 0th 
	column of m[][] are not used */
	int m[n][n]; 

	int i, j, k, L, q; 

	/* m[i,j] = Minimum number of scalar 
	multiplications needed to compute the 
	matrix A[i]A[i+1]...A[j] = A[i..j] where 
	dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying 
	// one matrix. 
	for (i = 1; i < n; i++) 
		m[i][i] = 0; 

	// L is chain length. 
	for (L = 2; L < n; L++) 
	{ 
		for (i = 1; i < n - L + 1; i++) 
		{ 
			j = i + L - 1; 
			m[i][j] = INT_MAX; 
			for (k = i; k <= j - 1; k++) 
			{ 
				// q = cost/scalar multiplications 
				q = m[i][k] + m[k + 1][j] + 
					p[i - 1] * p[k] * p[j]; 
				if (q < m[i][j]) 
					m[i][j] = q; 
			} 
		} 
	} 

	return m[1][n - 1]; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {1, 2, 3, 4}; 
	int size = sizeof(arr) / sizeof(arr[0]); 

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, size); 

	getchar(); 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(vector<int> &v)
{
	int n = v.size();
	int i,j,k,l,q;
	int m[n][n];
	for(i=1;i<n;i++)
	m[i][i]=0;
	for(l=2;l<n;l++)
	{
		for(i=1;i<n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+v[i-1]*v[k]*v[j];
				m[i][j] = min(q,m[i][j]);
			}
		}
	}
	return m[1][n-1];
	
}
int main() {
	vector<int> arr = {1, 2, 3, 4}; 
    // int size = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << solve(arr); 
  
    // getchar(); 
    return 0; 
	// your code goes here
	return 0;
}