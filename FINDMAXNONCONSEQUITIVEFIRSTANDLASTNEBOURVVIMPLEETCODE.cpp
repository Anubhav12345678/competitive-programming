class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return nums[0]>nums[1]?nums[0]:nums[1];
        int i,j,k,l,a,b,c,inc1=nums[0],inc2=nums[1],exc1=0,exc2=0;
        for(i=1;i<n-1;i++)
        {
            int p = max(inc1,exc1);
            inc1=exc1+nums[i];
            exc1 = p;
        }
        for(i=2;i<n;i++)
        {
            int p=max(inc2,exc2);
            inc2 = exc2+nums[i];
            exc2=p;
        }
        return max(max(exc1,exc2),max(inc1,inc2));
    }
};