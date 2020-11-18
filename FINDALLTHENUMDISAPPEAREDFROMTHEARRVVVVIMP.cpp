// Make appeared numbers to negative.
        for(int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        }
        // Set disappered numbers and slide it.
        int start = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                nums[start] = i + 1; // if nums[i] is negative, then i + 1 is not appered.
                start++;
            }
        }
        
        // Erase appeared numbers.
        for(int i = nums.size() - 1; i >= start ; i--) {
            nums.erase(nums.begin() + i);
        }
        return nums;
        /*
       Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

        */