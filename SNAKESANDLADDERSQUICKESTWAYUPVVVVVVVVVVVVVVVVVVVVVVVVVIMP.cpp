#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 104
#include<vector>
#define se second
/*
Markov takes out his Snakes and Ladders game, stares at the board and wonders: "If I can always roll the die to whatever number I want, what would be the least number of rolls to reach the destination?"

Rules The game is played with a cubic die of 6 faces numbered 1 to 6.

Starting from square , land on square  with the exact roll of the die. If moving the number rolled would place the player beyond square , no move is made.

If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.



*/
// meeee
#define ff first
#define se second
int solve(vector<vector<int>> &lad,vector<vector<int>> &sna){
    map<int,int> mp1,mp2;
    for(auto v:lad){
        mp1[v[0]] = v[1];
    }
    
    for(auto v:sna){
        mp2[v[0]] = v[1];
    }
    
    queue<pair<int,int>> q;
    q.push({1,0});
    vector<bool> vis(101,false);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int x = cur.ff;
        int dis = cur.se;
        if(mp1.find(x)!=mp1.end()) x = mp1[x];
        if(mp2.find(x)!=mp2.end()) x=  mp2[x];
        if(x==100) return dis;
        vis[x]=true;
        for(int i=1;i<=6;i++){
            if((x+i)<=100&&!vis[x+i])
            {
                q.push({x+i,dis+1});
            }
        }
    }
    
    return -1;
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    
    return solve(A,B);
}



#define ff first
int main(){
    ll i,j,k,l,n,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> graph(N,0);
        vector<bool> mark(N,0);
        for(i=0;i<n;i++)
        {
            ll a,b;
            cin>>a>>b;
            graph[a]=b;
        }
        cin>>m;
        for(i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            graph[a]=b;
        }
        queue<pair<ll,ll>> q;
        q.push({1,0});
        mark[1]=true;
        ll ans= INT_MAX;
        while(!q.empty())
        {
            pair<ll,ll> p = q.front();
            q.pop();
            if(p.ff==100)
            {
                ans = p.se;
                break;
            }
            
            for(i=1;i<=6;i++)
            {
                ll x = p.ff+i;
                if(x>100) continue;
                if(mark[x]==0)
                {
                mark[x]=1;
                if(graph[x]==0)
                    q.push({x,p.se+1});
                else{
                    x = graph[x];
                    mark[x]=true;
                    q.push({x,p.se+1});
                }
                }
            }
        }
        if(ans==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    
}








