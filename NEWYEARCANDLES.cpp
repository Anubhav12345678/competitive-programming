#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b;
    cin>>a>>b;
    ll cura=a,curb=0,res=0;
    while(cura>0)
    {
        res+=cura;
        curb+=cura;
        cura=curb/b;
        curb = curb%b;
    }
    cout<<res<<endl;
}