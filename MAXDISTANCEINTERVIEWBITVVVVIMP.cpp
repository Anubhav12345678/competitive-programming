
/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.




*/





int Solution::maximumGap(const vector<int> &A) {
    int i,j,k,l,n=A.size();
    i=0,j=n-1;
    int best=0;
    vector<pair<int,int>> v(n);
    for(i=0;i<n;i++)
    v[i] = {A[i],i};
    sort(v.begin(),v.end());
    int ans=0,rmax=v[n-1].second;
    for(i=n-2;i>=0;i--)
    {
        ans = max(ans,rmax-v[i].second);
        rmax = max(rmax,v[i].second);
    }
    return ans;
}
