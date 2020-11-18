void solve(vector<int> &v)
{
    int i,j,k,l,n=v.size();
    vector<int> cnt(n+1,0);
    for(i=0;i<n;i++)
    cnt[v[i]]++;
    vector<int> res(n);
    for(i=1;i<=n;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        res[cnt[v[i]]-1]=v[i];
        cnt[v[i]]--;
    }
    
    for(i=0;i<n;i++)
    v[i]=res[i];
}
int solve2(vector<vector<int>> &v)
{
    int i,j,k,l,n=v.size();
    int m = v[0].size();
    // int hist[n][m];
    vector<vector<int> > hist(n,vector<int>(m,0));
    for(i=0;i<m;i++)
    {
        hist[0][i]=v[0][i];
        for(j=1;j<n;j++)
        if(v[j][i]) hist[j][i] = hist[j-1][i]+1;
        else hist[j][i]=0;
    }
    
    for(i=0;i<n;i++)
    {
        int cnt[n+1]={0};
        for(j=0;j<m;j++)
        cnt[hist[i][j]]++;
        int colno=0;
        for(k=n;k>=0;k--)
        {
            while(cnt[k]>0)
            {
             hist[i][colno++]=k;
             cnt[k]--;
            }
        }
    }
    // for(i=0;i<n;i++)
    // solve(hist[i]);
    
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<m;j++)
    //     cout<<hist[i][j]<<" ";
    //     cout<<endl;
    // }
    int ans=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        ans = max(ans,(j+1)*hist[i][j]);
    }
    return ans;
}
int Solution::solve(vector<vector<int> > &A) {
    return solve2(A);
}
