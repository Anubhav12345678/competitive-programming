/*

Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.
 

Example 1:



Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]


*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int i,j,k,l,n=nums.size();
        vector<int> res;
        map<int,list<int>> mp;
        for(i=0;i<n;i++)
        {
            for(j=0;j<nums[i].size();j++)
                mp[i+j].push_front(nums[i][j]);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            list<int> v = it->second;
            // sort(v.begin(),v.end(),greater<>());
            for(auto it2=v.begin();it2!=v.end();it2++)
                res.push_back(*it2);
        }
        return res;
    }
};