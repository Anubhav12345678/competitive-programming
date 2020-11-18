


/*






*/



class Solution {
public:
    bool dfs(vector<int> &nums,vector<int> &side,int st)
    {
        if(side[0]==0&&side[1]==0&&side[2]==0&&side[3]==0)
            return 1;
        if(st>=nums.size()) return 0;
        for(int i=0;i<4;i++)
        {
            if(side[i]<nums[st]) continue;
            side[i]-=nums[st];
            if(dfs(nums,side,st+1))
                return 1;
            side[i]+=nums[st];
        }
        return 0;
    }
    bool makesquare(vector<int>& nums) {
        if (nums.empty()) return false;
        int i,j,k,l,n=nums.size();
        sort(nums.begin(),nums.end(),greater<>());
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s%4) return 0;
        int len = s/4;
        vector<int> side(4,len);
        return dfs(nums,side,0);
    }
};