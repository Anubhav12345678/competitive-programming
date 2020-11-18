class Solution {
public:
    int longestAwesome(string s) {
        int i,j,k,l,n=s.size();
        map<int,int> mp;
        int mask=0,ans=0;
        mp[0]=-1;
        for(i=0;i<n;i++){
            mask^=(1<<(s[i]-'0'));
            if(mp.find(mask)!=mp.end())
                ans = max(ans,i-mp[mask]);
            
            for(int d=0;d<=9;d++){
                int newmask = mask^(1<<d);
                if(mp.find(newmask)!=mp.end())
                ans = max(ans,i-mp[newmask]);
            }
            
            if(mp.find(mask)==mp.end())
                mp[mask]=i;
        }
        
        return ans;
    }
};
/*
Given a string s. An awesome substring is a non-empty substring of s such that we can make any number 
of swaps in order to make it palindrome.

Return the length of the maximum length awesome substring of s.

 

Example 1:

Input: s = "3242415"
Output: 5
Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
Example 2:

Input: s = "12345678"
Output: 1


*/