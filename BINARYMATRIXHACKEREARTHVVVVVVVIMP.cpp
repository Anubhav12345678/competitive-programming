#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<set>
/*
N numbers were converted into their respective Binary form of M length and arranged in an NxM matrix.

Your task is to find the index of row (1 based indexing) which contains the binary number with maximum value. If multiple rows
 have maximum value then print the row with minimum index.

Input:

The first line contains two space separated integers N and M, denoting number of rows and number of columns in matrix respectively.

Each of the next N lines contains a number in binary form.

*/
int main(){

  ll i,j,k,l,n,m;
  char a[1010][1010];
  cin>>n>>m;
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  unordered_set<ll> v,v2;
  for(i=1;i<=n;i++){
    v.insert(i);
  }

  for(j=1;j<=m;j++){
    for(auto ind:v)
    if(a[ind][j]=='1')
    v2.insert(ind);
    if(!v2.empty())
    v=v2;
    v2.clear();
  }

  ll mini=INT_MAX;
  for(auto ind:v)
  mini = min(mini,ind);
  cout<<mini;
  




















  return 0;
}