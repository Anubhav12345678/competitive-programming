#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define MAX 100006
/*
n=no  of units
m=types of coins
c[m] = values of coins
*/
// memset(dp,-1,sizeof(dp));
ll noofways(ll n,ll m,ll c[])
{
//     // if(dp[n][m]!=-1)
//     // return dp[n][m];
//     // If n is 0 then there is 1 solution  
//     // (do not include any coin) 
//     if(n==0)
//     return 1;
//      // If n is less than 0 then no  
//     // solution exists 
//     if(n<0)
//     return 0;
//     // If there are no coins and n  
//     // is greater than 0, then no 
//     // solution exist 
//     if(m<=0&&n>=1)
//     return 0;
//     // dp[n][m] = noofways(n,m-1,c)+noofways(n-c[m-1],m,c);
//     return noofways(n,m-1,c)+noofways(n-c[m-1],m,c);;
  ll table[n+1][m];
  ll i,j,x,y;
  for(i=0;i<m;i++)
  table[0][i]=1;//to represent 0 value using i coins there is 1 way
  for(i=1;i<=n;i++)
  {
      for(j=0;j<m;j++)
      {
          x = (i-c[j]>=0)?table[i-c[j]][j]:0;//including the jth type of coin
          //not include jth type coin 
          y = (j>=1)?table[i][j-1]:0;
          table[i][j] = x+y;
      }
  }
  return table[n][m-1];
}
int main() {
    ll n,m,c[100001],i,j;
    cin>>n>>m;
    for(i=0;i<m;i++)
    cin>>c[i];
    // ll dp[n+1][m+1];
    // memset(dp,-1,sizeof(dp));
    cout<<noofways(n,m,c)<<endl;
    // your code goes here
    return 0;
}

///COINCHANGEVVIMPLEETCODE
class Solution {
public:
    int solve(int pos,int m,int dp[][10001],vector<int> &c)
    {
        if(pos>=c.size())
        {
            if(m==0) return 0;
            return INT_MAX/2;
        }
            int &res = dp[pos][m];
            if(res!=-1) return res;
            int ret=INT_MAX/2;
            for(int i=pos;i<c.size();i++)
            {
                if(c[i]<=m)
                {
                    ret = min(ret,1+solve(pos,m-c[i],dp,c));
                    ret = min(ret,1+solve(pos+1,m-c[i],dp,c));
                }
                else
                  ret  = min(ret,solve(pos+1,m,dp,c));
            }
            return res=ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        int dp[coins.size()+1][10001];
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,amount,dp,coins);
        if(ans==INT_MAX/2) return -1;
        return ans;
    }
};