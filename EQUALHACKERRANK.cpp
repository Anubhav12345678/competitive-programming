#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<limits.h>
using namespace std;
typedef long long lld;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,a[100000],t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<min)min=a[i];
        }
        int ans=INT_MAX,iter=5;
        while(iter--)
        {
        int res=0;
        for(int i=0;i<n;i++)
        {
            int d=a[i];
            while(d-5>=min)
            {
                d-=5;
                res++;
            }
            while(d-2>=min)
            {
                d-=2;
                res++;
            }
            while(d-1>=min)
            {
                d-=1;
                res++;
            }
            //cout<<a[i]<<endl;
        }
        min--;
        if(res<ans)ans=res;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
OUTPUT
min = 2
min = 2
res = 0
min = 2
res = 0
min = 2
eneterd thitd while
res = 1
min = 2
eneterd first while
res = 2
min = 1
min = 1
eneterd thitd while
res = 1
min = 1
eneterd thitd while
res = 2
min = 1
eneterd second while
res = 3
min = 1
eneterd first while
eneterd thitd while
res = 5
min = 0
min = 0
eneterd second while
res = 1
min = 0
eneterd second while
res = 2
min = 0
eneterd second while
eneterd thitd while
res = 4
min = 0
eneterd first while
eneterd second while
res = 6
min = -1
min = -1
eneterd second while
eneterd thitd while
res = 2
min = -1
eneterd second while
eneterd thitd while
res = 4
min = -1
eneterd second while
eneterd second while
res = 6
min = -1
eneterd first while
eneterd second while
eneterd thitd while
res = 9
min = -2
min = -2
eneterd second while
eneterd second while
res = 2
min = -2
eneterd second while
eneterd second while
res = 4
min = -2
eneterd first while
res = 5
min = -2
eneterd first while
eneterd second while
eneterd second while
res = 8
2

*/