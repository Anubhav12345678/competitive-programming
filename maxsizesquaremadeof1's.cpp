// C++ code for Maximum size square  
// sub-matrix with all 1s  
#include <bits/stdc++.h> 
// #define bool int  
// #define R 6  
// #define C 5  
using namespace std; 
  
  
int printMaxSubSquare(int M[][55],int n,int m)  
{  
    int i,j;  
    int S[55][55];  
    int mini = -1;
    int max_of_s, max_i, max_j;  
      
    /* Set first column of S[][]*/
    for(i = 0; i < n; i++) 
    {
        S[i][0] = M[i][0];  
        mini = max(mini,S[i][0]);
    } 
    /* Set first row of S[][]*/
    for(j = 0; j < m; j++)  
    {
        S[0][j] = M[0][j];
        mini = max(mini,S[0][j]);
    }
    /* Construct other entries of S[][]*/
    for(i = 1; i < n; i++)  
    {  
        for(j = 1; j < m; j++)  
        {  
            if(M[i][j] == 1)  
                S[i][j] = min(S[i][j-1],min( S[i-1][j],  
                                S[i-1][j-1])) + 1;  
            else
                S[i][j] = 0;  
            mini = max(mini,S[i][j]);    
        }  
    }
    return mini;
}
int main()
{
    int t,n,m,c[55][55],i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin>>c[i][j];
        cout<<printMaxSubSquare(c,n,m)<<endl;    
    }
    
    
    
    
    
}
// me leetcode
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0)
            return 0;
        int m= matrix[0].size();
        if(m==0)
            return 0;
        int i,j,k,l,ans=-1;
        int s[n][m];
        for(i=0;i<n;i++)
        {
            s[i][0]=matrix[i][0]-'0';
            ans = max(ans,s[i][0]);
        }
        for(i=0;i<m;i++)
        {
            s[0][i]=matrix[0][i]-'0';
            ans = max(ans,s[0][i]);
        }
        // for(i=0;i<n;i++)
        //     s[i][0]=matrix[i][0]-'0';
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(matrix[i][j]=='1')
                s[i][j]=min(s[i][j-1],min(s[i-1][j],s[i-1][j-1]))+1;
                else
                    s[i][j]=0;
                ans = max(ans,s[i][j]);
            }
        }
        return ans*ans;
    }
};