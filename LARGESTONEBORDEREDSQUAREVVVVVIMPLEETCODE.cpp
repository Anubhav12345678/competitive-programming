class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& g) {
        int i,j,k,l,n=g.size();
        int m = g[0].size();
        vector<vector<int>> ver(n,vector<int>(m,0)), hor(n,vector<int>(m,0));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(g[i][j]==1)
                {
                  hor[i][j] =  (j==0)?1:(hor[i][j-1]+1);
                  ver[i][j] = (i==0)?1:ver[i-1][j]+1;
                }
            }
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int st = min(hor[i][j],ver[i][j]);
                while(st>ans)
                {
                    if(hor[i-st+1][j]>=st&&ver[i][j-st+1]>=st)
                        ans = st;
                    st--;
                }
            }
        }
        return ans*ans;
    }
};
/*

Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.

 

Example 1:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
Example 2:

Input: grid = [[1,1,0,0]]
Output: 1


*/