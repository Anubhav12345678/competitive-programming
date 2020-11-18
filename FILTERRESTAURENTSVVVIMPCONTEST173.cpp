class Solution {
public:
    // static bool comp(const vector<int> a,const vector<int> b)
    // {
    //     if(a[1]!=b[1])
    //         return a[1]>b[1];
    //     else
    //         return a[0]>b[0];
    // }
    vector<int> filterRestaurants(vector<vector<int>>& r, int vf, int mx, int md) {
        // vector<int>
        int n = r.size();
        int i,j,k,l;
        vector<int> res;
        vector<vector<int>> tmp;
        if(vf==1)
        {
            for(i=0;i<n;i++)
            {
                if(r[i][2]==1&&r[i][3]<=mx&&r[i][4]<=md)
                {
                   tmp.push_back({r[i][1],r[i][0]});
                }
            }
            sort(tmp.rbegin(),tmp.rend());
            for(i=0;i<tmp.size();i++)
                res.push_back(tmp[i][1]);
            // sort(res.begin(),res.end(),comp);
            return res;
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(r[i][3]<=mx&&r[i][4]<=md)
                {
                   tmp.push_back({r[i][1],r[i][0]});
                }
            }
            sort(tmp.rbegin(),tmp.rend());
            for(i=0;i<tmp.size();i++)
                res.push_back(tmp[i][1]);
            // sort(res.begin(),res.end(),comp);
            return res;
        }
    }
};