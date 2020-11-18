
/*

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers
 exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen 
anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.





*/







class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1 = str1.size();
        int l2= str2.size();
        int i,j,k,l;
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        for(i=1;i<=l1;i++)
        {
            for(j=1;j<=l2;j++)
            {
                dp[i][j] = str1[i-1]==str2[j-1]?(1+dp[i-1][j-1]):(max(dp[i][j-1],dp[i-1][j]));
            }
        }
        string res="";
        while(l1||l2)
        {
            char c;
            if(l1==0) c = str2[--l2];
            else if(l2==0) c = str1[--l1];
            else if(str1[l1-1]==str2[l2-1]) c = str1[--l1]=str2[--l2];
            else if(dp[l1][l2]==dp[l1-1][l2]) c=str1[--l1];
            else if(dp[l1][l2]==dp[l1][l2-1]) c = str2[--l2];
            res.push_back(c);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};