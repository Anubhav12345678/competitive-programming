class Solution {
public:
    int dis(int x,int y)
    {
        return x*x+y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int i,j,k,l,n=points.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(auto v:points)
        {
            int x = v[0];
            int y = v[1];
            pq.push(make_pair(dis(x,y),make_pair(x,y)));
        }
        i=0;
        vector<vector<int>> res;
        while(i<K)
        {
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            vector<int> v;
            v.push_back(p.second.first);
            v.push_back(p.second.second);
            i++;
            res.push_back(v);
        }
        return res;
        
    }
};