class Solution {
public:
    vector<int> poss;
    void solve(string a)
    {
        for(int dig1=0;dig1<10;dig1++)
        {
            for(int dig2=0;dig2<10;dig2++)
            {
                string b=a;
                for(auto &ch:b)
                {
                    if(ch==('0'+dig1))
                        ch='0'+dig2;
                }
                if(b[0]=='0')
                    continue;
                poss.push_back(stoi(b));
            }
        }
    }
    int maxDiff(int num) {
        int i,j,k,l,n;
        solve(to_string(num));
        int ans=0;
        for(auto x:poss)
        {
            for(auto y:poss)
            {
                ans = max(ans,abs(x-y));
            }
        }
        return ans;
    }
};