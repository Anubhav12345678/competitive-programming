class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
      string s="123456789";
        int i,j,k,l;
        int num;
        vector<int> res;
        for(i=0;i<9;i++)
        {
            for(j=i+1;j<9;j++)
            {
                string p=s.substr(i,j-i+1);
                num=stoi(p);
                if(num>=low&&num<=high)
                    res.push_back(num);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};