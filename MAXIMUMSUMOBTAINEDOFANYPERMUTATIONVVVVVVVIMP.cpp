class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int i,j,k,l,n,m;
        n=nums.size();
        m = requests.size();
        vector<int> a(n+10,0);
        for(auto v:requests){
            a[v[0]]++;
            a[v[1]+1]--;
        }
        
        for(i=1;i<a.size();i++)
            a[i]+=a[i-1];
        
        sort(a.begin(),a.end(),greater<>());
        sort(nums.begin(),nums.end(),greater<>());
        
        int ans=0;
        int mod = 1e9+7;
        for(i=0;i<n;i++){
            ans = (ans+a[i]*nums[i])%mod;
        }
        
        return ans;
    }
};
/*
We have an array of integers, nums, and an array of requests where requests[i] = [starti, endi]. The ith request asks 
for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi]. Both starti and endi are 0-indexed.

Return the maximum total sum of all requests among all permutations of nums.

Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
Output: 19
Explanation: One permutation of nums is [2,1,3,4,5] with the following result: 
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
Total sum: 8 + 3 = 11.
A permutation with a higher total sum is [3,5,4,2,1] with the following result:
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
Total sum: 11 + 8 = 19, which is the best that you can do.


*/