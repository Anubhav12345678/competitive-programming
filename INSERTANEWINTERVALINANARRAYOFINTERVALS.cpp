class Solution {
public:
    bool doesoverlap(vector<int> a,vector<int> b)
    {
        return max(a[0],b[0])<=min(a[1],b[1]);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<int> a(newInterval.begin(),newInterval.end());
        vector<vector<int>> res;
        if(n==0)
        {
            res.push_back(a);
            return res;
        }
        int i,j,k,l,p,q;
        // case 1&&2
        if(a[0]<=intervals[0][0]&&a[1]>=intervals[n-1][1])
        {
            res.push_back(a);
            return res;
        }
        if(a[1]<intervals[0][0]||a[0]>intervals[n-1][1])
        {
            if(a[1]<intervals[0][0])
            {
                res.push_back(a);
            }
            for(i=0;i<n;i++)
                    res.push_back(intervals[i]);
            if(a[0]>intervals[n-1][1])
               res.push_back(a);
            return res;
        }
        bool overlap=false;
        for(i=0;i<n;i++)
        {
            overlap = doesoverlap(intervals[i],a);
            if(!overlap)
            {
                res.push_back(intervals[i]);
                if(i<n-1&&a[0]>intervals[i][1]&&a[1]<intervals[i+1][0])
                    res.push_back(a);
                continue;
            }
            vector<int> tmp(2);
            tmp[0] = min(intervals[i][0],a[0]);
            while(i<n&&overlap)
            {
                tmp[1] = max(intervals[i][1],a[1]);
                if(i==n-1)
                    overlap=false;
                else
                    overlap = doesoverlap(intervals[i+1],a);
                i++;
            }
            res.push_back(tmp);
            i--;
        }
        return res;
    }
};