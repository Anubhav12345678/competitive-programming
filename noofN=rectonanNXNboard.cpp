#include <iostream>
using namespace std;
#define ll long long
ll solve(ll n)
{
    return (((n*(n+1)*n*(n+1))/4)-((n*(n+1)*(2*n+1))/6));
}
int main() {
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<solve(n)<<endl;
    }
	//code
	return 0;
}