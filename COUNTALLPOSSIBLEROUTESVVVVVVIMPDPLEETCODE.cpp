
const int mod = 1e9+7;
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int i,j,k,l,n=locations.size();
        vector<vector<int>> dp(fuel+1,vector<int>(n,0));
        dp[fuel][start]=1;// no of ways to go with given fuel f ti city start
        for(int f=fuel;f>=0;f--){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    int d=  abs(locations[i]-locations[j]);
                    if(i!=j&&f>=d){
                        dp[f-d][j] = (dp[f-d][j]+dp[f][i])%mod;
                    }
                }
            }
        }
        int tot=0;
        for(i=0;i<=fuel;i++){
            tot = (tot+dp[i][finish])%mod;
        }
        return tot%mod;
    }
};
/*
You are given an array of distinct positive integers locations where locations[i] represents the position of city i.
 You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount
  of fuel you have, respectively.

At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to
 city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice
  that |x| denotes the absolute value of x.

Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once
 (including start and finish).

Return the count of all possible routes from start to finish.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
Output: 4
Explanation: The following are all possible routes, each uses 5 units of fuel:
1 -> 3
1 -> 2 -> 3
1 -> 4 -> 3
1 -> 4 -> 2 -> 3


*/