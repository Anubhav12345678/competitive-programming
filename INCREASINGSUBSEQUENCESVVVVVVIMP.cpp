
/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.

 

Example:

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]


*/




class Solution {
public:
   vector<vector<int>>result;
set<vector<int>>s;
void dfshelper(vector<int>& nums,int i,vector<int>res,int prev)
{
  if(res.size()>=2&&s.find(res)==s.end())
  {
   result.push_back(res);
   s.insert(res);
  } 
  if(i==nums.size())
   return;   
  if(nums[i]>=prev)
  {
  res.push_back(nums[i]);//Include current element
  dfshelper(nums,i+1,res,nums[i]);
  res.pop_back();//Exclude current element-Backtrack
  }
  dfshelper(nums,i+1,res,prev);
  return;
}
vector<vector<int>> findSubsequences(vector<int>& nums) 
{
 vector<int>res;
 dfshelper(nums,0,res,INT_MIN);
 return result;
}
};