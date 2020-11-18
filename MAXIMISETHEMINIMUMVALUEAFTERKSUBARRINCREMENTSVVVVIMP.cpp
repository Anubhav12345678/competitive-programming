#include "solution.hpp"
using namespace std;
/*
You are given a list of integers nums and integers size and k. Consider an operation where we take a
 contiguous sublist of length size and increment every element by one.

Given that you can perform this operation k times, return the largest minimum value possible in nums.



*/
#define ll long long
bool poss(vector<ll> &v,ll m,ll sz,ll k){
    ll i,j,l,n=v.size();
    vector<ll> use(n+1,0);
    ll ans=0LL,inc=0LL;
    for(i=0;i<n;i++){
        if(i>=sz)
        inc-=use[i-sz];
        use[i] = max(0LL,m-(ll)v[i]-inc);
        ans+=use[i];
        inc+=use[i];
    }
    return ans<=k;
}
class Solution {
    public:
    int solve(vector<int>& nums, int size, int k) {
        // Write your code here
        ll n = nums.size();
        if(n == 0){
            return 0;
        }
        ll st = *min_element(nums.begin(),nums.end());
        ll en = *max_element(nums.begin(),nums.end())+k;
        ll ans=0,i,j,l,m;
        vector<ll> v(nums.begin(),nums.end());
        while(st<=en){
            m = (st+en)/2;
            if(poss(v,m,size,k))
            {
                ans=m;
                st=m+1;
            }
            else
            en=m-1;
        }
        
        return ans;
    }
};
