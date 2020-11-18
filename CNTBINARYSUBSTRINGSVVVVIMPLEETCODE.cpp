/*

Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and 
all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.




*/




class Solution {
public:
    int countBinarySubstrings(string s) {
        int n  =s.size();
        int i,j,k,l;
        int pre=0,cur=1,ans=0;
        for(i=1;i<n;i++)
        {
            if(s[i-1]==s[i])
                cur++;
            else
            {
                ans+=min(pre,cur);
                pre=cur;
                cur=1;
            }
        }
        ans+=min(pre,cur);
        return ans;
    }
};