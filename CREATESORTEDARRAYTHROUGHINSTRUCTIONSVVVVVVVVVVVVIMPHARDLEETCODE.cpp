#define ll long long
class Solution {
public:
    vector<ll> t,a;
    ll N = 1e5+1;
    void update(ll st,ll en,ll x,ll node=1)
    {
        if(st==en&&st==x)
        {
            t[node] = a[x];
            return;
        }
        ll m = st+(en-st)/2;
        if(x<=m)
            update(st,m,x,node*2+1);
        else
            update(m+1,en,x,node*2+2);
        t[node] = t[2*node+1]+t[2*node+2];
    }
    ll query(ll qs,ll qe,ll st,ll en,ll node=1)
    {
        if(qs>en||qe<st) return 0;
        if(qs<=st&&qe>=en) return t[node];
        ll m  = (st+en)/2;
        ll x = query(qs,qe,st,m,node*2+1);
        ll y= query(qs,qe,m+1,en,node*2+2);
        return x+y;
    }
    
    int createSortedArray(vector<int>& in) {
        
        t.resize(4*N,0);
        a.resize(N,0);
        ll ans=0;
        ll mod =1e9+7;
        for(auto i: in)
        {
            ll x = query(0,i-1,0,N-1);
            ll y = query(i+1,N-1,0,N-1);
            ll z  =min(x,y);
            ans = (ans+z)%mod;
            a[i]++;
            update(0,N-1,i);
        }
        return ans%mod;
    }
};
/*
Given an integer array instructions, you are asked to create a sorted array from the elements in instructions. You start with an empty container nums. For each element from left to right in instructions, insert it into nums. The cost of each insertion is the minimum of the following:

The number of elements currently in nums that are strictly less than instructions[i].
The number of elements currently in nums that are strictly greater than instructions[i].
For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].

Return the total cost to insert all elements from instructions into nums. Since the answer may be large, return it modulo 109 + 7

 

Example 1:

Input: instructions = [1,5,6,2]
Output: 1
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
The total cost is 0 + 0 + 0 + 1 = 1.






**/