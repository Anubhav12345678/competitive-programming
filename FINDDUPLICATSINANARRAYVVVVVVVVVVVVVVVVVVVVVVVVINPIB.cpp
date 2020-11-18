int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
        long long int sum = 0;
        for(int i = 0; i<n; i++){
            sum += A[i];
        }
        long long int m = n-1;
        long long int total = (m * (m+1)) / 2;
        return sum - total;
}
/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1


*/
//FLOYD WARSHALL
class Solution {
  public int findDuplicate(int[] nums) {
    // Find the intersection point of the two runners.
    int tortoise = nums[0];
    int hare = nums[0];
    do {
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
      tortoise = nums[tortoise];
      hare = nums[hare];
    }

    return hare;
  }
}