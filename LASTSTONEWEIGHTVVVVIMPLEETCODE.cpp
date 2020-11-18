/*

We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

SAME AS MIN SUBSETSUM DIFF


*/






class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int i,j,k,l,n=stones.size();
        int s = accumulate(stones.begin(),stones.end(),0);
        cout<<s<<endl;
        bool t[n+1][s+1];
        for(i=0;i<=n;i++)
            t[i][0]=1;
        for(i=1;i<=s;i++)
            t[0][i]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=s;j++)
            {
                if(j>=stones[i-1])
                    t[i][j] = t[i-1][j]||t[i-1][j-stones[i-1]];
                else
                    t[i][j]  = t[i-1][j];
            }
        }
        int ans = 1e9+7;
        for(i=s/2;i>=0;i--)
            if(t[n][i])
            {
                ans = s-2*i;
                break;
            }
        return ans;
    }
};