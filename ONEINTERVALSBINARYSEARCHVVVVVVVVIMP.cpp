#include "solution.hpp"
using namespace std;

static bool comp(vector<int> &a,vector<int> &b){
    return a[0]<b[0];
}
class Solution {
    public:
    int solve(vector<vector<int>>& in) {
        // Write your code here
        int i,j,k,l,n=in.size();
        if(n<2) return 0;
        stack<vector<int>> st;
        sort(in.begin(),in.end(),comp);
        st.push(in[0]);
        for(i=0;i<n;i++){
            vector<int> t = st.top();
            if(t[1]<in[i][0])
            st.push(in[i]);
            else if(in[i][1]>t[1])
            {
                st.pop();
                t[1] = in[i][1];
                st.push(t);
            }
        }
        vector<vector<int>> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        if(res.size()==1) return 0;
        reverse(res.begin(),res.end());
        return res.back()[0]-res.front()[1];
    }
};
/*
You are given a two-dimensional list of integers intervals where each list represents an inclusive [start, end] interval. For an interval [a, b] (where a < b), its 'size' is defined as b - a.

You must add one interval to the given list such that, after merging all the intervals, you get exactly one range left.

Return the minimum possible size of the added interval.


*/