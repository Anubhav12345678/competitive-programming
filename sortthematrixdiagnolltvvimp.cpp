class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        int i,j,k,l;
        map<int,vector<int>> mp;
        map<int,int> mp2;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                mp[i-j].push_back(mat[i][j]);
            mp2[i-j]=0;
        }
        vector<vector<int>> res(n,vector<int>(m));
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            sort(it->second.begin(),it->second.end());
            mp[it->first] = it->second;
        }
        for(i=0;i<n;i++)
        {
            vector<int> tmp;
            for(j=0;j<m;j++)
            {
                res[i][j] = mp[i-j][mp2[i-j]];
                    mp2[i-j]++;
            }
        }
        return res;
        
        
    }
};