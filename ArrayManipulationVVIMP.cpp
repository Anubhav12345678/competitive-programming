#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int N,K,p,q,sum,i,j,maxi=0,x=0;

    cin>>N>>K;
    long int *a=new long int[N+1]();

    for(i=0;i<K;i++)
    {
        cin>>p>>q>>sum;
        a[p]+=sum;
        if((q+1)<=N) a[q+1]-=sum;
    }

    for(i=2;i<=N;i++)
    {
        a[i]+=a[i-1];
    }
    for(i=1;i<=N;i++)
    maxi = max(a[i],maxi); 

    cout<<maxi;
    return 0;
}