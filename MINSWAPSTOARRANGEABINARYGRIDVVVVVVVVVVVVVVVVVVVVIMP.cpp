class Solution {
public:
    /*
Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

    */
    int zeroesatend(vector<int> &a){
        int ans=0;
        int i=a.size()-1;
        while(i>=0&&a[i]==0){
            ans++;
            i--;
        }
        return ans;
    }
    
    vector<int> gridtovec(vector<vector<int>> &g){
        vector<int> a(g.size());
        int i=0;
        for(auto v:g){
            a[i++] = zeroesatend(v);
        }
        return a;
    }
    int solve(vector<int> &a){
        // tom find the min number off swaps
        int i,j,k,l,n=a.size();
        int ans=0;
        for(i=0;i<n;i++){
            if(a[i]<(n-i-1)){
                j=i;
                while(j<n&&a[j]<(n-i-1))
                    j++;
                if(j==n) return -1;
                while(j>i){
                    swap(a[j],a[j-1]);
                    ans++;
                    j--;
                }
            }
        }
        return ans;
    }
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> v = gridtovec(grid);
        return solve(v);
    }
};