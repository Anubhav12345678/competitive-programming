vector<int> solve(string &s){
    int i,j,k,l,n=s.size();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    // dp[i][j] represents max lcs from substring of len i starting from first index and substring of len j string from last index vvvimp 
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(s[i-1]==s[n-j])
            dp[i][j] = dp[i-1][j-1]+1;
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            // cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
        }
    }
    int ans1=-1, ans2 = -1;
    for(i=1;i<=n;i++){
        if(dp[i][n-i]>ans2)
        {
            ans2=dp[i][n-i];
            ans1=i;
        }
    }
    return {ans1,ans2};
    
}

vector<int> Solution::maxLCS(string A) {
    return solve(A);
    
}
/*
Defining substring
For a string P with characters P1, P2 ,…, Pq, let us denote by P[i, j] the substring Pi, Pi+1 ,…, Pj.

Defining longest common subsequence(LCS)
A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order
 of the remaining elements. LCS(A, B) of 2 sequences A and B is a subsequence, with maximal length, which is common to both the
  sequences.

Given a string S with small alphabet characters S1, S2 ,…, SN, return an array with two elements. First is the smallest j (1 ≤ j < N) 
for which LCS(S[1, j], rev(S[j + 1, N])) is maximal and second is the maximal value of LCS(S[1, j], rev(S[j + 1, N])).
Here, rev(A) denotes reverse of string A.
*/