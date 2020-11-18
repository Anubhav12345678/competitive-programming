int solve(const string text,const string pat){
    int i,j,k,l,n=text.size();
    int m = pat.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;
    for(i=1;i<=m;i++)
    if(pat[i-1]=='*')
    dp[0][i] = dp[0][i-2];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(text[i-1]==pat[j-1]||pat[j-1]=='.')
            dp[i][j] = dp[i-1][j-1];
            else if(pat[j-1]=='*'){
                dp[i][j] = dp[i][j-2];
                if(pat[j-2]=='.'||pat[j-2]==text[i-1])
                dp[i][j] = dp[i][j]||dp[i-1][j];
            }
            else
            dp[i][j]=0;
        }
    }
    return dp[n][m];
}

int Solution::isMatch(const string A, const string B) {
    return solve(A,B);
}
/*

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)


*/