class Solution {
public:
    /*
    You are given a sorted array consisting of only integers where every element appears exactly 
    twice, except for one element which appears exactly once. Find this single element that appears only once.
    */
    int singleNonDuplicate(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        // int res=0;
        // for(i=0;i<n;i++)
        //     res=res^nums[i];
        // return res;
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        int st=0,en=n-1;
        while(st<=en)
        {
            if(st==en)
                return nums[st];
            int mid = st+(en-st)%2;
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                    st=mid+2;
                else
                    en=mid;
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                    st=mid+1;
                else
                    en=mid-1;
            }
        }
        return -1;
    }
};