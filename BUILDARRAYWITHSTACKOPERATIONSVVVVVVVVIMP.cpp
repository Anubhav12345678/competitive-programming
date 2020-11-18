class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i,j,k,l,m=target.size();
        int tsz=0;
        vector<string> res;
        int x = target[0]-1;
        while(x--)
        {
            res.push_back("Push");
            res.push_back("Pop");
        }
        res.push_back("Push");
        tsz++;
        int y = target[0]+1;
        i=1;
        while(tsz<m)
        {
            while((target[tsz])-y>0)
            {
                res.push_back("Push");
                res.push_back("Pop");
                y++;
            }
            res.push_back("Push");
            y++;
            tsz++;
        }
        return res;
    }
};