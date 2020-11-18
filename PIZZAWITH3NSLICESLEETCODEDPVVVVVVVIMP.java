// We can understand the problem: pick n non-adjacent elements from circular array m=3n elements so that the sum of the elements is
 // maximum.
// We can't pick 0th and (m-1)th elements at the same time, since it's adjacent in circular array.
// So there are total 2 cases, then we can return the case with maximum sum:
// Case 1: Don't pick (m-1)th element
// => Solve problem: pick n non-adjacent elements from linear array elements in ranges [0..m-2] so that the sum of the elements is 
 // maximum.
// Case 2: Don't pick 0th element
// => Solve problem: pick n non-adjacent elements from linear array elements in ranges [1..m-1] so that the sum of the elements 
 // is maximum.
public int maxSizeSlices(int[] slices) {
	int m = slices.length, n = m / 3;
	int[] slices1 = Arrays.copyOfRange(slices, 0, m-1);
	int[] slices2 = Arrays.copyOfRange(slices, 1, m);
	return Math.max(maxSum(slices1, n), maxSum(slices2, n));
}

int maxSum(int[] arr, int n) { // max sum when pick `n` non-adjacent elements from `arr`
	int m = arr.length;
	int[][] dp = new int[m+1][n+1]; // dp[i][j] is maximum sum which we pick `j` elements from linear array `i` elements
	// Case j = 0 (pick 0 elements): dp[i][0] = 0
	// Case i = 0 (array is empty): dp[0][j] = 0
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == 1) { // array has only 1 element
				dp[i][j] = arr[0]; // pick that element
			} else {
				dp[i][j] = Math.max(
					dp[i-1][j],             // don't pick element `ith`
					dp[i-2][j-1] + arr[i-1] // pick element `ith` -> dp[i-2][j-1] means choose `j-1` elements from array `i-2` elements
											//   because we exclude adjacent element `(i-1)th`
				);
			}
		}
	}
	return dp[m][n];
}