class Solution {
public:
    /*

    The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.



    */
     //meeeeeeeeeeeeeeeeeeeeeeeee
    class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();   // no of rows
        if(r == 0) return 0; // if empty then return 0
        int c = dungeon[0].size();  // no of columns
        // DP with r+1 x c+1 dimension and all values initialized to INT_MAX
        vector<vector<int>>dp(r+1,vector<int>(c+1,INT_MAX));
        // Initializing the cell to the bottom and right of princess' cell with value 1.
        dp[r-1][c] = 1;
        dp[r][c-1] = 1;
        // Iterating over dp excluding the additional row and column we added.
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                int val = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];  // value is minimum health to land on next - health need to stay
                dp[i][j] = max(1,val); // minimum value required is 1. maximum is the +ve value we calculated.
            }
        }
        
        return dp[0][0];  // The first element contains the minimum health needed to rescue the princess.
    }
};



















    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int i,j,k,l,n=dungeon.size();
        if(n==0) return 0;
        int m = dungeon[0].size();
        if(m==0) return 0;
        cout<<n<<" "<<m<<endl;
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[n-1][m-1] = max(1-dungeon[n-1][m-1],1);
        // init last row
        cout<<"1ok\n";
        for(i=n-2;i>=0;i--)
            dp[i][m-1] = max(dp[i+1][m-1]-dungeon[i][m-1],1);
        for(i=m-2;i>=0;i--)
        {
            dp[n-1][i] = max(dp[n-1][i+1]-dungeon[n-1][i],1);
        }
        cout<<"2ok\n";
        cout<<"3ok\n";
        for(i=n-2;i>=0;i--)
            for(j=m-2;j>=0;j--)
            {
                int down = max(dp[i+1][j]-dungeon[i][j],1);
                int right = max(dp[i][j+1]-dungeon[i][j],1);
                dp[i][j] = min(down,right);
            }
        return dp[0][0];
    }
};