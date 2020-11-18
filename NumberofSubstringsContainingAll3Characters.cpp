
/*

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab",
 "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1




*/





class Solution {
public:
    int numberOfSubstrings(string s) {
        int i,j,k,l,n=s.size();
        int ca=0,cb=0,cc=0,st=0,ans=0,cnt=0;
        int left=0,right=0;
        map<char,int> mp;
        for(left=0,right=0;left<n;left++)
        {
            if(left>0)
            {
                if(--mp[s[left-1]]==0)
                    cnt--;
            }
            while(right<n&&cnt<3)
            {
                if(++mp[s[right++]]==1)
                    cnt++;
            }
            if(cnt==3)
                ans+=n-right+1;
        }
        return ans;
    }
};