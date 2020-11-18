/* You are required to complete this method */
int minSwaps(int A[], int N){
    pair<int,int> p[N];
    int i,j,k,l,csz=0,ans=0;
    bool vis[N];
    memset(vis,false,sizeof(vis));
    for(i=0;i<N;i++)
    {
        p[i].first=A[i];
        p[i].second = i;
    }
    sort(p,p+N);
    for(i=0;i<N;i++)
    {
        if(vis[i]||p[i].second==i)
        continue;
        j=i;
        csz=0;
        while(!vis[j])
        {
            vis[j]=1;
            j=p[j].second;
            csz++;
        }
        ans+=csz-1;
    }
    return ans;
    /*Your code here */
}
