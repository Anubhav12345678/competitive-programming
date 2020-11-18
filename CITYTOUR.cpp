#define ll long long
ll ma=1000000007;
ll fact(ll k){
    if(k==0)
    return 1;
    else return ((k*fact(k-1))%ma);
    
}
ll power(ll p,ll t){
    if(t==0)
    return 1;
    ll y=power(p,t/2);
    y=(y*y)%ma;
    if(t%2==1)
    y=(y*p)%ma;
    return y;
    
}


int Solution::solve(int a, vector<int> &b) {
int n=b.size();
sort(b.begin(),b.end());
ll y=a-n;
if(y==0)
return 0;
ll ans=fact(y);
ll q=fact(b[0]-1);
for(int i=0;i<n-1;i++){
    
    ll u=b[i+1]-b[i]-1;
    ans=(ans*power(2,u-1))%ma;
    q=(q*fact(u))%ma;
}
q=(q*fact(a-b[n-1]))%ma;
q=power(q,ma-2);

ans=(ans*q)%ma;
return ans;
  

    
    
}