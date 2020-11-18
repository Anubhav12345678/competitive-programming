/*

You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colours: Red, Yellow or Green while making sure that no two adjacent cells have the same colour (i.e no two cells that share vertical or horizontal sides have the same colour).

You are given n the number of rows of the grid.

Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

*/






class Solution {
public:
    int mod = 1e9 + 7;
    int numOfWays(int n) {
        vector<long long int> v2(n,0); vector<long long int> v1(n,0);
        v2[0] = 6; v1[0] = 6;
        for(long long int i = 1; i<n;i++)
        {
            v1[i] = ((2*v2[i-1])%mod + (v1[i-1] * 3)%mod )%mod;
            v2[i] = ((2*v2[i-1])%mod + (v1[i-1] * 2)%mod )%mod;
            
        }
        return (int)((v2[n-1]%mod + v1[n-1]%mod)%mod);
    }
};