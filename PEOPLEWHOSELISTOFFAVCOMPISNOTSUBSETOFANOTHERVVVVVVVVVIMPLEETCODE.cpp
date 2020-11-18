class Solution {
public:
    /*
   Given the array favoriteCompanies where favoriteCompanies[i] is the list of favorites companies for the
    ith person (indexed from 0).

Return the indices of people whose list of favorite companies is not a subset of any other list of favorites
 companies. You must return the indices in increasing order.



    */
    bool issub(vector<int> &a,vector<int> &b)
    {
        int i,j,k,l,n=a.size();
        int m = b.size();
        if(n<=m)
        {
            i=0,j=0;
            for(i=0;i<m;i++)
            {
                if(j<n&&a[j]==b[i])
                    j++;
            }
            return j==n;
        }
        
        return false;
    }
    vector<int> peopleIndexes(vector<vector<string>>& fc) {
        int i,j,k,l,n=fc.size();
        map<string,int> mp;
        vector<vector<int>> res(n);
        k=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<fc[i].size();j++)
            {
                if(mp.find(fc[i][j])==mp.end())
                    mp[fc[i][j]]=k++;
                res[i].push_back(mp[fc[i][j]]);
            }
            sort(res[i].begin(),res[i].end());
        }
        
        vector<int> ans;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j&&issub(res[i],res[j]))
                    break;
            }
            if(j==n)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};