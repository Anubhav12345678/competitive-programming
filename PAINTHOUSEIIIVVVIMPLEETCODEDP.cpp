class Solution {
public:
    int dp[101][101][21];
    int solve(vector<int>  &h,vector<vector<int>> &col,int i,int lst,int tar){
        if(i>=h.size()||tar<0) {
            return (tar==0)? tar:10000001;
        }
        
        if(h[i])
            return solve(h,col,i+1,h[i], tar-(lst!=h[i]));
        if(dp[i][tar][lst]!=-1) return dp[i][tar][lst];
        int res=10000001;
        for(int j=1;j<=col[i].size();j++){
          res = min(res,col[i][j-1]+solve(h,col,i+1,j, tar-(lst!=j)));
        }
        return dp[i][tar][lst]=res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        auto res = solve(houses,cost,0,0,target);
        if(res!=10000001) return res;
        else
            return -1;
    }
};
/*

User Accepted:861
User Tried:1482
Total Accepted:935
Total Submissions:2751
Difficulty:Hard
There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that has been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color. (For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods  [{1}, {2,2}, {3,3}, {2}, {1,1}]).

Given an array houses, an m * n matrix cost and an integer target where:

houses[i]: is the color of the house i, 0 if the house is not painted yet.
cost[i][j]: is the cost of paint the house i with the color j+1.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods, if not possible return -1.

 

Example 1:

Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.
*/