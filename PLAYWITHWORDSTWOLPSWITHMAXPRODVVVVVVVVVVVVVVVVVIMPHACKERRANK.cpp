int playWithWords(string s) {
    /*
     * Write your code here.
     Shaka and his brother have created a boring game which is played like this:

They take a word composed of lowercase English letters and try to get the maximum possible score by building exactly
 2 palindromic subsequences. The score obtained is the product of the length of these 2 subsequences.

Let's say  and  are two subsequences from the initial string. If  &  are the smallest and the largest positions
 (from the initial word) respectively in  ; and  &  are the smallest and the largest positions (from the initial word)
  respectively in , then the following statements hold true:
,
, &
.
i.e., the positions of the subsequences should not cross over each other.

Hence the score obtained is the product of lengths of subsequences  & . Such subsequences can be numerous for a larger
 initial word, and hence it becomes harder to find out the maximum possible score. Can you help Shaka and his brother find this out?

Input Format

Input contains a word  composed of lowercase English letters in a single line.

Constraints


each character will be a lower case english alphabet.

Output Format

Output the maximum score the boys can get from .

     */
    ll i,j,k,l,n=s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    // memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
    dp[i][i]=1;
    for(i=0;i<n-1;i++)
    {
    if(s[i]==s[i+1]) dp[i][i+1]=2;
    else
    dp[i][i+1]=1;
    }
    for(l=3;l<=n;l++){
        for(i=0;i<n-l+1;i++){
            j=i+l-1;
            if(s[i]==s[j]) dp[i][j] = 2+dp[i+1][j-1];
            else
            dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        }
    }

    ll left[n];
    ll right[n];
    right[n-1] = 1;
    left[0]=1;
    for(i=n-2;i>=0;i--)
    right[i] = max(right[i+1],dp[i][n-1]);
    for(i=1;i<n;i++)
    left[i] = max(left[i-1],dp[0][i]);

    long long int ans=0;
    for(i=0;i<n-1;i++)
    {
        long long int x = (long long int)left[i]*(long long int)right[i+1];
        ans = max(ans,x);
    }
    return ans;
}