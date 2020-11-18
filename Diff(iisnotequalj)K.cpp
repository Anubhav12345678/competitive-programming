int Solution::diffPossible(const vector<int> &A, int B) {
    int n = A.size();
    if(n==0)
    return 0;
    // if(B==0&&n>1)
    // return 1;
    // if(B==0)
    // return 0;
    int i,j,k;
    // n = A.size();
    set<int> s;
    // cout<<k<<endl;
    for(i=0;i<n;i++)
    {
        if(((s.find((B+A[i]))!=s.end())||(s.find((A[i]-B))!=s.end())))
        {
            // cout<<"A["<<i<<"] = "<<A[i]<<" k+A["<<i<<"] = "<<k+A[i]<<endl;
        return 1;
        }
        s.insert(A[i]);
    }
    return 0;
}
