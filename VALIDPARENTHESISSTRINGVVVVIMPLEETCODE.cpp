

/*

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid.
 We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True





*/





/*

JAVA BETTER
*/


class Solution {
public:
    bool checkValidString(string s) {
        int i,j,k,l,n=s.size();
        if(n==0)
            return 1;
        // int st,i,j,k,l;
        
     bool dp[n][n];
        memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
    {
        if(s[i]=='*') dp[i][i]=1;
        if(i<n-1&&(s[i]=='('||s[i]=='*')&&(s[i+1]==')'||s[i+1]=='*'))
            dp[i][i+1]=1;
    }
    for(l=2;l<n;l++)
    {
        for(i=0;i+l<n;i++)
        {
            if(s[i]=='*'&&dp[i+1][i+l]==1)
                dp[i][i+l]=1;
            else if(s[i]=='('||s[i]=='*')
            {
                for(k=i+1;k<=i+l;k++)
                {
                    if((s[k]==')'||s[k]=='*')&&(k==i+1||dp[i+1][k-1])&&(k==i+l||dp[k+1][i+l]))
                        dp[i][i+l]=1;
                }
            }
        }
    }
        return dp[0][n-1];
        
    }
};


class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int i,j,k,l;
        int lo=0,hi=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                lo++;
                hi++;
            }
            else if(s[i]==')')
            {
                if(lo>0) lo--;
                hi--;
            }
            else
            {
                if(lo>0)
                    lo--;
                hi++;
            }
            if(hi<0)
                return 0;
        }
        return lo==0;
    }
};