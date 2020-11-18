#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*

Given an array with non negative numbers, divide the array into two parts such that the average of both the parts is equal.
Return both parts (If exist).
If there is no solution. return an empty list.

Example:


Input:
[1 7 15 29 11 9]

Output:
[9 15] [1 7 11 29]

The average of part is (15+9)/2 = 12,
average of second part elements is (1 + 7 + 11 + 29) / 4 = 12





*/
vector<vector<vector<bool>>> dp;
vector<int> res;
int totsz;
vector<int> org;
bool possible(int index, int sum, int sz) {
            if (sz == 0) return (sum == 0);
            if (index >= totsz) return false;

            if (dp[index][sum][sz] == false) return false;

            if (sum >= org[index]) {
                res.push_back(org[index]);
                if (possible(index + 1, sum - org[index], sz - 1)) return true;
                res.pop_back();
            }
            
            if (possible(index + 1, sum, sz)) return true;

            return dp[index][sum][sz] = false;
        }
vector<vector<int> > Solution::avgset(vector<int> &A) {
    dp.clear();
    res.clear();
    totsz=0;
    org.clear();
    sort(A.begin(),A.end());
    org=A;
    totsz=A.size();
    int totsum = accumulate(A.begin(),A.end(),0);
    dp.resize(org.size(), vector<vector<bool> > (totsum + 1, vector<bool> (totsz, true)));
    for (int i = 1; i < totsz; i++) {
                // Sum_of_Set1 has to be an integer
                if ((totsum * i) % totsz != 0) continue;
                int Sum_of_Set1 = (totsum * i) / totsz;
                if (possible(0, Sum_of_Set1, i)) {

                    // Ok. Lets find out the elements in Vec, not in res, and return the result.
                    int ptr1 = 0, ptr2 = 0;
                    vector<int> res1 = res;
                    vector<int> res2;
                    while (ptr1 < A.size() || ptr2 < res.size()) {
                        if (ptr2 < res.size() && res[ptr2] == A[ptr1]) {
                            ptr1++;
                            ptr2++;
                            continue;
                        }
                        res2.push_back(A[ptr1]);
                        ptr1++;
                    }

                    vector<vector<int> > ans;
                    sort(res1.begin(),res1.end());
                    sort(res2.begin(),res2.end());
                    ans.push_back(res1);
                    ans.push_back(res2);
                    return ans;
                }
            }
            // Not possible.
            vector<vector<int> > ans;
            return ans;

    
}
