#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<queue>
/*
Dr. Patel has N stacks of plates. Each stack contains K plates. Each plate has a positive beauty value, describing
 how beautiful it looks.

Dr. Patel would like to take exactly P plates to use for dinner tonight. If he would like to take a plate in a stack,
 he must also take all of the plates above it in that stack as well.

Help Dr. Patel pick the P plates that would maximize the total sum of beauty values.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line
 containing the three integers N, K and P. Then, N lines follow. The i-th line contains K integers, describing the beauty
  values of each stack of plates from top to bottom.

*/
ll n,k,p;
const ll sz1 = 55;
const ll sz2  = 1505;
ll memo[sz1][sz2];
ll a[sz1][sz2];
ll dp(ll pos,ll left){
    if(left==0) return 0;
    if(left>(n-pos)*k) return -1e9;
    if(memo[pos][left]!=-1) return memo[pos][left];
    ll maxans = dp(pos+1,left); // not taking any plate from this stack
    ll cur=0LL;
    for(ll i=0;i<k&&i<left;i++){
        cur+=a[pos][i];// cur stack me se i+1 plates utha li
        maxans = max(maxans,cur+dp(pos+1,left-i-1));
    }
    
    return memo[pos][left] = maxans;
}
int main(){
    ll i,j,l,t;
    cin>>t;
    // k=t;
    l=t;
    while(t--){
        memset(memo,-1,sizeof(memo));
        
        cin>>n>>k>>p;
        // memo.resize(n,vector<ll>(k+10,-1));
        // a.resize(n,vector<ll>(k));
        
        for(i=0;i<n;i++)
        for(j=0;j<k;j++)
        cin>>a[i][j];
        cout<<"Case #"<<l-t<<": "<<dp(0,p)<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}