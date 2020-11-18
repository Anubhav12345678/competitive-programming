#include<bits/stdc++.h>
using namespace std;
int n, k, q, a[105];
void    in()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}
void    xuly()
{
    int low = 0, high = 1e9;
    for (int i = 1; i <= n; i++)
    {
    	// cout<<"a["<<i<<"] = "<<a[i]<<endl;
    	// cout<<"low = "<<low<<" high = "<<high<<endl;
    	// cout<<"k = "<<k<<endl;
        int x = (a[i] - k), y = a[i] + k;
        // cout<<"x = "<<x<<" y = "<<y<<endl;
        if (x > high || y < low)
        {
        	// cout<<"entered if\n";
            cout << -1 << '\n';
            return;
        }
        // cout<<"low = "<<low<<" high = "<<high<<endl;
        low = max (low, x);
        // cout<<"low = "<<low<<" high = "<<high<<endl;
        high = min (high, y);
        // cout<<"low = "<<low<<" high = "<<high<<endl;
    }
    // cout<<"out of loop\n";
    cout << high << '\n';
}
int main ()
{
    cin >> q;
    while (q--)
    {
        in();
        xuly();
    }
}