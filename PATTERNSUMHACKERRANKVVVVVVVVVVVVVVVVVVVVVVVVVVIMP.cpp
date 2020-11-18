#include<bits/stdc++.h>
using namespace std ;
/*
Consider the following pattern extending infinitely.

1
2 3
4 5 6
7 8 9 10
.
.
...( extending infinitely ).
Given q queries ; in each query ; you will be given some  ; find the sum of elements in the  row of the triangle.




*/
# define ll long long
# define line cout << "\n" ;

# define fast ios_base :: sync_with_stdio ( false ) ; cin.tie ( 0 ) ; cout.tie ( 0 ) ;

const ll mod = 1e9 + 7 ;

ll mod_pow ( ll a , ll b )
{
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return (a%mod) ;
    if ( b == 2 ) return (((a%mod) * (a%mod))%mod) ;

    return ((mod_pow ( mod_pow ( a , b/2 ) , 2 ) * mod_pow ( a , b%2 )) % mod) ;
}

ll mod_inv ( ll n )
{
    ll ans = mod_pow ( n , mod - 2 ) ;
    return ans ;
}

void solve ()
{
    ll n ;
    cin >> n ;

    ll ans = n * n ;
    ans %= mod ;

    ans *= n ;
    ans %= mod ;

    ans += n ;
    ans %= mod ;

    ans *= mod_inv ( 2 ) ;
    ans %= mod ;

    cout << ans ; line ;
}

int main()
{fast

    int t = 1;
    cin >> t ;

    while ( t -- )
        solve ( ) ;

    return 0 ;
}