static bool comp(vector<int> &a,vector<int> &b)
{
    if(a[0]!=b[0]) return a[0]<b[0];
    else
    return a[1]>b[1];
}
int solve(vector<vector<int>>& mat) {
    int i,j,k,l,n=mat.size();
    if(n<=1) return 1;
    sort(mat.begin(),mat.end(),comp);
    vector<int> hts;
    for(auto v:mat)
    hts.push_back(v[1]);
    vector<int> lis;
    for(auto x:hts)
    {
        auto lower = lower_bound(lis.begin(),lis.end(),x);
        if(lower==lis.end())
        lis.push_back(x);
        else
        *lower = x;
    }
    return lis.size();
}
/*
You are given a two-dimensional list of integers boxes. Each list contains two integers [width, height] which represent the width and height of a box. Given that you can put a box in another box if both of its width and height are smaller than the other box, return the maximum number of boxes you can fit into a box.

Constraints

The number of lists in boxes is at most 100,000.
Example 1
Input

matrix = [
    [10, 10],
    [9, 9],
    [5, 5],
    [4, 9]
]
Output

3



*/