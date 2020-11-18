#include <bits/stdc++.h>
#define ll long long
#define V vector
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];
int ans[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int cnt1 = 0;
    int cnt2 = 0;
   
    for (int i = 0;i<n;i++){
        if(a[i]%2==0){
            if(i%2)
                cnt1++;
                else
                    cnt2++;
        }
       
    }
    for(int i=0;i<n;i++){
        if(i%2) cout<<cnt2<<" ";
        else cout<<cnt1<<" ";
    }
        return 0;
}