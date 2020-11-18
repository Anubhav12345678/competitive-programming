#define ll long long
class Solution {
public:
    /*

Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and 
maximum element on it is less or equal than target.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)




    */
    ll power(ll a,ll ind,ll mod)
    {
        if(ind==0) return 1;
        ll x = power(a,ind/2,mod)%mod;
        if(ind%2==0)
            return (x*x)%mod;
        else
            return (x*x*a)%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        int i,j,k,l,n=nums.size();
        sort(nums.begin(),nums.end());
        long long int ans=0;
        ll mod = 1e9+7,res=0LL;
        j=n-1;
        for(i=0;i<n;i++)
        {
            //the lowest value should be nums[i]
                //nums[i+1]~nums[j] can be included or excluded
                //so there are 2^(j-i) combinations
            while(j>=i&&(nums[i]+nums[j])>target)
                j--;
            if(j<i) break;
            ll a = 2*1LL;
            res = (res+(ll)(power(a,(j-i),mod)))%mod;
        }
        return res;
    }
};