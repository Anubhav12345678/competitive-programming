class Solution {
public:/*
In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What 
is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left,
 and right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the
  plus sign, only the relevant area of the plus sign is checked for 1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000

*/
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int i,j,k,n=mines.size();
        vector<vector<int>> g(N,vector<int>(N,N));
        
        int l=0,r=0,d=0,u=0,res=0;
        for(auto m:mines)
            g[m[0]][m[1]]=0;
        for(i=0;i<N;i++){
            
            for(j=0, l=0;j<N;j++) // left to right
            {
                g[i][j] = min(g[i][j], (l=(g[i][j]==0)?0:(l+1)));
            }
            
            for(k=N-1,r=0;k>=0;k--){ //right to left
                g[i][k] = min(g[i][k], (r=(g[i][k]==0)?0:(r+1)));
            }
            
            for(j=0, u=0;j<N;j++){ // top to bottom
                g[j][i] = min(g[j][i], (u = (g[j][i]==0)?0:(u+1)));
            }
            
            for(k=N-1, d=0;k>=0;k--){ // bootom to top
                g[k][i] = min(g[k][i], (d = (g[k][i]==0)?0:(d+1)));
            }
        }
        
        for(i=0;i<N;i++){
            for(j=0;j<N;j++)
                 res = max(res,g[i][j]);
            cout<<endl;
        }
        return res;
    }
};