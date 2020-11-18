#include<bits/stdc++.h>
using namespace std ;

# define pll pair < ll , ll >
# define vpll vector < pll >

# define ll long long
# define C continue ;

# define pb push_back
# define line cout << "\n" ;
# define fast ios_base :: sync_with_stdio ( false ) ; cin.tie ( 0 ) ; cout.tie ( 0 ) ;

# define F first
# define S second

const ll mod = 1e9 + 7 ;

ll mod_pow ( ll a , ll b )
{
    if ( b == 0 )
        return 1 ;

    if ( b == 1 )
        return (a%mod) ;

    if ( b == 2 )
        return ((a%mod) * (a%mod))%mod ;

    return ((mod_pow ( mod_pow ( a , (b>>1) ) , 2 ) * mod_pow ( a , (b&1) )) % mod) ;
}

ll mod_inv ( ll n )
{
    ll ans = mod_pow ( n , mod - 2 ) ;
    return ans ;
}

const int N = 1e5 + 10 ;

vector < pair < int , int > > g[N] ;
int weight[N] , str[N] ;

int summer , winter ;
pair < int , int > ed[N] ;

int n , m ;

void read ()
{
    cin >> n >> m ;

    for ( int i=0 ; i < m ; i ++ )
    {
        int a , b , w , s ;
        cin >> a >> b >> w >> s ;

        g[a].pb ( { i , b } ) ;
        g[b].pb ( { i , a } ) ;

        weight[i] = w ;
        str[i] = s ;

        ed[i] = { a , b } ;
    }

    cin >> summer >> winter ;
}

ll dis1[N] , disn[N] ;
bool vis1[N] , visn[N] ;

void dijk ( ll *dis , int node , bool *vis )
{
    priority_queue < pll , vpll , greater < pll > > q ;

    dis[node] = 0 ;
    q.push ( { 0 , node } ) ;

    while ( q.empty() == false )
    {
        auto temp = q.top() ;
        q.pop() ;

        ll w = temp.F ;
        int node = temp.S ;

        if ( vis[node] )
            C ;

        vis[node] = 1 ;

        for ( auto &temp : g[node] )
        {
            int indx = temp.F ;
            int i = temp.S ;

            ll relax_dis = w + weight[indx] ;

            if ( relax_dis < dis[i] )
            {
                dis[i] = relax_dis ;
                q.push ( { relax_dis , i } ) ;
            }
        }
    }
}

void solve()
{
    read () ;

    memset ( dis1 , 63 , sizeof ( dis1 ) ) ;
    memset ( disn , 63 , sizeof ( disn ) ) ;

    const ll inf = dis1[0] ;

    dijk ( dis1 , summer , vis1 ) ;
    dijk ( disn , winter , visn ) ;

    assert ( dis1[winter] == disn[summer] ) ;
    const ll sp = dis1[winter] ;

    if ( sp == inf )
    {
        cout << "Stay safe, stay indoors" ; line ;
        return ;
    }

    int total = 0 ;
    int max_str_count = 0 ;
    int max_str = 0 ;

    for ( int i = 0 ; i < m ; i ++ )
    {
        int a = ed[i].F ;
        int b = ed[i].S ;

        ll dis = min ( dis1[a] + weight[i] + disn[b] , dis1[b] + weight[i] + disn[a] ) ;

        if ( dis == sp )
        {
            total ++ ;

            if ( str[i] > max_str )
                max_str = str[i] , max_str_count = 1 ;

            else if ( str[i] == max_str )
                max_str_count ++ ;
        }
    }

    ll nr = max_str_count ;
    ll dr = total ;

    /// probability is (nr/dr)

    nr *= mod_inv ( dr ) ;
    nr %= mod ;

    cout << max_str << " " << nr ; line ;
}

int main()
{fast
    solve () ;
    return 0 ;
}
/*

The King of redSword-land is a fat person. And like all fat people ; he is a bit lazy.

He has two capital cities in his country. One of the capital cities is situated in a hilly region ; and hence is cold
 and pleasant even in the summers ; hence ; the king rules from this capital during the summer season. This city is 
 called Summer Capital, and currently the king is here in this city ( Right now, its summer after all, insn't it)

But this capital city becomes very cold during the winters. And the king faces problems ruling in the winter season 
from here. Hence ; he has another city ; from where he rules during the winter. This city is called the winter capital.

When the season changes ; the king has to travel from one capital city to another. The cities of the country
 redSword-land can be modelled using a graph.

Since the king is lazy ; he always moves on one of the Shortest Paths connecting the two capitals.

Length of the path between two cities is the sum of the lengths of the roads in that path. And the shortest path
 between two cities is the path having the least Length.

But the king does not move through the roads of the country that often ( for security reasons. ) But when during 
the change of the seasons he does so ; his enemies eye him.

The enemies cannot attack the king whenever he is in some city ( Yes he is safe there ). But they can attack him,
 when he moves from one city to another. The roads of redSword-Land also have a security number assigned to them,
  in such a fashion, that the more safe road is assigned a higher number as compared to the less safe road.

Naturally ; the king is "most safe" when he is on a road with max security number ( out of the roads where he might
 be at any time of his journey ; even though, that road might not be the safest road of the country. )

So ; out of all the roads where the king can be, you need to determine the probability of the king being "most safe".

This probability will be defined as the ratio of the number of distinct roads where the king will be "most safe"
 in his journey, to the number of distinct roads where the king can be during his entire journey.

And ; you should also determine the security number of the safest road in the king's path.



*/