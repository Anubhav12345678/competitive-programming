class Solution {
public:
    int dp[505][505],sum[505];
    int f(int l,int r) {
        if(dp[l][r]!=-1) return dp[l][r];
        if(l == r) return 0;
        int ret=0;
        for(int k=l;k<r;++k) {
            int tmp = 0;
            if(sum[r]-sum[k] > sum[k]-sum[l-1]) {
                tmp = sum[k]-sum[l-1]+f(l,k);
            } else if(sum[r]-sum[k] < sum[k]-sum[l-1]) {
                tmp = sum[r]-sum[k]+f(k+1,r);
            } else {
                tmp = max(sum[r]-sum[k]+f(k+1,r), sum[k]-sum[l-1]+f(l,k));
            }
            ret=max(ret,tmp);
        }
        return dp[l][r]=ret;
    }
    int stoneGameV(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        int n=a.size();
        for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i-1];
        return f(1,n);
    }
};
/*
User Accepted:806
User Tried:1473
Total Accepted:838
Total Submissions:3059
Difficulty:Hard
There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates
 the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the 
 maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob
  lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's is initially zero.

Return the maximum score that Alice can obtain.


*/