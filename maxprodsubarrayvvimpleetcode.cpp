class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int prevMaxProd = nums[0];
        int prevMinProd = nums[0];
        int currMinProd = nums[0];
        int currMaxProd = nums[0];
        int res = nums[0];
        
        for(int i=1; i < nums.size(); i++)
        {
            currMaxProd = max(prevMaxProd*nums[i], max(prevMinProd*nums[i], nums[i]));
            currMinProd = min(prevMaxProd*nums[i], min(prevMinProd*nums[i], nums[i]));
            res = max(res, currMaxProd);
            
            prevMaxProd = currMaxProd;
            prevMinProd = currMinProd;
        }
        return res;
    }
};