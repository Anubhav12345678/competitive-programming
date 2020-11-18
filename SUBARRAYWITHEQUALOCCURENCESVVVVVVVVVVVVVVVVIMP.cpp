int sol(vector<int> &v,int k)
{
    int i,j,l,n=v.size();
    int ans=0,sum=0;
    map<int,int> mp;
    for(i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum==k)
        ans++;
        if(mp.find(sum-k)!=mp.end())
        ans+=mp[sum-k];
        mp[sum]++;
    }
    return ans;
}
int Solution::solve(vector<int> &A, int B, int C) {
    int i,j,k,l,n=A.size();
    for(i=0;i<n;i++)
    {
        if(A[i]==B)
        A[i]=1;
        else if(A[i]==C)
        A[i]=-1;
        else
        A[i]=0;
    }
    return sol(A,0);
    
}
/*
Given a stream of numbers A. On arrival of each number, you need to increase its first occurence by 1 and include this in the stream.

Return the final stream of numbers.
*/