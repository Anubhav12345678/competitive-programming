int bfs(vector<vector<int>> &tree,int start,int &en)
{
    // int curnode=
    set<int> vis;
    queue<pair<int,int>> q;
    int cur = start;
    int curlvl=0;
    q.push({cur,curlvl});
    // vis.ins
    while(!q.empty())
    {
        pair<int,int> tmp = q.front();
        q.pop();
        vis.insert(cur);
        cur=tmp.first;
        curlvl = tmp.second;
        for (auto neighbour : tree[cur]) {
            if (vis.count(neighbour) == 0) {
                q.push({neighbour, curlvl + 1});
            }
        }
    }
    en =  cur;
    return curlvl;
    
    
}
int Solution::solve(vector<int> &A) {
    vector<int> par = A;
    int i,j,k,l,n=A.size();
    vector<vector<int>> tree(n,vector<int>());
    int root;
    for(i=0;i<n;i++)
    {
        if(A[i]==-1)
        {
            root=i;
            continue;
        }
        tree[A[i]].push_back(i);
        tree[i].push_back(A[i]);
    }
    int pathst,pathen;
    bfs(tree, root, pathst);// go from root to one end that en in pathst
    int max_distance = bfs(tree, pathst, pathen);// go from pathst to other en givingmax distance

    return max_distance;
    
    
}
