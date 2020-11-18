#include <bits/stdc++.h> 
using namespace std; 
#define R 3 
#define C 6 

void spiralPrint(int m, int n, int a[R][C]) 
{ 
	int i, k = 0, l = 0; 

	/* k - starting row index 
		m - ending row index 
		l - starting column index 
		n - ending column index 
		i - iterator 
	*/

	while (k < m && l < n) { 
		/* Print the first row from 
			the remaining rows */
		for (i = l; i < n; ++i) { 
			cout << a[k][i] << " "; 
		} 
		k++; 

		/* Print the last column 
		from the remaining columns */
		for (i = k; i < m; ++i) { 
			cout << a[i][n - 1] << " "; 
		} 
		n--; 

		/* Print the last row from 
				the remaining rows */
		if (k < m) { 
			for (i = n - 1; i >= l; --i) { 
				cout << a[m - 1][i] << " "; 
			} 
			m--; 
		} 

		/* Print the first column from 
				the remaining columns */
		if (l < n) { 
			for (i = m - 1; i >= k; --i) { 
				cout << a[i][l] << " "; 
			} 
			l++; 
		} 
	} 
} 

/* Driver program to test above functions */
int main() 
{ 
	int a[R][C] = { { 1, 2, 3, 4, 5, 6 }, 
					{ 7, 8, 9, 10, 11, 12 }, 
					{ 13, 14, 15, 16, 17, 18 } }; 

	spiralPrint(R, C, a); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 
// me LEETCODE
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==0)
            return {};
        int m = matrix[0].size();
        if(m==0)
            return {};
        int i=0,j=0,k=n-1,l=m-1,a,b,c;
        vector<int> res;
        // i-start row
        // k-end row
        // j = start col
        // l=end col
        while(i<n&&j<m)
        {
            for(a=j;a<m;a++)
            {
                res.push_back(matrix[i][a]);
            }
            i++;
            for(a=i;a<n;a++)
                res.push_back(matrix[a][m-1]);
            m--;
            if(i<n)
            {
                for(a=m-1;a>=j;a--)
                    res.push_back(matrix[n-1][a]);
                n--;
            }
            if(j<m)
            {
                for(a=n-1;a>=i;a--)
                    res.push_back(matrix[a][j]);
                    j++;
            }
        }
        return res;
    }
};