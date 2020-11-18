/*

You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].




*/





class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
            st.insert(nums[i]);
        vector<int> freq(n);
        map<int,int> ranks;
        int rank=0;
        for(auto it: st)
        {
            ranks[it] = rank++;
        }
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            int p = ranks[nums[i]];
            ans.push_back(accumulate(freq.begin(),freq.begin()+p,0));
            freq[p]++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};