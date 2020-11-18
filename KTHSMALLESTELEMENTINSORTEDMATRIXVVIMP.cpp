
/*

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.


*/

//pririty_queue
class Solution {
public:
struct compare
{
    bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b)
    {
        return a.first>b.first;
    }
};
    int kthSmallest(vector<vector<int>>& arr, int k) {
        
        int n=arr.size(),m=arr[0].size();
        
        priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, compare > p;
        
        for(int i=0;i<n;i++)
        p.push(make_pair(arr[i][0],make_pair(i,0)));
        
        int x=k,ans;
        while(x--)
        {
            int e=p.top().first;
            int i=p.top().second.first;
            int j=p.top().second.second;
            ans=e;
            p.pop();
            if(j!=m-1)
            p.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
        }
        return ans;
        
    }
};      

class Solution {
public:
    vector<int> merge(vector<int> &a,vector<int> &b)
    {
        int n = a.size();
        int m = b.size();
        int i=0,j=0,k=0,l;
        vector<int> res(n+m);
        while(i<n&&j<m)
        {
            if(a[i]<=b[j])
            {
                res[k++] = a[i++];
            }
            else
                res[k++] = b[j++];
        }
        while(i<n)
            res[k++] = a[i++];
        while(j<m)
            res[k++] = b[j++];
        return res;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        // int m = mat[0].size();
        int i,j=0,l=0,r;
        vector<int> res(mat[0].begin(),mat[0].end());
        for(i=1;i<n;i++)
            res = merge(res,mat[i]);
        return res[k-1];
        
        
    }
};