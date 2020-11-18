
/*

You are Dastan, the great Prince of Persia!

Under the tunnels of Alamut, you have discovered a path ― a sequence of N tiles (numbered 1 through N) ahead of you.
 You are currently on tile 1. There is a signboard beside you, which says thus:

Stepping on tile i (for each valid i) activates a switch described by a binary string Si with length N. When you 
fell through the tunnels onto tile 1, switch S1 got activated.
For each valid i, when the switch Si gets activated, then for each j (1≤j≤N), if the j-th character of Si is '0',
 tile j becomes unsafe to step on; otherwise (if the j-th character is '1'), tile j becomes safe to step on.
Step on an unsafe tile and you shall testify the fate of all men ― death!
You shall find that which you seek on reaching tile N. This tile must also be safe when you step on it.
Being a trained warrior, you are able to make jumps with length up to K tiles, in both directions. In other words, 
if you are currently at a tile i, you may jump to a tile j if j is a valid tile and |i−j|≤K.

You want to reach tile N as quickly as possible ― you want to minimise the number of jumps you need to make.
 Find this minimum number of jumps.



*/



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e3+5, inf=2e9;

int d[sz];
char s[sz];
vector <int> g[sz];

void bfs(int n)
{
    d[0]=0;
    for(int i=1; i<n; i++) d[i]=inf;

    queue <int> q;
    q.push(0);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int v : g[u]) {
            if(d[v]==inf) {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        int n,k;
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++) g[i].clear();
        for(int i=0; i<n; i++) {
            scanf("%s", s);
            for(int j=0; j<n; j++) {
                if(s[j]=='1' && abs(i-j)<=k && i-j) {
                    g[i].push_back(j);
                }
            }
        }

        bfs(n);

        if(d[n-1]==inf) puts("-1");
        else printf("%d\n", d[n-1]);
    }
}
