
/*

Your algorithms have become so good at predicting the market
 that you now know what the share price of Wooden Orange Toothpicks Inc. (WOT) will be for the next number of days.

Each day, you can either buy one share of WOT, sell any number of 
shares of WOT that you own, or not make any transaction at all.
 What is the maximum profit you can obtain with an optimum trading strategy?

For example, if you know that prices for the next two days are , you
 should buy one share day one, and sell it day two for a profit of .
  If they are instead , no profit can be made so you don't buy or sell stock those days.



*/


long max(long a,long b)
{
    return (a>b)?a:b;
}
long stockmax(vector<int> prices) {
   long res=0LL;
   int i,j,k,l,n=prices.size();
   long maxi = prices[n-1];
   for(i=n-2;i>=0;i--)
   {
       maxi = max(maxi,(long)prices[i]);
       res+=(long)(maxi-prices[i]);
   }
   return res;
}
