class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int i,j,l,n=mat.size();
        vector<int> v;
        v.push_back(0);
        for(auto it1:mat)
        {
            vector<int> w;
            for(auto it2:it1)
            {
                for(auto it3:v) w.push_back(it3+it2);
            }
            sort(w.begin(),w.end());
            if(w.size()>k) w.resize(k);// imp ssare pichle v k sath sum le lenge uske baad jo phle k me aa gya usko rkhenge vvvvimp
            v=w;
        }
        return v.back();
    }
};