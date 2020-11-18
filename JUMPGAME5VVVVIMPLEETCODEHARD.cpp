

/*

Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and 0 < x <= d.
i - x where: i - x >= 0 and 0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between
 i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.




*/




class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int i,j,k,l,n=arr.size();
        vector<pair<int,int>> v;
        for(i=0;i<n;i++)
            v.push_back(make_pair(arr[i],i));
        sort(v.begin(),v.end());
        int dp[10010];
        memset(dp,0,sizeof(dp));
        for(auto it=v.begin();it!=v.end();it++)
        {
            int x = it->first;
            i=it->second;
            dp[i]=1;
            for(j=i+1;j<n&&j<=i+d&&arr[i]>arr[j];j++)
                dp[i]  =max(dp[i],dp[j]+1);
            for(j=i-1;j>=0&&j>=i-d&&arr[i]>arr[j];j--)
                dp[i]  =max(dp[i],dp[j]+1);
        }
        return *max_element(dp,dp+n);
    }
};