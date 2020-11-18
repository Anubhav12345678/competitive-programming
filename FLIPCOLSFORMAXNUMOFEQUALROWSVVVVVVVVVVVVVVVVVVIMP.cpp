class Solution {
public:
    /*
Given a matrix consisting of 0s and 1s, we may choose any number of columns in the matrix and flip every cell in that column.  Flipping a cell changes the value of that cell from 0 to 1 or from 1 to 0.

Return the maximum number of rows that have all values equal after some number of flips.

 

Example 1:

Input: [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.



    */
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        for(auto x:matrix)
        {
            string s="";
            char top = x[0];
            for(int i=0;i<x.size();i++)
            {
                if(x[i]==top)
                    s+='1';
                else
                    s+='0';
            }
            mp[s]++;
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++)
            ans = max(ans,it->second);
        return ans;
    }
};