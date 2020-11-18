class Solution {
public:
    void solve(vector<vector<int>> &res,vector<int> &v,int sum,int k,int st)
    {
        if(sum<0)
            return;
        if(sum==0&&v.size()==k)
        {
            res.push_back(v);
            return;
        }
        for(int i =st;i<=9;i++)
        {
            v.push_back(i);
            solve(res,v,sum-i,k,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> v;
        solve(res,v,n,k,1);
        return res;
    }
};