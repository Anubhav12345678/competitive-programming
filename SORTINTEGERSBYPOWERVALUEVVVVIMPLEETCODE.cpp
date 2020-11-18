

/*

The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in
 ascending order, if two or more integers have the same power value sort them by ascending order.

Return the k-th integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that
 the power of x is will fit in 32 bit signed integer.

 

Example 1:

Input: lo = 12, hi = 15, k = 2
Output: 13
Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
The power of 13 is 9
The power of 14 is 17
The power of 15 is 17
The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.






*/





class Solution {
public:
    map<int,int> mp;
    int ans[30001];
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second!=b.second)
            return a.second<b.second;
        else
            return a.first<b.first;
    }
    int solve(int n)
    {
        if(n==1)
            return 0;
        if(mp.find(n)!=mp.end())
            return mp[n];
        if(n%2==0)
            return mp[n] = 1+solve(n/2);
        return mp[n] = 1+solve(3*n+1);
    }
    void fill()
    {
        for(int i=1;i<=1000;i++)
        {
            ans[i] = solve(i);
        }
    }
    int getKth(int lo, int hi, int k) {
        fill();
        cout<<"ans[3] = "<<ans[3]<<endl;
        vector<pair<int,int>> v(hi-lo+1);
        for(int i=lo;i<=hi;i++)
        {
            v[i-lo].first = i;
            v[i-lo].second = ans[i];
            cout<<v[i-lo].second<<endl;
        }
        sort(v.begin(),v.end(),comp);
        return v[k-1].first;
    }
};