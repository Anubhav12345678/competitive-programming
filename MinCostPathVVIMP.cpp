#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int t;
cin>>t;
int n,m;
int a1,b1;
int k,l;
pair<int,int>p;
while(t--)
{
cin>>n;
int a[n][n];
int dis[n][n];
for(int i=0;i<n;i++)
  {
  for(int j=0;j<n;j++)
        {
       cin>>a[i][j];
       dis[i][j]=INT_MAX;
       }
      }
  int x[4]={-1,1,0,0};
int y[4]={0,0,1,-1};
dis[0][0]=a[0][0];
queue<pair<int,int> >q;
q.push(make_pair(0,0));
while( !q.empty())
  {
  p=q.front();
  a1=p.first;
  b1=p.second;
  q.pop();
  for(int i=0;i<4;i++)
   {
    k=a1+x[i];
    l=b1+y[i];
   if( k>=0 && k<n && l>=0 && l<n &&  dis[k][l]>(dis[a1][b1]+a[k][l]) )
  {
   dis[k][l]=dis[a1][b1]+a[k][l];
    q.push(make_pair(k,l));    
    }   
}
  }
 cout<<dis[n-1][n-1]<<endl;

}
return 0;
}