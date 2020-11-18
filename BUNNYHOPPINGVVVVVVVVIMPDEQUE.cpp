#include "solution.hpp"
using namespace std;
#define ll long long
#define ff first
#define se second
class Solution {
    public:
    int solve(vector<int>& nums, int k) {
        ll i,j,l,n=nums.size();
        if(n==0) return 0;
        deque<pair<ll,ll>>  q;
        ll res = nums[0];
        pair<ll,ll> p = {res,0LL};
        q.push_back(p);
        for(i=1;i<n;i++)
        {
            while(!q.empty()&&(i-k)>q.front().se)
            q.pop_front();
            res = nums[i]+q.front().ff;
            while(!q.empty()&&q.back().ff>=res)
            q.pop_back();
            q.push_back({res,i});
        }
        return res;
    }
};
/*
You are given a list of integers nums and an integer k. The nums list represents the costs of landing at each
 index. You must start at index 0 and end at the last index of nums. In each step you can move from some position
  X to any position up to k steps away.

You want to minimize the sum of the costs of the positions you land at. What is this minimum sum?

Constraints

Length of nums is ≤ 100,000
1 ≤ k ≤ 100,000
Example 1
Input

nums = [1, 2, 3, 4, 5]
k = 2
Output

9


*/