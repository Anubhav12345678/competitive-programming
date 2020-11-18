class Solution {
public:
    pair<int,int> par[501][501];
    int rank[501][501];
    pair<int,int> find(pair<int,int> a)
    {
        if(par[a.first][a.second]==a)
            return a;
        else
           return par[a.first][a.second] = find(par[a.first][a.second]);
    }
    void merge(pair<int,int> a,pair<int,int> b)
    {
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(rank[a.first][a.second]>rank[b.first][b.second])
        {
            par[b.first][b.second]=a;
            rank[a.first][a.second]++;
        }
        else
        {
            par[a.first][a.second]=b;
            rank[b.first][b.second]++;
        }
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        int i,j,k,l;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                par[i][j]= {i,j};
                rank[i][j]=1;
            }
        }
        for(i=0;i<n;i++)
        {
            map<int,pair<int,int>> mp;
            for(j=0;j<m;j++)
            {
                if(mp.find(mat[i][j])!=mp.end())
                    merge({i,j},mp[mat[i][j]]);
                else
                    mp[mat[i][j]] = {i,j};
            }
        }
        for(j=0;j<m;j++)
        {
            map<int,pair<int,int>> mp;
            for(i=0;i<n;i++)
            {
                if(mp.find(mat[i][j])!=mp.end())
                    merge({i,j},mp[mat[i][j]]);
                else
                    mp[mat[i][j]] = {i,j};
            }
        }
        vector<pair<int,int>> v[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                auto x = find({i,j});
                v[x.first][x.second].push_back({i,j});
            }
        }
        map<int,vector<vector<pair<int,int>>>> mp;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(v[i][j].size()==0) continue;
                mp[mat[i][j]].push_back(v[i][j]);
            }
        }
        vector<int> row(n,0), col(m,0);
        for(auto a:mp)
        {
            auto b = a.second;
            for(auto c:b)
            {
                int x = 0;
                for(auto d:c)
                {
                    x = max(x,max(row[d.first],col[d.second])+1);
                }
                for(auto d:c)
                {
                    ans[d.first][d.second]=x;
                    row[d.first] = max(x,row[d.first]);
                    col[d.second] = max(x,col[d.second]);
                }
            }
        }
        return ans;
    }
};
/*
Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].

The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:

The rank is an integer starting from 1.
If two elements p and q are in the same row or column, then:
If p < q then rank(p) < rank(q)
If p == q then rank(p) == rank(q)
If p > q then rank(p) > rank(q)
The rank should be as small as possible.
It is guaranteed that answer is unique under the given rules.

 

Example 1:


Input: matrix = [[1,2],[3,4]]
Output: [[1,2],[2,3]]
Explanation:
The rank of matrix[0][0] is 1 because it is the smallest integer in its row and column.
The rank of matrix[0][1] is 2 because matrix[0][1] > matrix[0][0] and matrix[0][0] is rank 1.
The rank of matrix[1][0] is 2 because matrix[1][0] > matrix[0][0] and matrix[0][0] is rank 1.
The rank of matrix[1][1] is 3 because matrix[1][1] > matrix[0][1], matrix[1][1] > matrix[1][0], and both matrix[0][1] and matrix[1][0] are rank 2.



*///