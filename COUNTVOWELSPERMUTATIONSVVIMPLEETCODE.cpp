class Solution {
    typedef long long ll;
    ll mod = 1000000007;
public:
    int countVowelPermutation(int n) {
        if(n==1)
            return 5;
        map<char,ll> _dp,dp;
        _dp['a']=_dp['e']=_dp['i'] = _dp['o']=_dp['u']=1;
        for(int l=2;l<=n;l++)
        {
            dp['a'] = (_dp['e'])%mod;
            dp['e'] = (_dp['a']+_dp['i']);
            dp['i'] = (_dp['a']+_dp['e']+_dp['o']+_dp['u'])%mod;
            dp['o'] = (_dp['i']+_dp['u'])%mod;
            dp['u'] = (_dp['a'])%mod;
                _dp=dp;
        }
        int ans=0;
        for(auto x : dp) ans = (ans+x.second)%mod;
        return ans;
    }
};