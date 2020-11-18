
/*
Given an array nums sorted in ascending order, return true if and only if you can split it into 1 or more subsequences
 such that each subsequence consists of consecutive integers and has length at least 3.

 

Example 1:

Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5






*/

//meeeee
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        unordered_map<int,int> cnt, mp;
//        mp[i] = number of subsequenes len>=3 ending at number i
        for(auto &i:nums) cnt[i]++;
        for(auto &i:nums)
        {
            if(!cnt[i]) continue;
            cnt[i]--;
            if(mp[i-1]>0)
            {
                mp[i-1]--;
                mp[i]++;
            }
            else if(cnt[i+1]>0&&cnt[i+2]>0)
            {
                cnt[i+1]--;
                cnt[i+2]--;
                mp[i+2]++;
            }
            else
                return 0;
        }
        return 1;
    }
};



class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> mp;
        int i,j,k,l;
        for(i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(i=nums.size()-1;i>=0;i--)
        {
            if(mp[nums[i]]==0) continue;
            int n=nums[i];
            for(j=0;mp[n]--<=mp[n-1];n--,j++);
                if(j<2) return 0;
        }
        return 1;
    }
};