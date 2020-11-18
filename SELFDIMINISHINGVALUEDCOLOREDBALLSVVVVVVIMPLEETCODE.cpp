#define ll long long
class Solution {
public:
    map<ll,ll,greater<ll>> mp;
    bool solve(ll m,ll T,vector<ll> &v)
    {
        for(auto &[n,cnt]: mp)
        {
            if(n<=m) break;
            T-=cnt*(n-m);
            if(T<=0) return 1;
        }
        return T<=0;
    }
    int maxProfit(vector<int>& in, int T) {
        ll i,j,k,l,m,a,b,c;
        ll mod=1e9+7;
        vector<ll> v(in.size());
        for(i=0;i<in.size();i++)  {v[i] = (ll)in[i];  mp[v[i]]++;}
        ll lo=0, hi=(ll)*max_element(v.begin(),v.end());
        while(lo<=hi)
        {
            ll m = (lo+hi)>>1;
            if(solve(m,T,v)) lo=m+1;
            else
                hi=m-1;
        }
        ll ans=0LL;
        for(auto &[n,cnt]: mp)
        {
            if(n<=lo) break;
            T-=cnt*(n-lo);
            ans = (ans+ ((((n+lo+1)*(n-lo))/2)*cnt)%mod)%mod;
        }
        if(T) ans = (ans+lo*T%mod)%mod;
        return ans;
    }
};
/*


You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.

The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have
 in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction,
  there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell
   more to the customer).

You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. 
You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in 
any order.

Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return
 it modulo 109 + 7.

 


*/