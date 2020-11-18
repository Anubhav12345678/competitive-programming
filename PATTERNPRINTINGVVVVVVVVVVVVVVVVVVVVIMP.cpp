#include<bits/stdc++.h>
using namespace std ;
/*

Notice the following pattern

15 19 22 24 25
10 14 18 21 23
 6  9 13 17 20
 3  5  8 12 16
 1  2  4  7 11
Numbers increase in the direction of the diagonal from bottom to top.



*/
# define vi vector < int >
# define vvi vector < vector < int > >

int n , m ;

void print ( vvi &v ) /// To Print the pattern finally !
{
    for ( int i=0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < m ; j ++ )
        {
            cout << v[i][j] << " " ;
        }

        cout << "\n" ;
    }
}

void solve ( )
{
    cin >> n >> m ;
    vvi v ( n , vi ( m ) ) ;

    int cnt = 1 ;

    int row = n - 1 ;
    for ( int col = 0 ; col < m ; col ++ )
    {
        for ( int j = 0 ; row - j > -1 && col - j > -1 ; j ++ )
            v[row - j][col - j] = cnt ++ ;
    }

    int col = m - 1 ;
    for ( int row = n - 2 ; row > -1 ; row -- )
    {
        for ( int j = 0 ; row - j > -1 && col - j > -1 ; j ++ )
            v[row - j][col - j] = cnt ++ ;
    }

    print ( v ) ;
}

int main()
{
    int t = 1;
    cin >> t ;

    while ( t -- )
        solve ( ) ;

    return 0 ;
}