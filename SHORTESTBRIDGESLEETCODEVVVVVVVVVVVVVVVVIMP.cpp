#define ff first
#define se second
/*
In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not 
connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

Example 1:

Input: A = [[0,1],[1,0]]
Output: 1
Example 2:

Input: A = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2



*/
class Solution {
public:
    int dis(pair<int,int> a,pair<int,int> b)
    {
        return  abs(a.ff-b.ff)+abs(a.se-b.se)-1;
    }
    int solve(set<pair<int,int>> st1,set<pair<int,int>> st2)
    {
        int i,j,k,l,ans=INT_MAX;
        for(auto it1:st1)
        {
            for(auto it2:st2)
            {
                ans = min(ans,dis(it1,it2));
            }
        }
        return ans;
    }
    void floodfill(set<pair<int,int>> &st,int r,int c,vector<vector<int>>& A)
    {
        if(r<0||r>=A.size()||c<0||c>=A[0].size()||A[r][c]!=1)
            return;
        A[r][c]=0;
        st.insert({r,c});
        floodfill(st,r+1,c,A);
        floodfill(st,r-1,c,A);
        floodfill(st,r,c+1,A);
        floodfill(st,r,c-1,A);
    }
    int shortestBridge(vector<vector<int>>& A) {
        int i,j,k,l,n=A.size();
        if(n==0)
            return 0;
        int m=A[0].size();
        if(m==0) return 0;
        set<pair<int,int>> st1,st2;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(A[i][j]==1)
                {
                    if(st1.empty())
                      floodfill(st1,i,j,A);
                    else if(st2.empty()&&st1.find({i,j})==st1.end())
                        floodfill(st2,i,j,A);
                }
            }
        }
        return solve(st1,st2);
    }
};