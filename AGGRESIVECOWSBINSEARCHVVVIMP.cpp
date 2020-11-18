bool noofcows(vector<int> &v,int x,int B)
{
    int i,j,k,n,l,r,m,cnt=1;
    n = v.size();
    sort(v.begin(),v.end());
    int st=0;
    for(i=1;i<n;i++)
    {
        if(v[i]-v[st]>=x)
        {
            cnt++;
            if(cnt>=B)
            return true;
            st=i;
        }
    }
    return false;
}
int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int i,j,k,n;
    int lo = 0;
    n = A.size();
    int high = A[n-1]-A[0],mid,ans=INT_MIN;
    while(lo<=high)
    {
        // cout<<"netered loop\n";
        mid = lo+(high-lo)/2;
        if(noofcows(A,mid,B))
        {
            ans = max(ans,mid);
            lo = mid+1;
        }
        else
        high = mid-1;
    }
    return ans;
    
}
