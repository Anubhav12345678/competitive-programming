class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i,j,l,a,b,c;
        map<int,int> m;
        int sum=0,ans=0;
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)
                ans++;
            if(m.find(sum-k)!=m.end())
                ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};