class Solution {
public:
    bool solve(vector<int>  &v,int x, int h)
    {
        if(x==0)
            return 0;
        int i,j,k,l,n=v.size(),ans=0;
        for(i=0;i<n;i++)
        {
            if(v[i]<=x)
                ans++;
            else
            {
                int a=  v[i]/x;
                int b = v[i]%x;
                ans+=a;
                if(b>0)
                    ans++;
            }
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int i,j,k,l,n=piles.size();
        int r;
        l=1;
        r = *max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=r)
        {
            int m  =(l+r)/2;
            if(solve(piles,m,H))
            {
                ans=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        // cout<<"l = "<<l<<" r = "<<r<<endl;
        return ans;
    }
};