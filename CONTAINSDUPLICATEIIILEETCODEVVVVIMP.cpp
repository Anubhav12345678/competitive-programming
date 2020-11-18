class Solution {
public:
    //Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute 
    // difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            long n = nums[i];
            
            if (i > k)
                window.erase(nums[i-k-1]); //win contains ind diff atmost k and from i to i-k there are k+1 elements
            
            auto pos = window.lower_bound(n - t);
            
            if (pos != window.end() && (*pos - n) <= t)
                return true;
            
            window.insert(n);
        }
        return false;
    }
};