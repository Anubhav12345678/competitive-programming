class Solution {
public:
    bool binsearch(vector<vector<int>> &v,int x,int i,int jl,int jh)
    {
        while(jl<=jh)
        {
            int jm = (jl+jh)/2;
            if(v[i][jm]==x)
                return true;
            else if(v[i][jm]>x)
                jh=jm-1;
            else
                jl = jm+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0)
            return 0;
        int n = matrix[0].size();
        int i,j,k,l,p,q;
        if(m==0||n==0)
            return 0;
        i=0,j=n-1;
        if(m==1)
            return binsearch(matrix,target,0,0,n-1);
        int il = 0,ih = m-1,jm = n/2;
        while((il+1)<ih)
        {
            int im = (il+ih)/2;
            if(matrix[im][jm]==target)
                return true;
            else if(matrix[im][jm]>target)
                ih = im;
            else
                il=im;
        }
        if(il>=0&&il<m)
        {
        if(matrix[il][jm]==target)
            return true;
        if(matrix[il+1][jm]==target)
            return true;
        if(jm>=1&&target<=matrix[il][jm-1])
            return binsearch(matrix,target,il,0,jm-1);
        else if((jm+1)<n&&target>=matrix[il][jm+1]&&target<=matrix[il][n-1])
            return binsearch(matrix,target,il,jm+1,n-1);
        else if(jm>0&&target<=matrix[il+1][jm-1])
            return binsearch(matrix,target,il+1,0,jm-1);
        else if(jm>0)
            return binsearch(matrix,target,il+1,jm+1,n-1);
        }
        return false;
    }
};