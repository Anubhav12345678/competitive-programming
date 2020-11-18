class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i = 0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        sum/=2;
        int dp[nums.size()][sum+1];
        for(int i = 0;i<nums.size();i++)
        { //cout<<nums[i]<<" ";
            for(int j=0;j<=sum;j++)
            {
                if(i==0)
                {
                    if(j-nums[0]==0)
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                else if(j<nums[i])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]]||j==nums[i];
                //cout<<dp[i][j]<<" ";    
            }
            //cout<<endl;
        }
        return dp[nums.size()-1][sum];
    }
};