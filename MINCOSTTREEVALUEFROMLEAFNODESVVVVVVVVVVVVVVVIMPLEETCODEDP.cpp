class Solution {
public:
    int memo[41][41];
    int maxi[41][41];
    int dp(int st,int en){
        if(st==en) return 0;
        if(memo[st][en]!=-1) return memo[st][en];
        
        int ans=INT_MAX;
        for(int i=st;i<en;i++){
            ans = min(ans,maxi[st][i]*maxi[i+1][en]+dp(st,i)+dp(i+1,en));
        }
        
        return memo[st][en] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int i,j,k,l,n=arr.size();
        memset(memo,-1,sizeof(memo));
        memset(maxi,-1,sizeof(maxi));
        for(i=0;i<n;i++){
            maxi[i][i] = arr[i];
            for(j=i+1;j<n;j++)
                maxi[i][j] = max(maxi[i][j-1],arr[j]);
        }
        
        return dp(0,n-1);
        
    }
};
/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  
(Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and
 right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. 
 It is guaranteed this sum fits into a 32-bit integer.

 

Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4


*/