/*
Given N x M character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long
// bool vis[1005][1005];
bool isval(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
void bfs(vector<string> &A,int r,int c)
{
    int n = A.size();
    int m = A[0].size();
    if(!isval(r,c,n,m))
    return;
    if(A[r][c]!='X')
    return;
    // int n = A.size();
    // int m = A[0].size();
    // if(!isval(r,c,n,m))
    // return;
    // vis[r][c]=true;
    A[r][c]='O';
    bfs(A,r+1,c);
    bfs(A,r-1,c);
    bfs(A,r,c-1);
    bfs(A,r,c+1);
}
int Solution::black(vector<string> &A) {
    int i,j,k,l,n=A.size();
    int m = A[0].size();
    int ans=0;
    // memset(vis,false,sizeof(vis));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(A[i][j]=='X')
            {
                bfs(A,i,j);
                // cout<<"ok\n";
                ans++;
            }
        }
    }
    return ans;
}
