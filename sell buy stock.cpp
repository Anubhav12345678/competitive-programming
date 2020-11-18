#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Interval
{
public:
	int buy;
	int sell;
}
void sellbuy(ll prices[],ll n)
{
	if(n==1)
		return;  //as we need atleast 2 days  
  ll count=0;
  Interval sol[10005];
  ll i=0;
  while(i<n-1)
  {
  	//find local minima note that limit is n-2 as we are compairing present ele to next elle
  	while(i<n-1&&prices[i+1]<=prices[i])
  		i++;
  	//now we have reached the local minima
  	if(i==n-1)// if we reach the end break
  		break;
  	sol[count].buy = i++;
  	//find local maxima note that limit is n-1 as we are compairing present ele to prevoius elle
    while(i<n&&prices[i-1]<=prices[i])
    	i++;
    //strore the index of maxima
    sol[count].sell = i-1;

    //increment count of buy sell pairs
    count++;


  }
  if(count==0)
  	cout<<"there is no day when buying the stock is going to give us profit";
  else
  {
  	for(i=0;i<count;i++)
  		cout<<"Buy on day "<<sol[i].buy<<" and sell on day "<<sol[i].sell;
  	return;
  }
}

//driver fun
int main()
{
	//stock prices on consequitive days
	int prices[] = {100,180,260,310,40,535,695};
	int n = sizeof(prices)/sizeof(prices[0]);
	sellbuy(prices,n);
	return 0;
}

//me LEETCODE
class Solution {
public:
    struct interval
    {
        int buy;
        int sell;
    };
    int maxProfit(vector<int>& prices) {
        int i=0,j,k,l,n=prices.size();
        int res=0;
        struct interval sol[100005];
        int cnt=0;
        while(i<n-1)
        {
            while(i<n-1&&prices[i+1]<=prices[i])
                i++;
            if(i==n-1)
                break;
            sol[cnt].buy=i++;
            while(i<n&&prices[i-1]<=prices[i])
                i++;
            sol[cnt].sell=i-1;
            cnt++;
        }
        for(i=0;i<cnt;i++)
        {
            res+=prices[sol[i].sell]-prices[sol[i].buy];
        }
        return res;
    }
};