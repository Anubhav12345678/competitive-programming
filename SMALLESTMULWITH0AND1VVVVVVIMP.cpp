
/*
You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only.
 Since this multiple could be large, return it in form of a string.




*/


string Solution::multiple(int n) {
    if(n==1)
    return "1";
    queue<int> q;
    vector<int> dig(n),par(n);
    vector<bool> vis(n,0);
    // memset(vis,0,sizeof(vis));
    q.push(1%n);
    dig[1%n]=1;
    vis[1%n]=1;
    par[1%n]=-1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur==0)
        break;
        int mod0 = (cur*10)%n;
        int mod1 = (cur*10+1)%n;
        if(vis[mod0]==0)
        {
            dig[mod0]=0;
            vis[mod0]=1;
            par[mod0]=cur;
            q.push(mod0);
        }
        if(vis[mod1]==0)
        {
            dig[mod1]=1;
            vis[mod1]=1;
            par[mod1]=cur;
            q.push(mod1);
        }
    }
    string s="";
    int i=0;
    while(i!=-1)
    {
        s.push_back(dig[i]+'0');
        i=par[i];
    }
    reverse(s.begin(),s.end());
    return s;
    // q.push();
    
}
