class Solution {
public:
    /**
     * for every number in the array:
     *  - if there was a number previously k-diff with it, save the smaller to a set;
     *  - and save the value-index to a map;
     */
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_set<int> starters;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(nums[i] - k)) {
                starters.insert(nums[i] - k);
            }
            if (indices.count(nums[i] + k)) {
                starters.insert(nums[i]);
            }

            indices[nums[i]] += 1;
        }
        
        return starters.size();
    }
};
/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.


*/