#include <iostream>
#include <cstring>
#define rep(i,a,n) for(long long i=a;i<n;i++)
#define rep1(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
long check(long long a[],long long b[],long long n){
    long maxx = 0;
    rep(i,1,n){
        long low=0,high=i,mid=-1;
        while(low<=high){
            mid = (low+high)/2;
            if(a[mid] <= b[i])
            {
                if(i-mid > maxx)
                maxx = i-mid;
                high = mid - 1;
            }
            else
            low = mid + 1;
        }
    }
    return maxx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    long long n;
    cin >> tc;
    rep(j,0,tc){
        cin >> n;
    long long a[n],b[n];
    rep(i,0,n)
    {
        cin >> a[i];
    }
    rep(i,0,n)
    {
        cin >> b[i];
    }
    long y = check(a,b,n);
        cout << y << endl;
    }
	return 0;
}