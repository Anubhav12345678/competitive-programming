void solve2(vector<vector<char>> &v,int r,int c)
{
    if(r<0||r>=v.size()||c<0||c>=v[0].size()||v[r][c]!='O')
    return;
    v[r][c]='-';
    solve2(v, r+1, c); 
	solve2(v, r-1, c); 
	solve2(v, r, c+1); 
	solve2(v, r, c-1); 
}
void floodfill(vector<vector<char>> &v)
{
    int n=v.size();
    int m = v[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='O'&&(i==0||i==n-1||j==0||j==m-1))
            {
                solve2(v,i,j);
            }
        }
    }
}
void Solution::solve(vector<vector<char> > &A) {
    int n=A.size();
    int m = A[0].size();
    floodfill(A);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='O')
            A[i][j]='X';
            if(A[i][j]=='-')
            A[i][j]='O';
        }
    }
    // cout<<"ok"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         if(A[i][j]=='-')
    //         {
    //             cout<<"e"<<endl;
    //           A[i][j]='O';
    //         }
    //     }
    // }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
    