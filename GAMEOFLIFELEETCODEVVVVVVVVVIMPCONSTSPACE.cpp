class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int i,j,k,r,l,n=board.size();
        int m = board[0].size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int cnt=0;
                for(l = max(0,i-1);l<min(i+2,n);l++)
                {
                    for(r=max(0,j-1);r<min(m,j+2);r++)
                        cnt+=(board[l][r]>1)?board[l][r]-2:board[l][r];
                }
                // cnt==3 
                // if board[i][j]=1 means live neighour==2 so it lives till next gen
                // if board[i][j]==0 means live neighour==3 so it lives till next gen
                //  cnt-board[i][j]==3 
                // if board[i][j]=1 means live neighour==2 so it lives till next gen
                // if board[i][j]==0 means live neighour==3 so it lives till next gen
                
                if(cnt==3||cnt-board[i][j]==3) board[i][j]+=2;
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(board[i][j]>1) board[i][j]=1;
                else
                    board[i][j]=0;
    }
};
/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]




*.