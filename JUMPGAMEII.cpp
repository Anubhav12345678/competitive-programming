 int jump(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n==1)
            return 0;
        if(n==0||nums[0]==0)
            return INT_MAX;
       int reach=0,lastreach=0,step=0;
        for(i=0;i<=reach&&i<n;i++)
        {
            if(i>lastreach)
            {
                lastreach=reach;
                step++;
                
            }
            reach = max(reach,i+nums[i]);
        }
        if(reach<nums.size()-1)
            return 0;
        return step;
    }