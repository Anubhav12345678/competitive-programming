#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int ret = 0;
        vector<int> c(n), d(m);
        for (auto v : indices) c[v[0]]++, d[v[1]]++;
        REP(i, n) REP(j, m) ret += (c[i] + d[j]) % 2;
        return ret;
    }
};