#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int mxn = 8e6+10;
bitset<mxn>bs;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n;
    bool is_z=0;
    bs[0]=1;
    for(int i = 0,x; i < n; i++){
        cin >> x;
        if(x ==0)is_z=1;
        bs |= bs << x;
    }
    
    int q; cin >> q;
    while(q--)
    {
        int y; cin >> y;
         if(y == 0 && !is_z){
            cout<<0;
            continue;
        }
        cout<< (bs[y] ? "1":"0");
        
    }
    return 0;
}