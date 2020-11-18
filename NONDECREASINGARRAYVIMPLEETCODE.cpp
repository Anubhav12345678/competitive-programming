class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(),i,j,k,l;
        if(n==0||n==1)
            return 1;
         int maxi[n],mini[n];
        maxi[0]=nums[0];
        mini[n-1]=nums[n-1];
        int c1=0,c2=0;
        for(i=1;i<n;i++)
        {
            maxi[i] = max(maxi[i-1],nums[i]);
        }
        for(i=n-2;i>=0;i--)
        {
            mini[i] = min(mini[i+1],nums[i]);
        }
        for(i=0;i<n;i++)
            if(nums[i]<maxi[i])
                c1++;
        for(i=n-1;i>=0;i--)
            if(nums[i]>mini[i])
                c2++;
        return c1<2||c2<2;
    }
};