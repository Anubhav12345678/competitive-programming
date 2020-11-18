#include "solution.hpp"
using namespace std;

/*

Given a list of integers nums, return whether every sublist has at least 1 element in it which occurs once in the sublist.

Note: the intended solution should run \mathcal {O}(n)O(n) for random inputs on average.


*/
class Solution {
    public:
    bool rec(int l,int r,vector<int> &v,map<int,int> &mp){
        if(l>=r) return 1;
        int id=-1;
        int i=l,j=r;
        while(i<=j){
            if(mp[v[i]]==1)
            {
                id=i;
                break;
            }
            if(mp[v[j]]==1){
                id=j;
                break;
            }
            i++;
            j--;
        }
        if(id==-1) return 0;
        mp.erase(v[id]);
        map<int,int> nm;
        if(id<=(l+r)/2){
            for(i=l;i<id;i++)
            {
                nm[v[i]]++;
                mp[v[i]]--;
            }
            return rec(l,id-1,v,nm)&&rec(id+1,r,v,mp);
        }
        
        else
        {
            for(i=id+1;i<=r;i++){
                nm[v[i]]++;
                mp[v[i]]--;
            }
            return rec(l,id-1,v,mp)&&rec(id+1,r,v,nm);
        }
    }
    bool solve(vector<int>& nums) {
        // Write your code here
        int i,j,k,l,n=nums.size();
        map<int,int> mp;
        for(i=0;i<n;i++) mp[nums[i]]++;
        // for(auto it = mp.begin();it!=mp.end();it++)
        // if(it->second==1) break;
        // if(it==mp.end())
        // return 0;
        return rec(0,n-1,nums,mp);
        
        
    }
    
};
