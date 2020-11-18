class Solution {
public:
    /*

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.
    */
    int longestSubarray(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        // int s = accumulate(nums.begin(),nums.end(),0);
        // if(s==n) return 0;
        // int dp1[n]={0};
        // int dp2[n]={0};
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        dp1[0] = (nums[0]==1)?1:0;
        dp2[n-1] = (nums[n-1]==1)?1:0;
        for(i=1;i<n;i++)
        {
            if(nums[i]==0) dp1[i]=0;
            else
                dp1[i] = dp1[i-1]+1;
        }
        
        for(i=n-2;i>=0;i--){
            if(nums[i]==0) dp2[i]=0;
            else
                dp2[i] = dp2[i+1]+1;
        }
        // for(i=0;i<n;i++){
        //     cout<<"dp1["<<i<<"] = "<<dp1[i]<<endl;
        //     cout<<"dp2["<<i<<"] = "<<dp2[i]<<endl;
        // }
        
        int ans=0;
        for(i=0;i<n;i++){
            int x = (i>0)?dp1[i-1]:0;
            int  y = (i<n-1)?dp2[i+1]:0;
            ans = max(ans,x+y);
        }
        return ans;
        
    }
};