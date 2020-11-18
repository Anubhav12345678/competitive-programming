
/*
There are N students in a class. Some of them are friends, while some are not. 
Their friendship is transitive in nature. For example, if A is a direct friend
 of B, and B is a direct friend of C, then A is an indirect friend of C. And we
  defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class.
 If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
  And you have to output the total number of friend circles among all the students.



*/


//UNION FIND
class Solution {
public:
    vector<int> par;
    int find(int x)
    {
        if(par[x]==x) return x;
        else
            return find(par[x]);
    }
    int findCircleNum(vector<vector<int>>& M) {
        int i,j,k,l;
        int n = M.size();
        par.resize(n,0);
        // map<int,int> mp;
        int cnt=n;
        for(i=0;i<n;i++)
            par[i]=i;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    int x = find(i);
                    int y = find(j);
                    if(x!=y)
                    {
                        par[x]=y;
                        cnt--;
                    }
                }
            }
        }
        return cnt;
    }
};






//dfs
class Solution {
public:
    bool vis[201];
    void dfs(vector<vector<int>> &v,int i,int n)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&v[i][j]==1)
            {
                vis[j]=1;
                dfs(v,j,n);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& M) {
        int i,j,k,l,n=M.size();
        if(n==0) return 0;
        int ans=0;
        memset(vis,false,sizeof(vis));
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(M,i,n);
                ans++;
            }
        }
        return ans;
    }
};