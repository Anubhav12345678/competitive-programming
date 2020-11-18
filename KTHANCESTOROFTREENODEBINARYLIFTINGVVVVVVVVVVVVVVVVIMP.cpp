/*
You are given a tree with n nodes numbered from 0 to n-1 in the form of a parent array where
 parent[i] is the parent of node i. The root of the tree is node 0.

Implement the function getKthAncestor(int node, int k) to return the k-th ancestor of the given 
node. If there is no such ancestor, return -1.

The k-th ancestor of a tree node is the k-th node in the path from that node to the root.

 

Example:



Input:
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

Output:
[null,1,0,-1]

Explanation:
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2);  // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3);  // returns -1 because there is no such ancestor

*/
class TreeAncestor {
public:
    int dp[50004][29];
    int MAX;
    void solve(int u,int v){
        dp[v][0] = u;
        for(int i=1;i<=MAX;i++){
            dp[v][i] = dp[dp[v][i-1]][i-1];
            if(dp[v][i]==-1)
                return;
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        memset(dp,-1,sizeof(dp));
        MAX = (int)ceil(log2(n));
        for(int i=1;i<n;i++)
            solve(parent[i],i);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<=MAX;i++){
            if(k&(1<<i)){
                node = dp[node][i];
                if(node==-1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */