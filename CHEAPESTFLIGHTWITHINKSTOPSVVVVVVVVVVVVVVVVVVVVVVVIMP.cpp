class Solution {
    //DFS+ PRUNING
    //PRUNING REMOVING UNNECESSARY CALLS
public:
    void solve(vector<vector<int>> &adj,vector<vector<int>> &cost,int src,int dst,int K,int &fare,int totcost,vector<bool> &vis)
    {
        if(K<-1) return;
        if(src==dst)
        {
            fare = min(fare,totcost);
            return;
        }
        vis[src]=true;
        for(int i=0;i<adj[src].size();i++)
        {
            if(!vis[adj[src][i]]&&(totcost+cost[src][adj[src][i]])<=fare)
            {
                solve(adj,cost,adj[src][i],dst,K-1,fare,totcost+cost[src][adj[src][i]],vis);
            }
        }
        vis[src]=false;
        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> adj(n);
        vector<vector<int>> cost(n+1,vector<int>(n+1));
        int fare=INT_MAX;
        for(int i=0;i<flights.size();i++)
        {
            // cout<<flights[i][0]<<" "<<flights[i][1]<<" "<<flights[i][2]<<endl;
            adj[flights[i][0]].push_back(flights[i][1]);
            cost[flights[i][0]][flights[i][1]]=flights[i][2];
        }
        // cout<<adj[0].size();
        // for(int i=0;i<adj[0].size();i++)
        //     cout<<adj[0][i]<<" ";
        
        vector<bool> vis(n+1,false);
        solve(adj,cost,src,dst,K,fare,0,vis);
        return (fare==INT_MAX)?-1:fare;
    }
};