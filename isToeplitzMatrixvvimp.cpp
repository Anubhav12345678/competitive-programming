
//A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.



class Solution {
public:
    map<int,vector<int>> mp;
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        mp.clear();
        int n = mat.size();
        int m=mat[0].size();
        int i,j,k,l;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                mp[i-j].push_back(mat[i][j]);
        }
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            vector<int> v=  it->second;
            int p = v.size();
            for(i=0;i<p-1;i++)
                if(v[i]!=v[i+1])
                    return 0;
        }
        return 1;
    }
};