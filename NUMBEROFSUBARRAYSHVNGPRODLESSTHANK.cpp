class Solution {
public:
    int solve(vector<int> &a,int k)
    {
        int n=a.size();
        int st=0,en=0,i,j,l,res=0,len,p=1;
        for(;en<n;en++)
        {
            p*=a[en];
            while(st<en&&p>=k)
                p/=a[st++];
            if(p<k)
            {
                len = en-st+1;
                res+=len;
            }
        }
        return res;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        return solve(nums,k);
    }
};