

/*

Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and 
return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all
 nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.

*/


class Solution {
public:
    void dfs(vector<vector<int>> &res,vector<int> &tmp,vector<vector<int>> &g,int x,vector<bool> &vis){
        if(x==(g.size()-1))
        {
            tmp.push_back(x);
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        
        vis[x]=true;
        tmp.push_back(x);
        for(auto y:g[x]){
            if(!vis[y]){
                dfs(res,tmp,g,y,vis);
            }
        }
        tmp.pop_back();
        vis[x]=false;
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> vis(graph.size(),false);
        dfs(res,tmp,graph,0,vis);
        return res;
        
    }
};