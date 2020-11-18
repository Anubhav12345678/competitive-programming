void Solution::setZeroes(vector<vector<int> > &A) {
    int i,j,k,n,m,p,q,x=0;
    n = A.size();
    m = A[0].size();
    set<int> row;
    set<int> col;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(A[i][j]==0)
            {
               row.insert(i);
               col.insert(j);
            }
        }
    }
    if(row.size()!=0)
    for(auto it = row.begin();it!=row.end();++it)
    {
        for(j=0;j<m;j++)
        {
            A[*it][j] = 0;
        }
    }
    for(auto it = col.begin();it!=col.end();++it)
    {
        for(i=0;i<n;i++)
        {
            A[i][*it] = 0;
        }
    }
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
