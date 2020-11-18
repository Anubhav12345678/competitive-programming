class Solution {
public:
    vector<int> par;
    int find(int x){
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }
     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n  =edges.size();
         par.resize(n+1,0);
         vector<int> first,second;
         for(auto &e:edges){
             if(par[e[1]]==0)
                 par[e[1]]=e[0];
             else{
                 first = {par[e[1]],e[1]};
                 second=e;
                 e[1]=0;// discard this edge
             }
         }
         for(int i=0;i<=n;i++) par[i]=i;
         for(auto e:edges){
             if(e[1]==0) continue;
             int x = find(e[0]);
             int y = find(e[1]);
             if(x==y) return first.empty() ? e : first;
             par[x]=y;
         }
         
         return second;
         
    }
};
/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node
 (the root) for which all other nodes are descendants of this node, plus every node has 
 exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes 
(with distinct values 1, 2, ..., N), with one additional directed edge added. 
The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair 
[u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes.
 If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
*/
//https://github.com/grandyang/leetcode/issues/685