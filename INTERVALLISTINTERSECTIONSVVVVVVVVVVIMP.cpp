class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i,j,k,l,n=A.size();
        int m = B.size();
        vector<vector<int>> res;
        i=0;
        j=0;
        while(i<n&&j<m)
        {
            if(A[i][1]<B[j][0]) i++;
            else if(B[j][1]<A[i][0]) j++;
            else if(A[i][1]<=B[j][1])
            {
                vector<int> tmp;
                tmp.push_back(max(A[i][0],B[j][0]));
                tmp.push_back(A[i][1]);
                res.push_back(tmp);
                i++;
            }
            else
            {
                vector<int> tmp;
                tmp.push_back(max(A[i][0],B[j][0]));
                tmp.push_back(B[j][1]);
                res.push_back(tmp);
                j++;
            }
        }
        return res;
        
    }
};  