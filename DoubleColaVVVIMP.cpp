#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<functional>
#include<iterator>
#include<locale>
#include<memory>
#include<stdexcept>
#include<utility>
#include<string>
#include<fstream>
#include<ios>
#include<iostream>
#include<iosfwd>
#include<iomanip>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
#include<complex>
#include<numeric>
#include<valarray>
#include<exception>
#include<limits>
#include<new>
#include<typeinfo>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define sqr(x) (x*x)
#define cub(x) sqr(x)*(x)
#define all(x) x.begin(),x.end()
#define fp pop_front
#define bp pop_back
#define pf push_front
#define pb push_back
#define mp make_pair
#define sz size()
#define se second
#define fi first
#define endl "\n"
#define _ std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
using namespace std;
typedef long long ll;
typedef double dd;
typedef string st;
typedef char ch;
typedef unsigned long long ull;
typedef bool bl;
typedef long double ld;
typedef int I;
const ld pi = 3.14159265358979323846;
const ll mod = 1e9 ;
const ll N = 5e5 + 500;
const char *BIGBANG [5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
 
int n;
 
int main ()
{
    scanf ("%d", &n); n--;
    int count = 5;
 
    while (n >= count)
    {
        n -= count;
        count *= 2;
    }
 
    puts (BIGBANG [n / (count / 5)]);
    return 0;
}