class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        set<int> st;
        for(i=0;i<n;i++)
            st.insert(nums[i]);
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(st.find(nums[i]-1)==st.end())
            {
                j=nums[i];
                while(st.find(j)!=st.end())
                    j++;
                ans = max(ans,j-nums[i]);
            }
        }
        return ans;
    }
};