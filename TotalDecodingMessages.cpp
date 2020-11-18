//INTERVIEWBIT
int Solution::numDecodings(string s) {

int n = s.length();

if(n == 1) 
  return (s[0] == '0')? 0 : 1;

if(s[0] == '0')
  return 0;

//dp[i] no of ways upto i;
// {
// | dp[i+1] if s[i] > ‘0’
// |
// dp[i] += |
// |
// | dp[i+2] if
// {

int dp[n+1];


//dp[i] holds number of decode from i to n-1;

memset(dp,0,sizeof(dp));
dp[n]=1;
dp[n-1] = (s[n-1] == '0')? 0 : 1; 
// dp[n] = 1;

for(int i=n-2; i>=0 ;i--)
{
   if(s[i] > '0')
   {
     dp[i] += dp[i+1]%(1000000000+7);
   }
    
   if(s[i] == '1'|| s[i] == '2' && s[i+1] < '7')
   {
       dp[i] += dp[i+2]%(1000000000+7);
   }
}
  
return dp[0]%(1000000000+7);
}


















class Solution {
public:
    int numDecodings(string s) {
        int i,j,k,l,n=s.size();
        // if(n==1)
        //     return 1;
        int dp[100005]={0};
        dp[0]=1;
        dp[1] = (s[0]!='0')?1:0;
        for(i=2;i<=n;i++)
        {
            if(s[i-1]>'0')
                dp[i] = dp[i-1];
            int val = (s[i-2]-'0')*10+(s[i-1]-'0');
            if(val<=26&&val>=10)
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};