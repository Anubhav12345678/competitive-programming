class Solution {
public:
    // static bool comp(vector<int> a,vector<int> b)
    // {
    //     return a[1]<b[1];
    // }
    int maxEvents(vector<vector<int>>& events) {
     int n=events.size(), ans=0;
       pair<int,int> b[n];
        int i,j,k,l;
        for(i=0;i<n;i++)
        {
            b[i] = make_pair(events[i][0],events[i][1]);
        }
        sort(b,b+n);
        // int ans=0;
        map<int,int> mp;
        for(k=0,i=1,j=0;i<=100000;i++)
        {
            while(j<n&&b[j].first==i)
            {
                mp[b[j].second]++;
                j++;
            }
            while(mp.size()&&mp.begin()->first<i)
                mp.erase(mp.begin());
            if(mp.size())
            {
                ans++;
                mp.begin()->second--;
                if(!mp.begin()->second)
                    mp.erase(mp.begin());
                
            }
        }
        return ans;
    }
};