#include<bits/stdc++.h>
using namespace std;
 
#define getchar_unlocked getchar
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
#define fill(a,x) memset(a,x,sizeof(a))
#define all(x) x.begin(), x.end()
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define RIT(x) for (typeof(x.rbegin()) rit=x.rbegin(); rit!=x.rend(); rit++)
#define until(cond) while(!(cond))
 
#define ll long long int
#define mb make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define db double;
#define ldb long double;
#define pcc pair <char, char> ;
#define pic pair <int, char> ;
#define pil pair <int, ll> ;
#define pli pair <ll, int> ;
#define pdd pair<double,double>
#define vsort(v)   sort(v.begin(),v.end())
 
//#define tr(it,x) for(auto it=x.begin(); it!=x.end(); it++)
 
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define reppi(i,a,b,c) for(int i=a;i<=b;i+=c)
#define ref(i,n) for(int i=n;i>0;i--)
#define reff(i,a,b) for(int i=a;i>=b;i--)
#define fornm(n,m) for(int i =0; i<n; i ++) for(int j =0; j <m; j++)
#define fornmo(n,m,o) for(int i =0; i<n; i ++) for(int j =0; j <m; j++) for(int k =0; k <o; k++)
 
 
#define sc(x) scanf("%d",&x)
#define scc(x1,x2) scanf("%d%d",&x1,&x2)
#define sccc(x1,x2,x3) scanf("%d%d%d",&x1,&x2,&x3)
#define scl(x) scanf("%lld",&x)
#define sccl(x1,x2) scanf("%lld%lld",&x1,&x2)
#define scccl(x1,x2,x3) scanf("%lld%lld%lld",&x1,&x2,&x3)
#define pr(x) printf("%d\n",x)
#define prl(x) printf("%lld\n",x)
#define prrl(x1,x2) printf("%lld %lld\n",x1,x2)
 
 
#define no 31623
#define M 1000000007
#define MAX 10005
#define PI 3.1415926535897932384626433832795028841
//#define bitc(n) __builtin_popcount(n)
const int INF = 2034567891;
const ll INF64 = 1234567890123456789ll;
const ll N =5000005;
const ll MN = 100010;
 
#define DEBUG
#ifdef DEBUG
    #define dbg(var) cerr << "-> " << #var << " = " << (var) << "\n";
    #define dbgarr(arr,n) \
        { \
            cerr << "-> " << #arr << " = "; \
            rep(_i,n) cerr << arr[_i] << " "; \
            cerr << "\n"; \
        }
     #define dbgvec(v,n) \
        { \
            cerr << "-> " << #v << " = "; \
            rep(_i,n) cerr << v[_i] << " "; \
            cerr << "\n"; \
        }   
    #define dbgmat(mat,m,n) \
        { \
            cerr << "-> " << #mat << " =" << "\n"; \
            rep(_i,m) { \
                cerr << "-> "; \
                rep(_j,n) cerr << mat[_i][_j] << " "; \
                cerr << "\n"; \
            } \
        }
    #define dbgv(v) \
        { \
            cerr << "-> " << #v << " = "; \
            ITP(v)  \
            cerr << "\n"; \
        }
#else
    #define dbg(var)
    #define dbgarr(arr,n)
    #define dbgmat(mat,m,n)
    #define dbgv(v)
#endif
 
/*---------------------------------------------------------------------------*/
 
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
#define checkbit(n,b) ( (n >> b) & 1) //checking bth bit is set or not starting from behind and ex. if b=2 ,n=12 1100 answer is 1. 
#define bit(x,i)          (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)         ((x)&((x)^((x)-1))) //returning pow(2,lowestsetbit in x)
#define highbit(x)         (1 << ( int) log2(x) ) //returning nearest(just equal or just smaller power of 2)
#define countleadzero(x)  __builtin_ctz(x) //in its binary representation ex. when x=8 answer is 3
//#define countsetbits(x)   ____builtin_popcount(x) //count no of setbits
inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return x > 0; }
 
inline string readln() { string _s; getline(cin,_s); return _s; }
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(int a, int b) { return (a * (b / gcd(a, b))); }
ll max(ll a,ll b,ll c){return max(a,max(b,c));}
template <class T>string NTS ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
 string rev(string s)
 {
 	reverse(s.begin(),s.end());
 	return s;
 }
 
ll power(ll x,ll y)
{
    ll ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}
// upR KA SB FALTU H 
inline int read()
{
	int ret = 0,temp=1;
	int c = getchar_unlocked();
	while(c<'0' || c>'9'){
		c = getchar_unlocked();
	}
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
int main()
{
	ll n;
    string s,s1;
    s1="hello";
    int pos=0,flag=0;
    cin>>s;
    n=s.size();
    rep(i,n)
    {
    	if(s[i]==s1[pos])pos++;
    	if(pos==5) 
    	{ 
		  cout<<"YES"; 
		  return 0;
		}
	}
	cout<<"NO";
}