class Solution {
public:
 bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        vector<int> visited(n, 0);
        return dfs(nums, visited, k, 0, sum/k);
    }
    
    bool dfs(vector<int>& nums, vector<int>& visited, int k, int cur, int target) {
        if(k == 1) {
            return true;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(visited[i]) continue;
            int t = cur + nums[i];
            if(t > target) break; //!!!we can never reach target since all the nums are positive
            visited[i] = 1;
            if(t == target && dfs(nums, visited, k - 1, 0, target))
                return true;
            else if(dfs(nums,visited, k, cur + nums[i], target))
                return true;
            visited[i] = 0;
        }
        return false;
    }
};