class Solution {
public:
    //INCREASINGTRIPLETSEQUENCEO(N)timeO(1)space
    bool increasingTriplet(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n<3) return 0;
        int fm=INT_MAX,sm=INT_MAX;
        for(i=0;i<n;i++)
        {
            if(nums[i]<fm)
            {
                fm = nums[i];
            }
            else if(nums[i]>fm&&nums[i]<sm)
                sm=nums[i];
            else if(nums[i]>sm) return true;
        }
        return 0;
    }
};