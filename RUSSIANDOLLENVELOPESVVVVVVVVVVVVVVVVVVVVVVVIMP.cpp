class Solution {
public:


    /*

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).




    */
    static bool comp(vector<int> a,vector<int> b)
    {
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        int i,j,k,l,n=env.size();
        if(n==0||n==1) return n;
        sort(env.begin(),env.end(),comp);
        int lis[n];
        int ans=1;
        for(i=0;i<n;i++)
        {
            lis[i]=1;
            for(j=0;j<i;j++)
                if((env[i][0]>env[j][0])&&env[j][1]<env[i][1]&&lis[i]<lis[j]+1)
                    lis[i] = lis[j]+1;
            ans = max(ans,lis[i]);
        }
        return ans;
    }
};