int zerosum(vector<int> &v){
    int i,j,k,l,n=v.size();
    int ans=0,sum=0;
    unordered_map<int,int> mp;
    for(i=0;i<n;i++){
        sum+=v[i];
        if(sum==0) ans++;
        if(mp.find(sum)!=mp.end())
        ans+=mp[sum];
        mp[sum]++;
    }
    return ans;
}
int Solution::solve(vector<vector<int> > &A) {
    if(A.size()==0) return 0;
    int i,j,k,l,n=A.size();
    int m=  A[0].size();
    int ans=0;
    for(int left=0;left<m;left++){
        vector<int> tmp(n,0);
        for(int right=left;right<m;right++){
            for(i=0;i<n;i++)
            tmp[i]+=A[i][right];
            ans+=zerosum(tmp);
        }
    }
    return ans;
}
