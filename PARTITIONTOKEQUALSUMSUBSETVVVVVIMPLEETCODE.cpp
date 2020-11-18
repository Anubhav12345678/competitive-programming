
/*

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets
 whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.



*/





class Solution {
public:
    bool solve(vector<int> &v,int subset[],bool taken[],int reqsum,int k,int n,int curind,int limind)
    {
        if(subset[curind]==reqsum)
        {
            if(curind==(k-2))
                return 1;
            return solve(v,subset,taken,reqsum,k,n,curind+1,n-1);
        }
        for(int i=limind;i>=0;i--)
        {
            if(taken[i]) continue;
            int tmp = subset[curind]+v[i];
            if(tmp<=reqsum)
            {
            subset[curind]+=v[i];
            taken[i]=1;
            bool nxt = solve(v,subset,taken,reqsum,k,n,curind,i-1);
            subset[curind]-=v[i];
            taken[i]=0;
            if(nxt)
                return 1;
            }
        }
        return 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1)
            return 1;
        int n = nums.size();
        int i,j,l;
        int sum=0,reqsum;
        for(i=0;i<n;i++) sum+=nums[i];
        if(sum%k) return 0;
        reqsum = sum/k;
        int subset[k];
        bool taken[n];
        memset(taken,0,sizeof(taken));
        memset(subset,0,sizeof(subset));
        subset[0] = nums[n-1];
        taken[n-1] = 1;
        return solve(nums,subset,taken,reqsum,k,n,0,n-1);
    }
};