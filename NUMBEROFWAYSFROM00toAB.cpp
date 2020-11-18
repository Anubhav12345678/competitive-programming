long long int solve(int a,int b)
{
    long long int table[a][b];
    memset(table,0,sizeof(table));
    int i,j,k;
    for(i=0;i<a;i++)
    table[i][0] = 1;
    for(i=0;i<b;i++)
    table[0][i]=1;
    for(i=1;i<a;i++)
    {
        for(j=1;j<b;j++)
        {
            table[i][j] = table[i-1][j]+table[i][j-1];
        }
    }
    return table[a-1][b-1];
    
}
int Solution::uniquePaths(int A, int B) {
    return solve(A,B);
}
