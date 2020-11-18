#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums, int target) {
        // Write your code here
        int i,j,k,l,n=nums.size();
        multiset<int> s;
        sort(nums.begin(),nums.end());
        for(i=n/2;i<n;i++)
        {
            // auto it = s.lower_bound(nums);
            s.insert(nums[i]);
        }
        int ans=0;
        for(i=0;i<n/2;i++){
            auto it= s.lower_bound(nums[i]+target);
            if(it!=s.end()){
                ans++;
                s.erase(it);
            }
            else
            break;
        }
        return ans;
    }
};
