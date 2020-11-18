class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i,j,k,n=arr.size();
        int s=0;
        vector<int> l(n);
        int minl=INT_MAX/2;
        int ans=INT_MAX/2;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(i=0;i<n;i++){
            s+=arr[i];
            if(mp.count(s-target)) 
                minl = min(minl,i-mp[s-target]);
            l[i] = minl;
            mp[s]=i;
        }
        
        mp.clear();
        s=0;
        mp[0]=n;
        minl=INT_MAX/2;
        for(i=n-1;i>0;i--){
            s+=arr[i];
            if(mp.count(s-target)) 
                minl = min(minl,mp[s-target]-i);
            ans = min(ans,l[i-1]+minl);
            mp[s]=i;
        }
        
        return ans<=n?ans:-1;
    }
};
/*
Given an array of integers arr and an integer target.

You have to find two non-overlapping sub-arrays of arr each with sum equal target. There can be multiple answers so you
 have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.

*/