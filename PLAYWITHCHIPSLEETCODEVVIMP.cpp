class Solution {
public:
    int cost(vector<int> &c,int x)
    {
        int cnt=0;
        for(int i=0;i<c.size();i++)
        {
            cnt+=(abs(x-c[i]))%2;
        }
        return cnt;
    }
    int minCostToMoveChips(vector<int>& chips) {
        int n = chips.size();
        int i,j,k,l;
        int ans=INT_MAX;
        int maxpos=chips[0],minpos=chips[0];
        for(i=1;i<n;i++)
        {
            maxpos = max(maxpos,chips[i]);
            minpos = min(minpos,chips[i]);
        }
        l=minpos;
        int r=maxpos,m;
        while(l<=r)
        {
            m = l+(r-l)/2;
            int c = cost(chips,m);
            if(c<ans)
            {
                ans=c;
                l=m+1;
            }
            else
                r=m-1;
        }
        return ans;
    }
};