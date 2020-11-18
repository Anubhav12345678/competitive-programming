#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <cassert>
#include<complex>
#include <time.h>
using namespace std;
/*
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.

*/
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef complex<double> base;
const int INF = 1000000000;
const int MAX = 100007;
const int MAXE = 5000;
const int MAXV = 20*20;
const int BASE = 1000000007;
const int MOD = 1000000007;
vector<int> g[MAX];
bool U[MAX];
VI A , B;
int P[MAX];
int Q[MAX];
void dfs(int v)
{
    U[v] = 1;
    A.push_back(P[v]);
    B.push_back(Q[v]);
    FOR(i,0,g[v].size())
    {
        if (!U[g[v][i]])
        {
            dfs(g[v][i]);
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	FOR(tt,0,t)
	{
        int n , m;
        cin >> n >> m;
        FOR(i,0,n)
        {
            U[i] = 0;
            g[i].clear();
        }
        FOR(i,0,n)
        {
            cin >> P[i];
        }
        FOR(i,0,n)
        {
            cin >> Q[i];
        }
        FOR(i,0,m)
        {
            int a , b;
            scanf("%d%d" , &a , &b);
            --a;--b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool ok = 1;
        FOR(i,0,n)
        {
            if (!U[i])
            {
                A.clear();
                B.clear();
                dfs(i);
                sort(ALL(A));
                sort(ALL(B));
                if (A != B) ok = 0;
            }
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
	}
    return 0;
}