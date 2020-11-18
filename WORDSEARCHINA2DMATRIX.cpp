/*INTERVIEBIT*/
bool dfs(vector<string> &A, string B, int i, int j, int index)
{
    if(index==B.size())
    return true;
    if(i<0||i>=A.size()||j<0||j>=A[i].length()||(B[index]!=A[i][j]))
    return false;
    bool found=dfs(A, B, i+1, j, index+1)
    ||dfs(A, B, i-1, j, index+1)
    ||dfs(A, B, i, j+1, index+1)
    ||dfs(A, B, i, j-1, index+1);
    return found;
}
int Solution::exist(vector<string> &A, string B) {
    int n  =A.size();
    int m = A[0].size();
    int i,j,k,l;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(B[0]==A[i][j]&&dfs(A,B,i,j,0))
            return 1;
        }
    }
    return 0;
    
}




class Solution {
public:
    bool check(vector<vector<char>>& board,int row,int col,string s,int k)
    {
        int m = board.size();
        int n = board[0].size();
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        if(board[row][col]!=s[k])
            return 0;
        int len = s.size();
        if(k>=len-1)
            return true;
        int i,j,l;
        char t = board[row][col];
        board[row][col]='#';
        for(i=0;i<4;i++)
        {
            int pi = row+dx[i];
            int pj = col+dy[i];
            if(pi>=0&&pi<m&&pj>=0&&pj<n&&board[pi][pj]==s[k+1])
                if(check(board,pi,pj,s,k+1))
                    return true;
        }
        board[row][col]= t;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int i,j,k,l;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(check(board,i,j,word,0))
                    return 1;
            }
        }
        return 0;
    }
};