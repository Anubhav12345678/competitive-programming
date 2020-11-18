#include <bits/stdc++.h>
 
using namespace std;



/*


The Cartesian coordinate system is set in the sky. There you can see n stars, the i-th
 has coordinates (xi, yi), a maximum brightness c, equal for all stars, and an initial brightness si (0 ≤ si ≤ c).

Over time the stars twinkle. At moment 0 the i-th star has brightness si. Let at moment 
t some star has brightness x. Then at moment (t + 1) this star will have brightness x + 1, if x + 1 ≤ c, and 0, otherwise.

You want to look at the sky q times. In the i-th time you will look at the moment ti and 
you will see a rectangle with sides parallel to the coordinate axes, the lower left corner has coordinates (x1i, y1i) and the upper right — (x2i, y2i). For each view, you want to know the total brightness of the stars lying in the viewed rectangle.

A star lies in a rectangle if it lies on its border or lies strictly inside it.



*/
 
const int N = (int) 1e5 + 123;
const int C = 101;
const int P = 11;
 
int n, q, c;
int cnt[P][C][C];
 
int main() {
    scanf("%d%d%d", &n, &q, &c);
    for (int i = 0; i < n; i++) {
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        cnt[s][x][y]++;
    }
    
    for (int p = 0; p <= c; p++) {
        for (int i = 1; i < C; i++) {
            for (int j = 1; j < C; j++) {
                cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int ans = 0;
        for (int p = 0; p <= c; p++) {
            int brightness = (p + t) % (c + 1);
            int amount = cnt[p][x2][y2] - cnt[p][x1 - 1][y2] - cnt[p][x2][y1 - 1] + cnt[p][x1 - 1][y1 - 1];
            ans += brightness * amount;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}