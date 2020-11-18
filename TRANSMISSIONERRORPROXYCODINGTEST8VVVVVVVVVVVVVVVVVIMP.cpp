#include<bits/stdc++.h>
using namespace std;
// #define ll long long
//https://www.hackerrank.com/contests/proxy-coding-test-8/challenges/transmission-error/problem

int main() {
    int x,y,dx=0,dy=0,i,j,k,l,m,n;
    string s;
    cin>>x>>y;
    cin>>s;
    n=(int)s.size();
    if(n==0){
        cout<<"NO";
        return 0;
    }
    int cnt=0;
    for(i=0;i<n;i++){
        if(s[i]=='E')
            dx++;
        else if(s[i]=='W')
            dx--;
        else if(s[i]=='N')
            dy++;
        else if(s[i]=='S')
            dy--;
        else if(s[i]=='?')
            cnt++;
    }
    
    int p = abs(x-dx)+abs(y-dy);
    if(p==cnt||(cnt>=p&&(cnt-p)%2==0))
        cout<<"YES";
    else
        cout<<"NO";
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
