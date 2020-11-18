#define F first
#define S second
#define R cin>>
#define Z class
#define ll long long
#define ln cout<<'\n'
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cerr<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cerr<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cerr<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cerr<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cerr<<' ';cerr<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1e9+7,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<ll,string> P;

class Solution {
public:
  int maxSatisfied(vector<int>& c, vector<int>& g, int X) {
    int ans=0,M=0,sum=0;
    rep(i,c.size()) {
      if(!g[i]) ans+=c[i];
    }
    rep(i,X-1) {
      if(g[i]) sum+=c[i];
    }
    REP(i,X-1,c.size()) {
      if(g[i]) sum+=c[i];
      if(i-X>=0&&g[i-X]) sum-=c[i-X];
      M=max(M,sum);
    }
    return ans+M;
  }
};
