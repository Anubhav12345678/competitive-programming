/*

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have direct prerequisites, for example, to take course 0 you have 
first to take course 1, which is expressed as a pair: [1,0]

Given the total number of courses n, a list of direct prerequisite pairs and a list of queries pairs.

You should answer for each queries[i] whether the course queries[i][0] is a prerequisite 
of the course queries[i][1] or not.

Return a list of boolean, the answers to the given queries.

Please note that if course a is a prerequisite of course b and course b is a
 prerequisite of course c, then, course a is a prerequisite of course c.

 

Example 1:


Input: n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: course 0 is not a prerequisite of course 1 but the opposite is true.



*/



class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int i,j,k,l;
        
        int inf=100007;
       vector<vector<int>> dp(n,vector<int>(n,0));
        for(auto it:prerequisites)
        {
            dp[it[0]][it[1]]=1;
        }
        for(i=0;i<n;i++) dp[i][i]=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dp[j][i])
                for(k=0;k<n;k++)
                    if(dp[i][k])
                    dp[j][k] = 1;
            }
        }
        vector<bool> res(queries.size());
        k=0;
        for(auto it:queries)
        {
            res[k++] = (dp[it[0]][it[1]]==1);
        }
        return res;
    }
};