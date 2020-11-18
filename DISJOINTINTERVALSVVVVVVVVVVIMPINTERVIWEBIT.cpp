// Function to sort the vector elements by second element of pairs
bool sortbysec(vector<int> &a, vector<int> &  b)
{
    return (a[1] < b[1]);
}

// Function to find maximal disjoint set
int Solution::solve(vector<vector<int> > &A) {
      // Sort the list of intervals
      sort(A.begin(), A.end(), sortbysec);

      int ans = 1;

      // End point of first interval
      int r1 = A[0][1];

      for (int i = 1; i < A.size(); i++) {
          int l1 = A[i][0];
          int r2 = A[i][1];

          // Check if given interval overlap with previously included interval, if not
          // then include this interval and update the end point of last added interval
          if (l1 > r1) {
              ans += 1;
              r1 = r2;
          }
      }
      return ans;
}
/*
Given a set of N intervals denoted by 2D array A of size N x 2, the task is to find the
 length of maximal set of mutually disjoint intervals.

Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.

Return a integer denoting the length of maximal set of mutually disjoint intervals.

*/