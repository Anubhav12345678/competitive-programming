class Solution{
public:

 vector<int> findPair(vector<int>& vec, int target){
   if (vec.size() == 0) return {};
   vector<int> result;
 
   unordered_map<int, int> map;
   int curMax = INT_MIN;
 
   for(int i = 0; i < vec.size(); i++){
     int toLook = target - 30 - vec[i];
   
     if( map.find(toLook) != map.end()){
       if( max(toLook, vec[i]) > curMax){
         curMax = max(toLook, vec[i]);
         result = {i, map[toLook]};
       }
     }
   
     map[vec[i]] = i;
   }
   return result;
 }
};
/*
Given a list of positive integers nums and an int target, return indices of the two numbers such that they add up to a target - 30.

Conditions:

You will pick exactly 2 numbers.
You cannot pick the same element twice.
If you have muliple pairs, select the pair with the largest number.
Example 1:

Input: nums = [1, 10, 25, 35, 60], target = 90
Output: [2, 3]
Explanation:
nums[2] + nums[3] = 25 + 35 = 60 = 90 - 30

*/