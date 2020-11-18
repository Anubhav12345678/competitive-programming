class Solution {
public:
    vector<int> par;
    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }
    
    void merge(int i,int j){
        int x = find(i);
        int y = find(j);
        if(x!=y) 
            par[y]=x;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        par.resize(n);
        int i,j,k,l,m;
        for(i=0;i<n;i++) par[i]=i;
        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                    merge(i,j);
            }
        }
        int cnt=0;
        for(i=0;i<n;i++) if(par[i]==i) cnt++;
        return n-cnt;
    }
};
/*

On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
*/