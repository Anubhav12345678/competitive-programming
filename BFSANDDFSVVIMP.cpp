
// DFS of a graph
void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s]=true;
    cout<<s<<" ";
    for(auto i=g[s].begin();i!=g[s].end();++i)
    {
        if(!vis[*i])
        dfs(*i,g,vis);
    }
    
    // Your code here
}
// BFS of  agraph
void bfs(int s, vector<int> adj[], bool vis[])
{
    // Your code here
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        if(!vis[s])
        {
            vis[s] = true;
            cout<<s<<" ";
            
        }
        
        for(int i=0;i<adj[s].size();i++)
        {
            if(!vis[adj[s][i]])
                q.push(adj[s][i]);
        }
    }
  
}