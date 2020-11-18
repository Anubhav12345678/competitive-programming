 void permute(vector<int> &num, int start, vector<vector<int> > &result) {
        if (start == num.size() - 1) {
            result.push_back(num);
            return;
        } 
        for (int i = start; i < num.size(); i++) {
            swap(num[start], num[i]);
            permute(num, start + 1, result);
            swap(num[start], num[i]);
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() == 0)
            return result;
        sort(num.begin(), num.end());
        permute(num, 0, result);
        return result;
    }
    // LeetCode
    class Solution {
public:
    void permute(vector<vector<int>> &res,int st,vector<int> &v)
    {
        if(st==v.size()-1)
        {
            res.push_back(v);
            return;
        }
        for(int i=st;i<v.size();i++)
        {
            swap(v[st],v[i]);
            permute(res,st+1,v);
            swap(v[st],v[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        sort(nums.begin(),nums.end());
        permute(res,0,nums);
        sort(res.begin(),res.end());
        return res;
    }
};