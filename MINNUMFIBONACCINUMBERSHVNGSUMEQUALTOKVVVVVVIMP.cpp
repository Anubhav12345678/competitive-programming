#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
long long int s;
vector<long long int> v;
void fill()
{
    long long int a=1LL,b=1LL;
    v.pb(a);
    v.pb(b);
    long long int c = a+b;
    while(c<=s)
    {
        v.push_back(c);
        a=b;
        b=c;
        c=a+b;
    }
}
int Solution::fibsum(int A) {
    s = (long long int)A;
    v.clear();
    fill();
    long long cpy=s;
    int n = v.size();
    int i,j,k,l;
    i=n-1;
    // cout<<"i = "<<i<<"v["<<i<<"] = "<<v[i]<<endl;
    int ans=0;
    while(A>0)
    {
        // cout<<"i = "<<i<<"v["<<i<<"] = "<<v[i]<<" A = "<<A<<endl;
        while(v[i]>A)
        i--;
        // cout<<"i = "<<i<<"v["<<i<<"] = "<<v[i]<<" A = "<<A<<endl;
        // cout<<"ok\n";
        A=A-v[i];
        // cout<<"i = "<<i<<"v["<<i<<"] = "<<v[i]<<" A = "<<A<<endl;
        ans++;
    }
    return ans;
}
