class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i,j,k,l,n=nums.size();
        int cnt=0,ans=1;
        int pre=0;
        multiset<int> st;
        for(i=0;i<n;i++)
        {
            st.insert(nums[i]);
            while((*st.rbegin()-*st.begin())>limit)
                st.erase(st.find(nums[pre++]));
            ans = max(ans,i-pre+1);
        }
        return ans;
    }
};