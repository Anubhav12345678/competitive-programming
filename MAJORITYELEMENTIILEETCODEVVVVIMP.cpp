class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(); 
 if(n<2) return nums;
 int elem1=nums[0]; int elem2=0;
 int count1=1; int count2=0;
 for(int i=1;i<n;i++)
 {
  if(nums[i]==elem1) count1++;
  else if(nums[i]==elem2) count2++;
  else if(count1==0)
  {
      elem1=nums[i];
      count1=1;
  }
  else if(count2==0)
  {
      elem2=nums[i];
      count2=1;
  }
  else
  {
      count1--;
      count2--;
  }
 }
 count1=0;count2=0;
 for(int i=0;i<n;i++)
 {
     if(nums[i]==elem1) count1++;
     else if(nums[i]==elem2) count2++;
 }
 vector<int>result;
 if(count1>n/3) result.push_back(elem1);
 if(count2>n/3) result.push_back(elem2);
 return result;
    }
};