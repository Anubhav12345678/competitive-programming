class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        res.clear();
        int i,j,k,l,a,b,c,x,y,z,low,high,n=nums.size();
        sort(nums.begin(),nums.end());
        for(i=0;i<n-3;i++)
             {
                 for(j=i+1;j<n-2;j++)
                 {
                     k = target-(nums[i]+nums[j]);
                     low=j+1,high=n-1;
                     while(low<high)
                     {
                         if(nums[low]+nums[high]==k)
                         {
                             vector<int> tmp;
                             tmp.clear();
                             tmp.push_back(nums[i]);
                             tmp.push_back(nums[j]);
                             tmp.push_back(nums[low]);
                             tmp.push_back(nums[high]);
                             sort(tmp.begin(),tmp.end());
                             if(find(res.begin(),res.end(),tmp)==res.end())
                             res.push_back(tmp);
                             low++;
                             high--;
                         }
                         else if(nums[low]+nums[high]<k)
                             low++;
                         else
                             high--;
                     }
                 }
             }
             return res;
    }
};