
/*

In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3


*/
//mee
class Solution {
public:
    vector<int> par;
    int find(int x)
    {
        if(par[x]==x) return x;
        else
            return find(par[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1,0);
        int i,j,k,l;
        vector<int> res(2);
        for(i=1;i<=n;i++) par[i]=i;
        for(i=0;i<n;i++) 
        {
            int x = find(edges[i][0]);
            int y= find(edges[i][1]);
            if(x!=y)
                par[y]=x;
            else
            {
                res[0]=edges[i][0];
                res[1]=edges[i][1];
            }
        }
        return res;
    }
};


class Solution {
public:
    bool haspath(int cur,int goal,map<int,vector<int>> &graph,set<int> &vis)
    {
        if(cur==goal)
            return 1;
        if(graph.find(cur)==graph.end()||graph.find(goal)==graph.end())
            return 0;
        vis.insert(cur);
        for(auto next:graph[cur])
        {
            if(vis.find(next)!=vis.end())
                continue;
            if(haspath(next,goal,graph,vis))
                return 1;
        }
        return 0;
            
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        map<int,vector<int>> graph;
        int i,j,k,l;
        // set<int> vis;
        for(i=0;i<n;i++)
        {
            int u  = edges[i][0];
            int v = edges[i][1];
            set<int> vis; // naye vale edge k liye nye vale edge bnao purane vale purani edge k liye the
            if(haspath(u,v,graph,vis))
                return edges[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
};