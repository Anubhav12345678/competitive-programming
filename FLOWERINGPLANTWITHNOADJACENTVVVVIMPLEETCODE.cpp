
/*


You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, 
they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden. 
 The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

 

Example 1:

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]



*/





class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        int i,j,k,l;
        vector<int> adj[N+1];
        int m = paths.size();
        for(i=0;i<m;i++)
        {
            paths[i][0]--;
            paths[i][1]--;
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<bool > vis(N,false);
        k=1;
        vector<int> res(N,-1);
        for(i=0;i<N;i++)
        {
            set<int> ava;
            for(auto p:adj[i])
            {
                if(res[p]!=-1)
                    ava.insert(res[p]);
            }
            for(j=1;j<=4;j++)
                if(ava.count(j)==0)
                {
                    res[i]=j;
                    break;
                }
        }
        return res;
        
    }
};