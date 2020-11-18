#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
 
bool cmp(int n, int m) { 
    return n % 10 > m % 10; 
}
 
int main() {
    int n, k, a[100000];
    int ans = 0, distFromHundred = 0;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n, cmp);
    
    for (int i = 0; i < n; i++) {
        int dist = 10 - a[i] % 10;
    
        if (k >= dist) {
            a[i] += dist;
            k -= dist;
        }
        
        ans += (a[i] / 10);
        distFromHundred += (100 - a[i]);
    }
    
    ans += (min(distFromHundred, k) / 10);
    
    cout << ans << endl;
 
    return 0;
}