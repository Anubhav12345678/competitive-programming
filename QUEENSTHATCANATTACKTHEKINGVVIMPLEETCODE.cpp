

/*
On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that represents the positions of the Black Queens, and a pair of coordinates king that
 represent the position of the White King, return the coordinates of all the queens (in any order) that can attack the King.

 

Example 1:



Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output: [[0,1],[1,0],[3,3]]
Explanation:  
The queen at [0,1] can attack the king cause they're in the same row. 
The queen at [1,0] can attack the king cause they're in the same column. 
The queen at [3,3] can attack the king cause they're in the same diagnal. 
The queen at [0,4] can't attack the king cause it's blocked by the queen at [0,1]. 
The queen at [4,0] can't attack the king cause it's blocked by the queen at [1,0]. 
The queen at [2,4] can't attack the king cause it's not in the same row/column/diagnal as the king.


*/


class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
       int n = queens.size();
        int g[8][8];
        memset(g,0,sizeof(g));
        vector<vector<int>> res;
        for(auto it:queens)
        {
            g[it[0]][it[1]] = 1;
        }
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};
        int i,j,k,l;
        for(i=0;i<8;i++)
        {
            for(k=1;;k++)
            {
                int nx = dx[i]*k+king[0],ny = dy[i]*k+king[1];
                if(nx>=0&&nx<8&&ny>=0&&ny<8)
                {
                    if(g[nx][ny])
                    {
                        res.push_back({nx,ny});
                        break;
                    }
                }
                else
                    break;
            }
        }
        return res;
    }
};