

/*

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]




*/



class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;
        sort(nums.begin(),nums.end());
        int i,j,k,l;
        vector<int> dp(n+1),re(n+1),path(n+1);
        dp[0]=1;
        int maxind,maxlen=0;
        for(i=1;i<n;i++)
        {
            dp[i]=1;
            for(j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    path[i]=j;
                }
            }
            if(dp[i]>maxlen)
            {
                maxlen = dp[i];
                maxind=i;
            }
        }
        i=0;
        while(i<maxlen)
        {
            re[i++] = nums[maxind];
            maxind = path[maxind];
        }
        // reverse(re.begin(),re.end());
        vector<int> ve;
        while(i>0)
        {
            ve.push_back(re[--i]);
        }
        return ve;
    }
};