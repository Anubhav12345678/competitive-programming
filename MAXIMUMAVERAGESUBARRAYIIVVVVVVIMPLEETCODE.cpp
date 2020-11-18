class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        int nmin = Integer.MAX_VALUE, nmax = Integer.MIN_VALUE;
        for (int num : nums) {
            nmin = Math.min(nmin, num);
            nmax = Math.max(nmax, num);
        }
        double min = nmin, max = nmax;
        double epsilon = 0.00001, error = 1;
        while (max - min > epsilon) {
            double mid = min + (max - min) / 2;
            if (valid(nums, mid, k)) min = mid;
            else max = mid;
        }
        return min;
    }

    private boolean valid(int[] nums, double target, int k) {
        int i = 0;
        double sum = 0;
        while (i < k) {
            sum += nums[i++] - target;
        }
        if (sum >= 0) return true;
        double prev = 0, min = 0;
        while (i < nums.length) {
            sum += nums[i] - target;
            prev += nums[i - k] - target;
            i++;
            min = Math.min(min, prev);
            if (sum >= min) return true;
        }
        return false;
    }
}
/*

Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

Example:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.
Note:

1 <= k <= n <= 10,000.
Elements of the given array will be in range [-10,000, 10,000].
The answer with the calculation error less than 10-5 will be accepted.


*/