bool compare(pair<int,int > a,pair<int,int > b) {
    return a.second<b.second;
}
void godfs(int i,vector<pair<int, int>> adj[],bool isvisited[],int *cnt) {
    isvisited[i] = true;
    sort(adj[i].begin(),adj[i].end(),compare);
    
    vector<pair<int,int > >::iterator it;
    for(it = adj[i].begin();it != adj[i].end();it++) {
        if(!isvisited[it->first]){
            *cnt = *cnt + it->second;
        godfs(it->first,adj,isvisited,cnt);}
    }
}
int spanningTree(int V, int e, vector<pair<int, int>> adj[])
{
    bool isvisited[V] = {false};
    int val = 0,cnt= 0;
    for(int i = 0;i<V;i++) {
        if(!isvisited[i])
            godfs(i,adj,isvisited,&cnt);
    }
    return cnt;
    // return total;
    
    // Your code here
   
}