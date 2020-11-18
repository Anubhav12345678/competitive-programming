    class Solution {
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n  = intervals.size();
        int i,j,k,l,a,b,c;
        if(n==0||n==1)
            return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int res=0;
        int lst=0;
        for(i=1;i<n;i++)
        {
            if(intervals[i][0]>=intervals[lst][1])
            {
                lst=i;
            }
            else
            {
                res++;
                lst=intervals[lst][1]<intervals[i][1]?lst:i;
            }
        }
        return res;
    }
};