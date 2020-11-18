class Solution {
public:
    int solve(vector<int> &v,int k)
    {
        int i,j,l,ans=0;
        int cnt[20010]={0};
        memset(cnt,0,sizeof(cnt));
        int p=0,diff=0;
        for(i=0;i<v.size();i++)
        {
            if(++cnt[v[i]]==1)
                diff++;
            while(diff>k)
            {
                if(--cnt[v[p++]]==0)
                    diff--;
            }
            ans+=i-p+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& a, int K) {
        return solve(a,K)-solve(a,K-1);
    }
};
/*
Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of 
different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

 

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].



*/