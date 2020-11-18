class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int i,j,k,l;
        int inf = 1e9+7;
        // int dis[n][n];
        vector<vector<int>> dis(n,vector<int>(n,inf));
        for(i=0;i<n;i++)
            dis[i][i]=0;
        for(auto& e:edges)
        {
            dis[e[0]][e[1]]=min(dis[e[0]][e[1]],e[2]);
            dis[e[1]][e[0]]=min(dis[e[1]][e[0]],e[2]);
        }
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    dis[i][j] = min(dis[i][j],(dis[i][k]+dis[k][j]));
            }
        }
        int few=n+n,ans=-1;
        for(i=0;i<n;i++)
        {
            int cur=0;
            for(j=0;j<n;j++)
                if(dis[i][j]<=distanceThreshold) cur++;
            if(cur<=few)
            {
                few=cur;
                ans=i;
            }
        }
        return ans;
        
        // memset(dis,INT_MAX,sizeof(dis));
    }
};