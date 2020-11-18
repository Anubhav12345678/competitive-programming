class Solution {
public:
    unordered_set<int> vis,cyc,safe;
    bool dfs(vector<vector<int> > &g,int i){
        if(safe.find(i)!=safe.end()) return true;
        if(cyc.find(i)!=cyc.end()) return false;
        if(vis.find(i)!=vis.end()) return false;
        vis.insert(i);
        for(auto node:g[i]){
            if(!dfs(g,node)){
                cyc.insert(node);
                return 0;
            }
        }
        safe.insert(i);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vis.clear();
        cyc.clear();
        safe.clear();
        vector<int> ans;
        for(int i=0;i<graph.size();i++)
            if(dfs(graph,i))
                ans.push_back(i);
        return ans;
    }
};
/*
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.



*/