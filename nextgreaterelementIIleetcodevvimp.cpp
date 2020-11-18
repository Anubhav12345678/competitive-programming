class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       vector<int> output(nums.size(),INT_MIN);
        stack<int> s;
        
        
        // Next greater element
        for(int i = 0; i<nums.size();i++) {
            while(!s.empty() && nums[s.top()] < nums[i]) {
                output[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        
        if(s.empty()) return output;
        
        for(int  i = 0 ; i<nums.size() && !s.empty() ; i++) {
            while(!s.empty() && nums[s.top()] < nums[i]) {
                output[s.top()] = nums[i];
                s.pop();
            }
        }
        
        while(!s.empty()) {
            output[s.top()] = -1;
            s.pop();
        }
        
        return output;
            
    }
};