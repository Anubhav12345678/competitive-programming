class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> res;
        res.clear();
        int i,j,k,l;
        map<int,int> mp;
        for(auto num:nums2)
        {
            while(!st.empty())
            {
                int t = st.top();
                if(t<num)
                {
                    mp[t]=num;
                    st.pop();
                }
                else
                    break;
            }
            st.push(num);
        }
        for(auto num:nums1)
        {
            if(mp.find(num)!=mp.end())
                res.push_back(mp[num]);
            else
                res.push_back(-1);
        }
        return res;
    }
};