vector<vector<int> > Solution::prettyPrint(int A) {
    // int i,j,k,l,n = 2*A-1,tmp = A;
    vector<vector<int>> v(2*A-1);
    for(int i=0;i<2*A-1;i++)
    v[i] = vector<int>(2*A-1,0);
    // int x=1,y=0;
    int m=A+A-1;
int n=A+A-1;
int t=0,l=0,r=n-1,b=m-1,dir=0,x=0,y=0;
while(t<=b && l<=r){
    if(dir==0){
        for(int i=l;i<=r;i++) v[t][i]=A-t;
        t++;
    }
    else if(dir==1){
        for(int i=t;i<=b;i++) v[i][r]=A-x;
        r--;
        x++;
    }
    else if(dir==2){
        for(int i=r;i>=l;i--) v[b][i]=A-y;
        b--;
        y++;
    }
    else if(dir==3){
        for(int i=b;i>=t;i--) v[i][l]=A-l;
        l++;
    }
    dir=(dir+1)%4;
    
}
return v;
    // for(i=0;i<n;i++)
    // res[0][i] = A;
    // for(i=1;i<n;i++)
    // res[i][n-1] = A;
    

}
// in my format
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
void solve(int A)
{
    // vector<vector<int>> v;
    int m = 2*A-1;
    int n = 2*A-1;
    int i,j,k;
    vector<vector<int>> v(n);
    for(int i=0;i<2*A-1;i++)
    v[i] = vector<int>(2*A-1,0);
    int l=0,t=0,r=n-1,b=m-1,dir = 0,x=0,y=0,s=0,p=0;
    /*
    l - starting col
    k - ending kol
    t- starting row
    b = ending row
    */
    while(l<=r&&t<=b)
    {
        if(dir==0)
        {
        for(i=l;i<=r;i++)
        v[t][i] = A-x;
        x++;
        t++;
        }
        else if(dir==1)
        {
        for(i=t;i<=b;i++)
        v[i][r] = A-y;
        y++;
        r--;
        }
        else if(dir==2)
        {
            for(i=r;i>=l;i--)
            v[b][i] = A-s;
            s++;
            b--;
        }
        else 
        {
           for(i=b;i>=t;i--)
           v[i][l] = A-p;
           p++;
           l++;
        }
        dir = (dir+1)%4;
        
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    solve(n);
    // your code goes here
    return 0;
}