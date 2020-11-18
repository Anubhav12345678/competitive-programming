//meeeeeeeeeeeeeee another
// lc
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int i,j,k,l,n=mat.size();
        if(n==0) return 0;
        int m = mat[0].size();
        if(m==0) return 0;
        vector<vector<int> > v(n+1,vector<int>(m+1,0));
        int len=1,res=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                v[i][j] = mat[i-1][j-1]+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
                if(i>=len&&j>=len&&(v[i][j]-v[i-len][j]-v[i][j-len]+v[i-len][j-len])<=threshold)
                    res=len++;
            }
        }
        return res;
    }
};














class Solution {
public:
    int a[305][305];
    long long int s[305][305];
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m= mat.size();
        int n = mat[0].size();
        int i,j,k,l;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                a[i][j] = mat[i-1][j-1];
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
                cout<<"s["<<i<<"]["<<j<<"] = "<<s[i][j];
            }
        }
        int ans = 0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=i&&k<=j;k++)
                    if(s[i][j]-s[i-k][j]-s[i][j-k]+s[i-k][j-k]<=threshold)
                        ans  =max(ans,k);
            }
        }
        return ans;
        // int n = mat.size();
        // int m = mat[0].size();
        // memset(s, 0, sizeof s);
        // for (int i = 1; i <= n; ++i)
        //     for (int j = 1; j <= m; ++j) {
        //         a[i][j] = mat[i - 1][j - 1];
        //         s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        //     }
        // int ans = 0;
        // for (int i = 1; i <= n; ++i)
        //     for (int j = 1; j <= m; ++j) {
        //         for (int k = 1; k <= i && k <= j; ++k) 
        //             if (s[i][j] - s[i - k][j] - s[i][j - k] + s[i - k][j - k] <= threshold)
        //                 ans = max(ans, k);
        //     }
        // return ans;
    }
};