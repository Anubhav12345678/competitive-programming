
/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any
 connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates 
that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree 
as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, 
those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


*/


class Solution {
public:
    /*

The basic idea is "keep deleting leaves layer-by-layer, until reach the root."

Specifically, first find all the leaves, then remove them. After removing, some nodes will become new leaves. 
So we can continue remove them. Eventually, there is only 1 or 2 nodes left. If there is only one node left, 
it is the root. If there are 2 nodes, either of them could be a possible root.

Time Complexity: Since each node will be removed at most once, the complexity is O(n).

Thanks for pointing out any mistakes.


    */
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> cnt(n,0);
        int i,j,k,l,m;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            cnt[e[0]]++;
            cnt[e[1]]++;
        }
        
        queue<int> q;
        vector<int> res;
        for(i=0;i<n;i++)
            if(cnt[i]<=1) q.push(i);
        
        while(n>2){
            int sz = q.size();
            n-=sz;
            for(i=0;i<sz;i++){
                int x = q.front();
                q.pop();
                for(auto y:adj[x]){
                    if(--cnt[y]==1)
                        q.push(y);
                }
            }
            
        }
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};