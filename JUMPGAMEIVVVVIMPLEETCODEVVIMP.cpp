/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.




*/




class Solution {
public:
    int minJumps(vector<int>& a) {
        int i,j,k,l,n=a.size();
        int dp[n];
        memset(dp,1e9+7,sizeof(dp));
        map<int,vector<int>> mp;
        for(i=0;i<n;i++) mp[a[i]].push_back(i);
        dp[0]=0;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int id = q.front();
            q.pop();
            if(id+1<n&&dp[id+1]>dp[id]+1)
            {
                dp[id+1]=1+dp[id];
                q.push(id+1);
            }
            if(id-1>=0&&dp[id-1]>dp[id]+1)
            {
                dp[id-1]=dp[id]+1;
                q.push(id-1);
            }
            for(auto p:mp[a[id]])
            {
                if(p!=id&&dp[p]>dp[id]+1)
                {
                    dp[p]=dp[id]+1;
                    q.push(p);
                }
            }
            mp.erase(a[id]);
        }
        return dp[n-1];
    }
};