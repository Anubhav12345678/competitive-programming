/*
Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix.
In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.


*/



int maxof(int a,int b,int c,int d,int e)
{
    return max(max(a,max(b,c)),max(d,e));
}
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int i,j,k,l,n=B.size();
    int m = B[0].size();
    int maxdis = A;
    vector<vector<int>> curdis = B;
    vector<vector<int>> nextdis= curdis;
    for(int dis=0;dis<maxdis;dis++)
    {
        for(i=0;i<n;i++)
         for(j=0;j<m;j++)
         {
             int cur = curdis[i][j];
             int right = (j==m-1)?-1:curdis[i][j+1];
             int left = (j==0)?-1:curdis[i][j-1];
             int up = (i==0)?-1:curdis[i-1][j];
             int down = (i==n-1)?-1:curdis[i+1][j];
             nextdis[i][j] = maxof(cur,left,right,up,down);
         }
         
         curdis = nextdis;
    }
    return curdis;
}
