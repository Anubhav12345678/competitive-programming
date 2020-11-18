class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
     map<int,int> mp;
        for(auto num: nums)
            if(num) mp[num]+=num;
        int present=INT_MIN,ans=0,pre1=0,pre2=0;
        for(auto it: mp)
        {
            int key = it.first;
            int val = it.second;
            if(key>present+1)
                ans = pre1+val;
            else
                ans = max(pre1,pre2+val);
            pre2=pre1;
            pre1=ans;
            present=key;
        }
        return ans;
    }
};