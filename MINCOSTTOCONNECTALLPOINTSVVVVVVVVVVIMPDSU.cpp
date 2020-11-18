#define ff first
#define se second
class Solution {
public:
    // struct p{
    //     int x,y,dis;
    // };
    /*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where
 |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between 
any two points.

    */
    static bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
       return a.ff<b.ff;
    }
    vector<int> par;
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    bool merge(int a,int b){
        int x = find(a);
        int y = find(b);
        if(x==y) return false;
        par[y]=x;
        return true;
    }
    int dis(int x1,int y1,int x2,int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int i,j,k,l,n,m;
        n = points.size();
        par.resize(n);
        for(i=0;i<n;i++) par[i]=i;
        vector<pair<int,pair<int,int>>> cost;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                cost.push_back({dis(x1,y1,x2,y2),{i,j}});
            }
        }
        
        sort(cost.begin(),cost.end(),comp);
        int ans=0;
        for(i=0;i<cost.size();i++){
            int x = cost[i].se.ff;
            int y = cost[i].se.se;
            if(merge(x,y))
                ans+=cost[i].ff;
        }
        
        return ans;
        
    }
};