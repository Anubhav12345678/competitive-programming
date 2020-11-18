class Solution {
public:
   void dfs(int src,vector<int> adj[],vector<int>& vis){
    if(vis[src]==1){
        return;
    }
    vis[src]=1;
    for(int i=0;i<adj[src].size();i++){
        dfs(adj[src][i],adj,vis);
    }
    return;
}
bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
    vector<int> adj[n];
    vector<int> indegre(n,0);
    for(int i=0;i<n;i++){
        int x=l[i];
        int y=r[i];
        if(x!=-1){
            indegre[x]++;
            adj[i].push_back(x);
        }
        if(y!=-1){
            indegre[y]++;
            adj[i].push_back(y);
        }
    }
    for(int i=0;i<n;i++){
        if(indegre[i]==2){
            return false;
        }
    }
    int temp=0;
    int ind=0;
    for(int i=0;i<n;i++){
        if(indegre[i]==0){
            ind=i;
            temp=1;
            break;
        }
    }
    if(temp==0){
        return false;
    }
    for(int i=0;i<n;i++){
        if(adj[i].size()>2){
            return false;
        }
    }
    vector<int> vis(n,0);
    dfs(ind,adj,vis);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            return false;
        }
    }
    return true;
    
}
};