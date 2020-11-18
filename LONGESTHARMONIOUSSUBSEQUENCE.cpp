/*We define a harmounious array as an array where the difference between its maximum value and its minimum value is exactly 1.*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int mini = nums[0],i,j,k,l,maxi,n=nums.size();
        if(n==0) return 0;
        int st=0,nxtst=1,res=0;
        for(i=1;i<n;i++)
        {
            if(nums[i]-mini>1)
            {
                st=nxtst++;
                mini = nums[st];
                i--;
            }
            else if(nums[i]-mini==1)
            {
                res = max(res,i-st+1);
                if(nums[i]!=nums[i-1])
                    nxtst=i;
            }
        }
        return res;
        
    }
};