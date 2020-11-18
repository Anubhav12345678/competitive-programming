// map<int,pair<>>
/*
There are A coins (Assume A is even) in a line.

Two players take turns to take a coin from one of the ends of the line until there are no more coins left.

The player with the larger amount of money wins.

Assume that you go first.

Return the maximum amount of money you can win.



*/
map<string,int> mp;
int solve(vector<int> &v,int st,int en)
{
    string key = to_string(st)+"|"+to_string(en);
    if(mp.find(key)!=mp.end())
     return mp[key];
    if(st==en)
    return v[st];
    if(st+1==en)
    return max(v[st],v[en]);
    int x = v[st]+min(solve(v,st+2,en),solve(v,st+1,en-1));
    int y=  v[en]+min(solve(v,st+1,en-1),solve(v,st,en-2));
    return mp[key] = max(x,y);
}

int Solution::maxcoin(vector<int> &A) {
    int i,j,k,l,n=A.size();
    if(n==1)
    return A[0];
    mp.clear();
    return solve(A,0,n-1);
}
