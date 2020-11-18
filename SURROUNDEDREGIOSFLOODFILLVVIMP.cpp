/*

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
 Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected
  if they are adjacent cells connected horizontally or vertically


*/

class Solution {
public:
    void floodfill(vector<vector<char>>& board,int n,int m,char prev,char nc,int x,int y)
    {
        if(x>=n||x<0||y>=m||y<0)
            return;
        if(board[x][y]!=prev)
            return;
        board[x][y]=nc;
        floodfill(board,n,m,prev,nc,x+1,y);
        floodfill(board,n,m,prev,nc,x-1,y);
        floodfill(board,n,m,prev,nc,x,y+1);
        floodfill(board,n,m,prev,nc,x,y-1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n==0)
            return;
        int m = board[0].size();
        if(m==0)
            return;
        int i,j,k,l;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(board[i][j]=='O')
                    board[i][j]='-';
        }
        for(i=0;i<m;i++)
            if(board[0][i]=='-')
                floodfill(board,n,m,'-','O',0,i);
        for(i=0;i<n;i++)
            if(board[i][m-1]=='-')
                floodfill(board,n,m,'-','O',i,m-1);
        for(i=m-1;i>=0;i--)
            if(board[n-1][i]=='-')
                floodfill(board,n,m,'-','O',n-1,i);
        for(i=n-1;i>=0;i--)
            if(board[i][0]=='-')
                floodfill(board,n,m,'-','O',i,0);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(board[i][j]=='-')
                    board[i][j]='X';
            
    }
};