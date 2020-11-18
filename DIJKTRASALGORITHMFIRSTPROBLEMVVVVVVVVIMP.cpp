// Author: r3gz3n
// 3b 13 12 9 56 4e
// 6 56 a a 5f f
// 6 56 47 18 56 d
// 13 46 14 1f 13 27
// 52 52 a 5a 47 1
// 1d 13 b 1b 49 17
// Template Begin
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define le length()
#define sz size()
#define all(x) (x).begin(),(x).end()
#define alli(a, n, k) (a+k),(a+n+k)
#define REP(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)
#define REPI(i, a, b, k) for(__typeof(a) i = a;i > b;i -= k)
#define REPITER(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define eps 1e-6
#define pi 3.141592653589793
using namespace std;
template<class T> inline T gcd(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<class T> inline T mod(T x) { if(x < 0) return -x; else return x; }
typedef vector<int> VII;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<int, PII > PPII;
typedef vector< PII > VPII;
typedef vector< PPII > VPPI;
const int MOD = 1e9 + 7;
const int INF = 1e9;
// Template End
const int MAX = 1e3 + 5;
string s[MAX];
bool vis[MAX][MAX];
int ans[MAX][MAX];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};
void bfs(int sx, int sy, int n, int m) {
    queue <PII> q;
    PII p;
    int x, y;
    q.push({sx, sy});
    ans[sx][sy] = 0;
    vis[sx][sy] = true;
    while(!q.empty()) {
        p = q.front();
        q.pop();
        REP(i, 0, 4, 1) {
            x = dr[i] + p.fi;
            y = dc[i] + p.se;
            if (x >= 1 and x <= n and y >= 1 and y <= m and s[x][y] == 'O' and vis[x][y] == false) {
                ans[x][y] = ans[p.fi][p.se] + 1;
                vis[x][y] = true;
                q.push({x, y});
            }
        }
    }
}
int main(int argc, char* argv[]) {
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);
    int n, m, q, sx, sy, dx, dy;
    cin >> n >> m >> q;
    assert(1 <= n and n <= 1000);
    assert(1 <= m and m <= 1000);
    assert(1 <= q and q <= 1000000);
    REP(i, 1, n+1, 1) {
        cin >> s[i];
        s[i] = '0' + s[i];
        REP(j, 1, m+1, 1) {
            assert(s[i][j] == 'O' or s[i][j] == '*');
            ans[i][j] = -1;
        }
    }
    cin >> sx >> sy;
    assert(1 <= sx and sx <= 1000);
    assert(1 <= sy and sy <= 1000);
    bfs(sx, sy, n, m);
    while(q--) {
        cin >> dx >> dy;
        assert(1 <= dx and dx <= 1000);
        assert(1 <= dy and dy <= 1000);
        cout << ans[dx][dy] << endl;
    }
    return 0;
}