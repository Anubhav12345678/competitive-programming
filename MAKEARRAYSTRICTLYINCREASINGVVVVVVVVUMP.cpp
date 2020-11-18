class Solution {
public:
    int solve(map<pair<int,int>,int> &m,int prev,int i,vector<int> &a1,vector<int> &a2)
    {
        if(i==a1.size()) return 0;
        if(m.find({i,prev})!=m.end()) return m[{i,prev}];
        int ans=INT_MAX/2;
        int f = upper_bound(a2.begin(),a2.end(),prev)-a2.begin();
        if(a1[i]>prev) ans = min(ans,solve(m,a1[i],i+1,a1,a2));
        if(f<a2.size()) ans = min(ans,1+solve(m,a2[f],i+1,a1,a2));
        return m[{i,prev}]  = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int> m;
        int ans = solve(m,INT_MIN,0,arr1,arr2);
        return (ans>=INT_MAX/4)?-1:ans;
    }
};
/*
Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.

 

Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].


*/